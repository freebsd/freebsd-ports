--- vendor/github.com/godbus/dbus/transport_unixcred_freebsd.go.orig	2019-12-08 01:39:36 UTC
+++ vendor/github.com/godbus/dbus/transport_unixcred_freebsd.go
@@ -10,6 +10,7 @@ package dbus
 /*
 const int sizeofPtr = sizeof(void*);
 #define _WANT_UCRED
+#include <sys/types.h>
 #include <sys/ucred.h>
 */
 import "C"
