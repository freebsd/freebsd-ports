-- Add FreeBSD TUN interface support to the sing-tun library.
-- FreeBSD uses /dev/tunN character devices.  TUNSIFHEAD is enabled so each
-- packet carries a 4-byte AF-family prefix (PacketOffset=4), matching the
-- Darwin layout.  The interface is auto-created via SIOCIFCREATE2 if it does
-- not already exist.  IPv4/IPv6 addresses are configured via SIOCAIFADDR and
-- SIOCAIFADDR_IN6 ioctls; routes are managed through AF_ROUTE sockets.
--- vendor/github.com/sagernet/sing-tun/tun_freebsd.go.orig	2026-05-04 17:28:35 UTC
+++ vendor/github.com/sagernet/sing-tun/tun_freebsd.go
@@ -0,0 +1,426 @@
+//go:build freebsd
+
+package tun
+
+import (
+"fmt"
+"net"
+"net/netip"
+"os"
+"syscall"
+"unsafe"
+
+"github.com/sagernet/sing/common"
+E "github.com/sagernet/sing/common/exceptions"
+
+"golang.org/x/net/route"
+"golang.org/x/sys/unix"
+)
+
+const PacketOffset = 4
+
+// FreeBSD-specific ioctl constants (computed from /usr/include/net/if_tun.h
+// and /usr/include/netinet6/in6_var.h).
+const (
+_TUNSIFHEAD      = 0x80047460 // _IOW('t', 96, int) — enable multi-AF header mode
+_SIOCAIFADDR_IN6 = 0x8088691b // _IOW('i', 27, struct in6_aliasreq)
+
+_IN6_IFF_NODAD         = 0x0020
+_IN6_IFF_SECURED       = 0x0400
+_ND6_INFINITE_LIFETIME = 0xFFFFFFFF
+)
+
+// ifreqFlags is used with SIOCGIFFLAGS / SIOCSIFFLAGS.
+type ifreqFlags struct {
+Name  [unix.IFNAMSIZ]byte
+Flags int16
+_     [14]byte
+}
+
+// ifreqMTU is used with SIOCSIFMTU.
+type ifreqMTU struct {
+Name [unix.IFNAMSIZ]byte
+MTU  int32
+_    [12]byte
+}
+
+// ifAliasReq is used with SIOCAIFADDR (IPv4).
+type ifAliasReq struct {
+Name    [unix.IFNAMSIZ]byte
+Addr    unix.RawSockaddrInet4
+Dstaddr unix.RawSockaddrInet4
+Mask    unix.RawSockaddrInet4
+}
+
+// addrLifetime6 mirrors struct in6_addrlifetime from netinet6/in6_var.h.
+type addrLifetime6 struct {
+Expire    int64  // time_t ia6t_expire
+Preferred int64  // time_t ia6t_preferred
+Vltime    uint32 // ia6t_vltime
+Pltime    uint32 // ia6t_pltime
+}
+
+// ifAliasReq6 mirrors struct in6_aliasreq from netinet6/in6_var.h.
+// FreeBSD adds ifra_vhid relative to the Darwin version.
+// sizeof = 136 bytes (verified against the C struct).
+type ifAliasReq6 struct {
+Name     [unix.IFNAMSIZ]byte
+Addr     unix.RawSockaddrInet6
+Dstaddr  unix.RawSockaddrInet6
+Mask     unix.RawSockaddrInet6
+Flags    int32
+Lifetime addrLifetime6
+Vhid     int32
+}
+
+// NativeTun implements Tun for FreeBSD using /dev/tunN character devices.
+// TUNSIFHEAD is enabled so each packet carries a 4-byte AF-family prefix
+// (PacketOffset = 4), matching the Darwin layout.
+type NativeTun struct {
+tunFd               int
+tunFile             *os.File
+options             Options
+routeSet            bool
+iovecsOutputDefault []unix.Iovec
+}
+
+func New(options Options) (Tun, error) {
+if options.Name == "" {
+return nil, E.New("tun name is required")
+}
+var tunIndex int
+if _, err := fmt.Sscanf(options.Name, "tun%d", &tunIndex); err != nil {
+return nil, E.New("bad tun name (expected tunN): ", options.Name)
+}
+
+// Create the interface.  If it already exists from a previous run (EEXIST),
+// destroy it first so we start with a clean slate — no stale addresses,
+// routes, or flags.
+if err := useSocket(unix.AF_INET, unix.SOCK_DGRAM, 0, func(fd int) error {
+var ifr ifreqMTU
+copy(ifr.Name[:], options.Name)
+_, _, errno := unix.Syscall(syscall.SYS_IOCTL, uintptr(fd),
+uintptr(unix.SIOCIFCREATE2), uintptr(unsafe.Pointer(&ifr)))
+if errno == unix.EEXIST {
+// Interface exists: destroy it so we can recreate it cleanly.
+if _, _, errno2 := unix.Syscall(syscall.SYS_IOCTL, uintptr(fd),
+uintptr(unix.SIOCIFDESTROY), uintptr(unsafe.Pointer(&ifr))); errno2 != 0 {
+return os.NewSyscallError("SIOCIFDESTROY", errno2)
+}
+if _, _, errno2 := unix.Syscall(syscall.SYS_IOCTL, uintptr(fd),
+uintptr(unix.SIOCIFCREATE2), uintptr(unsafe.Pointer(&ifr))); errno2 != 0 {
+return os.NewSyscallError("SIOCIFCREATE2", errno2)
+}
+} else if errno != 0 {
+return os.NewSyscallError("SIOCIFCREATE2", errno)
+}
+return nil
+}); err != nil {
+return nil, err
+}
+
+devPath := fmt.Sprintf("/dev/%s", options.Name)
+tunFd, err := unix.Open(devPath, unix.O_RDWR, 0)
+if err != nil {
+return nil, os.NewSyscallError("open "+devPath, err)
+}
+
+// Enable multi-AF header mode: each packet gains a 4-byte network-byte-order
+// AF_family prefix.  Without this, the kernel assumes AF_INET for every write
+// and IPv6 packets would be misdelivered.
+one := 1
+if _, _, errno := unix.Syscall(
+syscall.SYS_IOCTL,
+uintptr(tunFd),
+uintptr(_TUNSIFHEAD),
+uintptr(unsafe.Pointer(&one)),
+); errno != 0 {
+unix.Close(tunFd)
+return nil, os.NewSyscallError("TUNSIFHEAD", errno)
+}
+
+// Set interface MTU
+if err = useSocket(unix.AF_INET, unix.SOCK_DGRAM, 0, func(fd int) error {
+ifr := ifreqMTU{MTU: int32(options.MTU)}
+copy(ifr.Name[:], options.Name)
+if _, _, errno := unix.Syscall(
+syscall.SYS_IOCTL,
+uintptr(fd),
+uintptr(unix.SIOCSIFMTU),
+uintptr(unsafe.Pointer(&ifr)),
+); errno != 0 {
+return os.NewSyscallError("SIOCSIFMTU", errno)
+}
+return nil
+}); err != nil {
+unix.Close(tunFd)
+return nil, err
+}
+
+if !options.EXP_ExternalConfiguration {
+for _, address := range options.Inet4Address {
+if err = setInet4Address(options.Name, address); err != nil {
+unix.Close(tunFd)
+return nil, err
+}
+}
+for _, address := range options.Inet6Address {
+if err = setInet6Address(options.Name, address); err != nil {
+unix.Close(tunFd)
+return nil, err
+}
+}
+if err = bringUp(options.Name); err != nil {
+unix.Close(tunFd)
+return nil, err
+}
+}
+
+return &NativeTun{
+tunFd:   tunFd,
+tunFile: os.NewFile(uintptr(tunFd), options.Name),
+options: options,
+}, nil
+}
+
+func setInet4Address(name string, address netip.Prefix) error {
+ifReq := ifAliasReq{
+Addr: unix.RawSockaddrInet4{
+Len:    unix.SizeofSockaddrInet4,
+Family: unix.AF_INET,
+Addr:   address.Addr().As4(),
+},
+Dstaddr: unix.RawSockaddrInet4{
+Len:    unix.SizeofSockaddrInet4,
+Family: unix.AF_INET,
+Addr:   address.Addr().As4(),
+},
+Mask: unix.RawSockaddrInet4{
+Len:    unix.SizeofSockaddrInet4,
+Family: unix.AF_INET,
+Addr:   netip.MustParseAddr(net.IP(net.CIDRMask(address.Bits(), 32)).String()).As4(),
+},
+}
+copy(ifReq.Name[:], name)
+return useSocket(unix.AF_INET, unix.SOCK_DGRAM, 0, func(fd int) error {
+if _, _, errno := unix.Syscall(
+syscall.SYS_IOCTL,
+uintptr(fd),
+uintptr(unix.SIOCAIFADDR),
+uintptr(unsafe.Pointer(&ifReq)),
+); errno != 0 {
+return os.NewSyscallError("SIOCAIFADDR", errno)
+}
+return nil
+})
+}
+
+func setInet6Address(name string, address netip.Prefix) error {
+ifReq6 := ifAliasReq6{
+Addr: unix.RawSockaddrInet6{
+Len:    unix.SizeofSockaddrInet6,
+Family: unix.AF_INET6,
+Addr:   address.Addr().As16(),
+},
+Mask: unix.RawSockaddrInet6{
+Len:    unix.SizeofSockaddrInet6,
+Family: unix.AF_INET6,
+Addr:   netip.MustParseAddr(net.IP(net.CIDRMask(address.Bits(), 128)).String()).As16(),
+},
+Flags: _IN6_IFF_NODAD | _IN6_IFF_SECURED,
+Lifetime: addrLifetime6{
+Vltime: _ND6_INFINITE_LIFETIME,
+Pltime: _ND6_INFINITE_LIFETIME,
+},
+}
+if address.Bits() == 128 {
+ifReq6.Dstaddr = unix.RawSockaddrInet6{
+Len:    unix.SizeofSockaddrInet6,
+Family: unix.AF_INET6,
+Addr:   address.Addr().Next().As16(),
+}
+}
+copy(ifReq6.Name[:], name)
+return useSocket(unix.AF_INET6, unix.SOCK_DGRAM, 0, func(fd int) error {
+if _, _, errno := unix.Syscall(
+syscall.SYS_IOCTL,
+uintptr(fd),
+uintptr(_SIOCAIFADDR_IN6),
+uintptr(unsafe.Pointer(&ifReq6)),
+); errno != 0 {
+return os.NewSyscallError("SIOCAIFADDR_IN6", errno)
+}
+return nil
+})
+}
+
+func bringUp(name string) error {
+return useSocket(unix.AF_INET, unix.SOCK_DGRAM, 0, func(fd int) error {
+var ifr ifreqFlags
+copy(ifr.Name[:], name)
+if _, _, errno := unix.Syscall(
+syscall.SYS_IOCTL,
+uintptr(fd),
+uintptr(unix.SIOCGIFFLAGS),
+uintptr(unsafe.Pointer(&ifr)),
+); errno != 0 {
+return os.NewSyscallError("SIOCGIFFLAGS", errno)
+}
+ifr.Flags |= unix.IFF_UP
+if _, _, errno := unix.Syscall(
+syscall.SYS_IOCTL,
+uintptr(fd),
+uintptr(unix.SIOCSIFFLAGS),
+uintptr(unsafe.Pointer(&ifr)),
+); errno != 0 {
+return os.NewSyscallError("SIOCSIFFLAGS", errno)
+}
+return nil
+})
+}
+
+func (t *NativeTun) Name() (string, error) {
+return t.options.Name, nil
+}
+
+func (t *NativeTun) Start() error {
+if t.options.EXP_ExternalConfiguration {
+return nil
+}
+t.options.InterfaceMonitor.RegisterMyInterface(t.options.Name)
+return t.setRoutes()
+}
+
+func (t *NativeTun) Close() error {
+if t.options.EXP_ExternalConfiguration {
+return t.tunFile.Close()
+}
+err := E.Errors(t.unsetRoutes(), t.tunFile.Close())
+// Destroy the interface so it doesn't leave stale addresses/routes behind.
+destroyErr := useSocket(unix.AF_INET, unix.SOCK_DGRAM, 0, func(fd int) error {
+var ifr ifreqMTU
+copy(ifr.Name[:], t.options.Name)
+_, _, errno := unix.Syscall(syscall.SYS_IOCTL, uintptr(fd),
+uintptr(unix.SIOCIFDESTROY), uintptr(unsafe.Pointer(&ifr)))
+if errno != 0 && errno != unix.ENXIO {
+return os.NewSyscallError("SIOCIFDESTROY", errno)
+}
+return nil
+})
+return E.Errors(err, destroyErr)
+}
+
+func (t *NativeTun) Read(p []byte) (n int, err error) {
+return t.tunFile.Read(p)
+}
+
+func (t *NativeTun) Write(p []byte) (n int, err error) {
+return t.tunFile.Write(p)
+}
+
+func (t *NativeTun) UpdateRouteOptions(tunOptions Options) error {
+t.options = tunOptions
+if t.options.EXP_ExternalConfiguration {
+return nil
+}
+if err := t.unsetRoutes(); err != nil {
+return err
+}
+return t.setRoutes()
+}
+
+func (t *NativeTun) setRoutes() error {
+if t.options.FileDescriptor != 0 {
+return nil
+}
+routeRanges, err := t.options.BuildAutoRouteRanges(false)
+if err != nil {
+return err
+}
+if len(routeRanges) == 0 {
+return nil
+}
+gateway4, gateway6 := t.options.Inet4GatewayAddr(), t.options.Inet6GatewayAddr()
+for _, destination := range routeRanges {
+var gateway netip.Addr
+if destination.Addr().Is4() {
+gateway = gateway4
+} else {
+gateway = gateway6
+}
+err = execRoute(unix.RTM_ADD, destination, gateway)
+if err != nil {
+if err == unix.EEXIST {
+_ = execRoute(unix.RTM_DELETE, destination, gateway)
+err = execRoute(unix.RTM_ADD, destination, gateway)
+}
+if err != nil {
+return E.Cause(err, "add route: ", destination)
+}
+}
+}
+t.routeSet = true
+return nil
+}
+
+func (t *NativeTun) unsetRoutes() error {
+if !t.routeSet {
+return nil
+}
+routeRanges, err := t.options.BuildAutoRouteRanges(false)
+if err != nil {
+return err
+}
+gateway4, gateway6 := t.options.Inet4GatewayAddr(), t.options.Inet6GatewayAddr()
+for _, destination := range routeRanges {
+var gateway netip.Addr
+if destination.Addr().Is4() {
+gateway = gateway4
+} else {
+gateway = gateway6
+}
+_ = execRoute(unix.RTM_DELETE, destination, gateway)
+}
+return nil
+}
+
+func useSocket(domain, typ, proto int, block func(fd int) error) error {
+fd, err := unix.Socket(domain, typ, proto)
+if err != nil {
+return err
+}
+defer unix.Close(fd)
+return block(fd)
+}
+
+func execRoute(rtmType int, destination netip.Prefix, gateway netip.Addr) error {
+msg := route.RouteMessage{
+Type:    rtmType,
+Version: unix.RTM_VERSION,
+Flags:   unix.RTF_STATIC | unix.RTF_GATEWAY,
+Seq:     1,
+}
+if rtmType == unix.RTM_ADD {
+msg.Flags |= unix.RTF_UP
+}
+if gateway.Is4() {
+msg.Addrs = []route.Addr{
+syscall.RTAX_DST:     &route.Inet4Addr{IP: destination.Addr().As4()},
+syscall.RTAX_NETMASK: &route.Inet4Addr{IP: netip.MustParseAddr(net.IP(net.CIDRMask(destination.Bits(), 32)).String()).As4()},
+syscall.RTAX_GATEWAY: &route.Inet4Addr{IP: gateway.As4()},
+}
+} else {
+msg.Addrs = []route.Addr{
+syscall.RTAX_DST:     &route.Inet6Addr{IP: destination.Addr().As16()},
+syscall.RTAX_NETMASK: &route.Inet6Addr{IP: netip.MustParseAddr(net.IP(net.CIDRMask(destination.Bits(), 128)).String()).As16()},
+syscall.RTAX_GATEWAY: &route.Inet6Addr{IP: gateway.As16()},
+}
+}
+request, err := msg.Marshal()
+if err != nil {
+return err
+}
+return useSocket(unix.AF_ROUTE, unix.SOCK_RAW, 0, func(fd int) error {
+return common.Error(unix.Write(fd, request))
+})
+}
