--- src/enums.h.orig	2019-02-18 18:46:22.000000000 -0800
+++ src/enums.h	2019-04-17 22:22:05.123445000 -0700
@@ -9,6 +9,9 @@
 #ifndef SQUID_ENUMS_H
 #define SQUID_ENUMS_H
 
+/* Namespace pollution from fcntl.h as of FreeBSD r345982 */
+#undef FD_NONE
+
 enum fd_type {
     FD_NONE,
     FD_LOG,
