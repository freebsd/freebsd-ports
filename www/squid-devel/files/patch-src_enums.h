--- src/enums.h.orig	2020-04-19 10:50:48 UTC
+++ src/enums.h
@@ -9,6 +9,9 @@
 #ifndef SQUID_ENUMS_H
 #define SQUID_ENUMS_H
 
+/* Namespace pollution from fcntl.h as of FreeBSD r345982 */
+#undef FD_NONE
+
 enum fd_type {
     FD_NONE_TYPE,
     FD_LOG,
