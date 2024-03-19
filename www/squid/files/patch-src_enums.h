--- src/enums.h.orig	2024-03-04 05:45:51 UTC
+++ src/enums.h
@@ -9,6 +9,9 @@
 #ifndef SQUID_SRC_ENUMS_H
 #define SQUID_SRC_ENUMS_H
 
+/* Namespace pollution from fcntl.h as of FreeBSD r345982 */
+#undef FD_NONE
+
 enum fd_type {
     FD_NONE_TYPE,
     FD_LOG,
