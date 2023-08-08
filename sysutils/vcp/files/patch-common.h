--- common.h.orig	2022-11-06 13:00:14 UTC
+++ common.h
@@ -23,8 +23,8 @@
 #define T_DIR  1 /*      -> DIR              */
 #define T_NED  2 /* DIR  -> NON-EXISTENT DIR */
 
-WINDOW *mainw;
-WINDOW *logw;
+extern WINDOW *mainw;
+extern WINDOW *logw;
 
 struct dest_new {
 	char *opath;
