--- ac3/ac3dec_wrap.c.orig	Sun Mar  2 16:50:03 2003
+++ ac3/ac3dec_wrap.c	Wed Jul  4 21:14:18 2007
@@ -48,7 +48,7 @@
 static void handle_events(MsgEventQ_t *q, MsgEvent_t *ev);
 
 
-static char *program_name;
+char *program_name;
 
 static FILE *outfile;
 
