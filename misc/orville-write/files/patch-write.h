--- write.h.orig	Sun Sep  7 22:55:03 2003
+++ write.h	Sun Sep  7 22:56:20 2003
@@ -34,6 +34,7 @@
 
 /* wrt_main.c functions */
 void done(int code);
+void _log(char *outcome);
 
 /* wrt_me.c functions */
 void find_me(void);
