--- terminfo/checktc.c.orig	Fri Sep 29 09:13:22 1995
+++ terminfo/checktc.c	Tue Apr 22 20:37:18 2003
@@ -171,6 +171,7 @@
   fflush(stdout);
 }
 
+#ifndef __FreeBSD__
 void CPutStr(s, c)
 char *s;
 int c;
@@ -178,6 +179,7 @@
   tputs(tgoto(s, 0, c), 1, putcha);
   fflush(stdout);
 }
+#endif /* __FreeBSD__ */
 
 void CCPutStr(s, x, y)
 char *s;
