--- src/dviprlib.c.orig	Tue May 13 00:14:09 1997
+++ src/dviprlib.c	Thu Apr  4 03:18:57 2002
@@ -1433,7 +1433,8 @@
 char *dviprt_prtcodename[] = { CFG_PRTCODE_NAME, NULL };
 char *dviprt_encodename[] = { CFG_ENCODE_NAME, NULL };
 
-private FILE *dviprt_messagestream = stderr;
+private FILE *dviprt_messagestream;
+private int dviprt_messagestream_init;
 
 /*--- library functions ---*/
 int
@@ -1505,6 +1506,10 @@
 liblocal int
 dviprt_printmessage(char *str,int len)
 {
+  if (!dviprt_messagestream_init) {
+    dviprt_messagestream = stderr;
+    dviprt_messagestream_init = 1;
+  }
   if (dviprt_messagestream && str) {
     if (len >= 0) fwrite(str,len,1,dviprt_messagestream);
     else fputs(str,dviprt_messagestream);
