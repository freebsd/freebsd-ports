--- vendor/github.com/godbus/dbus/v5/transport_unixcred_freebsd.go.orig	2020-08-31 12:11:57 UTC
+++ vendor/github.com/godbus/dbus/v5/transport_unixcred_freebsd.go
@@ -10,6 +10,7 @@ package dbus
 /*
 const int sizeofPtr = sizeof(void*);
 #define _WANT_UCRED
+#include <sys/types.h>
 #include <sys/ucred.h>
 */
 import "C"
