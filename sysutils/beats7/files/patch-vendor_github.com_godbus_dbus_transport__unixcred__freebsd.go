--- vendor/github.com/godbus/dbus/transport_unixcred_freebsd.go.orig	2020-05-28 07:16:25.000000000 -0700
+++ vendor/github.com/godbus/dbus/transport_unixcred_freebsd.go	2020-06-10 23:26:07.955802000 -0700
@@ -8,7 +8,7 @@
 package dbus
 
 /*
-const int sizeofPtr = sizeof(void*);
+const int sizeOfPtr = sizeof(void*);
 #define _WANT_UCRED
 #include <sys/ucred.h>
 */
@@ -38,7 +38,7 @@
 
 // http://golang.org/src/pkg/syscall/sockcmsg_unix.go
 func cmsgAlignOf(salen int) int {
-	salign := C.sizeofPtr
+	salign := C.sizeOfPtr
 
 	return (salen + salign - 1) & ^(salign - 1)
 }
