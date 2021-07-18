--- vendor/github.com/godbus/dbus/transport_unixcred_freebsd.go.orig	2021-05-06 12:02:02 UTC
+++ vendor/github.com/godbus/dbus/transport_unixcred_freebsd.go
@@ -4,12 +4,14 @@
 // http://code.google.com/p/go/source/browse/unix/sockcmsg_linux.go?repo=sys
 
 // Local implementation of the UnixCredentials system call for FreeBSD
+// Patch added from upstream project: https://github.com/godbus/dbus/commit/efee8394fa9a426004eb24eed1dee80f5efd90af
 
 package dbus
 
 /*
 const int sizeofPtr = sizeof(void*);
 #define _WANT_UCRED
+#include <sys/types.h>
 #include <sys/ucred.h>
 */
 import "C"
