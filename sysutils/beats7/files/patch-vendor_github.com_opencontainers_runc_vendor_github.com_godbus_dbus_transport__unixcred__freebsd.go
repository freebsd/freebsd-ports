--- vendor/github.com/opencontainers/runc/vendor/github.com/godbus/dbus/transport_unixcred_freebsd.go.orig	2019-09-30 16:36:09 UTC
+++ vendor/github.com/opencontainers/runc/vendor/github.com/godbus/dbus/transport_unixcred_freebsd.go
@@ -8,8 +8,9 @@
 package dbus
 
 /*
-const int sizeofPtr = sizeof(void*);
+static const int sizeofPtr = sizeof(void*);
 #define _WANT_UCRED
+#include <sys/types.h>#include <sys/types.h>
 #include <sys/ucred.h>
 */
 import "C"
