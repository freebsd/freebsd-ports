--- realtime.c.orig	Wed Nov 30 13:58:09 2005
+++ realtime.c	Wed Nov 30 13:58:20 2005
@@ -27,6 +27,8 @@
 
 void getdata(char *, FILE *);
 void datashow(char *);
+void getlog ();
+void header ();
 
 char dat[128];
 char tim[128];
