--- vendor/github.com/godbus/dbus/v5/transport_unixcred_freebsd.go.orig	2019-09-30 20:29:11 UTC
+++ vendor/github.com/godbus/dbus/v5/transport_unixcred_freebsd.go
@@ -8,8 +8,9 @@
 package dbus
 
 /*
-const int sizeofPtr = sizeof(void*);
+static const int sizeofPtr = sizeof(void*);
 #define _WANT_UCRED
+#include <sys/types.h>
 #include <sys/ucred.h>
 */
 import "C"
