--- mptsd.c.orig	2018-05-07 06:42:40 UTC
+++ mptsd.c
@@ -35,9 +35,9 @@
 #define PROGRAM_NAME "ux-mptsd"
 
 #ifdef BUILD_ID
-const char *program_id = PROGRAM_NAME " " GIT_VER " build " BUILD_ID;
+const char *program_id = PROGRAM_NAME " " GIT_VER " build " BUILD_ID " FreeBSD port";
 #else
-const char *program_id = PROGRAM_NAME " " GIT_VER;
+const char *program_id = PROGRAM_NAME " " GIT_VER " FreeBSD port";
 #endif
 
 char *server_sig = PROGRAM_NAME;
