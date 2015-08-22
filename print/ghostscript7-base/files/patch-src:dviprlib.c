--- src/dviprlib.c.orig	Tue May 13 16:14:09 1997
+++ src/dviprlib.c	Mon Apr 22 23:02:58 2002
@@ -1433,7 +1433,9 @@
 char *dviprt_prtcodename[] = { CFG_PRTCODE_NAME, NULL };
 char *dviprt_encodename[] = { CFG_ENCODE_NAME, NULL };
 
-private FILE *dviprt_messagestream = stderr;
+private FILE *dviprt_messagestream;
+private void dviprt_messagestream_construct (void) __attribute__((constructor));
+private void dviprt_messagestream_construct (void) { dviprt_messagestream = stderr; }
 
 /*--- library functions ---*/
 int
