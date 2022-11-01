--- vendor/github.com/insomniacslk/dhcp/dhcpv4/bindtodevice_bsd.go.orig	2021-12-20 11:34:32 UTC
+++ vendor/github.com/insomniacslk/dhcp/dhcpv4/bindtodevice_bsd.go
@@ -0,0 +1,19 @@
+//go:build freebsd || openbsd || netbsd
+// +build freebsd openbsd netbsd
+
+package dhcpv4
+
+import (
+      "net"
+      "syscall"
+)
+
+// BindToInterface emulates linux's SO_BINDTODEVICE option for a socket by using
+// IP_RECVIF.
+func BindToInterface(fd int, ifname string) error {
+      iface, err := net.InterfaceByName(ifname)
+      if err != nil {
+              return err
+      }
+      return syscall.SetsockoptInt(fd, syscall.IPPROTO_IP, syscall.IP_RECVIF, iface.Index)
+}
