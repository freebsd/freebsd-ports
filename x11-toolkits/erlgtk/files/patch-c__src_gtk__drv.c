
$FreeBSD$

--- c_src/gtk_drv.c.orig	Sat Aug 30 20:51:29 2003
+++ c_src/gtk_drv.c	Sat Aug 30 20:51:59 2003
@@ -80,6 +80,8 @@
 
 #define MAX_ARG_STACK  0x8000  /* max # of long words (128K) */
 
+#define ERL_MAX_COUNT 0xffffff
+
 #define ETERM_REF(e) do { \
   if (ERL_COUNT(e) < ERL_MAX_COUNT) \
       ERL_COUNT(e)++; \
