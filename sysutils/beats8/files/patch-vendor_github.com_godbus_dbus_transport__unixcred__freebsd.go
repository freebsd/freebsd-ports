--- vendor/github.com/godbus/dbus/v5/transport_unixcred_freebsd.go.orig	2021-08-05 12:40:38 UTC
+++ vendor/github.com/godbus/dbus/v5/transport_unixcred_freebsd.go
@@ -8,7 +8,8 @@
 package dbus
 
 /*
-const int sizeofPtr = sizeof(void*);
+static const int sizeofPtr = sizeof(void*);
+#include <sys/types.h>
 #define _WANT_UCRED
 #include <sys/ucred.h>
 */
