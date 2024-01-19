--- src/main-user.c.orig	2023-12-27 19:54:08 UTC
+++ src/main-user.c
@@ -47,7 +47,7 @@
 #include <script-list.h>
 #include <ccan/list/list.h>
 
-#define OCSERV_FW_SCRIPT "/usr/libexec/ocserv-fw"
+#define OCSERV_FW_SCRIPT "%%PREFIX%%/libexec/ocserv-fw"
 
 #define APPEND_TO_STR(str, val) \
 	do { \
