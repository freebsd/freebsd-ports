--- mptsd.c.orig	2011-09-16 12:37:04 UTC
+++ mptsd.c
@@ -34,7 +34,7 @@
 
 #define PROGRAM_NAME "ux-mptsd"
 
-const char *program_id = PROGRAM_NAME " " GIT_VER " build " BUILD_ID;
+const char *program_id = PROGRAM_NAME " FreeBSD port";
 
 char *server_sig = PROGRAM_NAME;
 char *server_ver = GIT_VER;
