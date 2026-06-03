-- Add gVisor (GVisorTun) support to FreeBSD's NativeTun.
-- Implements WritePacket (writes gVisor PacketBuffer to the TUN fd with the
-- 4-byte AF-family prefix required by TUNSIFHEAD) and NewEndpoint (returns a
-- channel.Endpoint with a reader goroutine for the pure gVisor stack).
-- Required by the "mixed" and "gvisor" network stacks when sing-box is built
-- with the with_gvisor tag.
--- vendor/github.com/sagernet/sing-tun/tun_freebsd_gvisor.go.orig	2026-05-04 17:24:50 UTC
+++ vendor/github.com/sagernet/sing-tun/tun_freebsd_gvisor.go
@@ -0,0 +1,107 @@
+//go:build with_gvisor && freebsd
+
+package tun
+
+import (
+	"encoding/binary"
+	"syscall"
+	"unsafe"
+
+	"github.com/sagernet/gvisor/pkg/buffer"
+	"github.com/sagernet/gvisor/pkg/tcpip"
+	gHdr "github.com/sagernet/gvisor/pkg/tcpip/header"
+	"github.com/sagernet/gvisor/pkg/tcpip/link/channel"
+	"github.com/sagernet/gvisor/pkg/tcpip/stack"
+
+	"golang.org/x/sys/unix"
+)
+
+// packetHeader{4,6} are the 4-byte big-endian AF-family prefixes written before
+// each packet when TUNSIFHEAD mode is active.
+var (
+	packetHeader4    = [4]byte{0, 0, 0, unix.AF_INET}
+	packetHeader6    = [4]byte{0, 0, 0, unix.AF_INET6}
+	packetHeaderVec4 unix.Iovec
+	packetHeaderVec6 unix.Iovec
+)
+
+func init() {
+	packetHeaderVec4 = unix.Iovec{Base: &packetHeader4[0]}
+	packetHeaderVec4.SetLen(4)
+	packetHeaderVec6 = unix.Iovec{Base: &packetHeader6[0]}
+	packetHeaderVec6.SetLen(4)
+}
+
+var _ GVisorTun = (*NativeTun)(nil)
+
+// WritePacket writes a gVisor packet buffer to the TUN device, prepending the
+// 4-byte big-endian AF-family header required by TUNSIFHEAD mode.
+func (t *NativeTun) WritePacket(pkt *stack.PacketBuffer) (int, error) {
+	iovecs := t.iovecsOutputDefault
+	if pkt.NetworkProtocolNumber == gHdr.IPv4ProtocolNumber {
+		iovecs = append(iovecs, packetHeaderVec4)
+	} else {
+		iovecs = append(iovecs, packetHeaderVec6)
+	}
+	var dataLen int
+	for _, s := range pkt.AsSlices() {
+		if len(s) == 0 {
+			continue
+		}
+		dataLen += len(s)
+		iov := unix.Iovec{Base: &s[0]}
+		iov.SetLen(len(s))
+		iovecs = append(iovecs, iov)
+	}
+	if cap(iovecs) > cap(t.iovecsOutputDefault) {
+		t.iovecsOutputDefault = iovecs[:0]
+	}
+	_, _, errno := unix.Syscall(syscall.SYS_WRITEV,
+		uintptr(t.tunFd),
+		uintptr(unsafe.Pointer(&iovecs[0])),
+		uintptr(len(iovecs)))
+	if errno != 0 {
+		return 0, errno
+	}
+	return dataLen, nil
+}
+
+// NewEndpoint creates a gVisor link endpoint backed by the TUN device fd.
+// A goroutine is started to read packets from the TUN fd and inject them into
+// the channel endpoint.  This is used by the pure gVisor stack; the Mixed
+// stack drives packet flow itself via WritePacket / Tun.Read.
+func (t *NativeTun) NewEndpoint() (stack.LinkEndpoint, stack.NICOptions, error) {
+	ep := channel.New(1024, uint32(t.options.MTU), "")
+	go t.gvisorReadLoop(ep)
+	return ep, stack.NICOptions{}, nil
+}
+
+func (t *NativeTun) gvisorReadLoop(ep *channel.Endpoint) {
+	buf := make([]byte, t.options.MTU+PacketOffset)
+	for {
+		n, err := t.tunFile.Read(buf)
+		if err != nil {
+			return
+		}
+		if n < PacketOffset+gHdr.IPv4MinimumSize {
+			continue
+		}
+		af := binary.BigEndian.Uint32(buf[:PacketOffset])
+		rawPkt := make([]byte, n-PacketOffset)
+		copy(rawPkt, buf[PacketOffset:n])
+		var proto tcpip.NetworkProtocolNumber
+		switch uint32(af) {
+		case uint32(unix.AF_INET):
+			proto = gHdr.IPv4ProtocolNumber
+		case uint32(unix.AF_INET6):
+			proto = gHdr.IPv6ProtocolNumber
+		default:
+			continue
+		}
+		pkt := stack.NewPacketBuffer(stack.PacketBufferOptions{
+			Payload: buffer.MakeWithData(rawPkt),
+		})
+		ep.InjectInbound(proto, pkt)
+		pkt.DecRef()
+	}
+}
