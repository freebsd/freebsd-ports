--- src/enums.h.orig	2018-07-15 20:46:55 UTC
+++ src/enums.h
@@ -9,6 +9,8 @@
 #ifndef SQUID_ENUMS_H
 #define SQUID_ENUMS_H
 
+#undef FD_NONE
+
 enum fd_type {
     FD_NONE,
     FD_LOG,
