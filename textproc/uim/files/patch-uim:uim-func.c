--- uim/uim-func.c.orig	Sun Aug 31 15:09:52 2003
+++ uim/uim-func.c	Sun Aug 31 15:10:19 2003
@@ -97,15 +97,17 @@
 char *
 uim_code_conv(char *str, iconv_t ic)
 {
+  int len, buflen;
+  char *realbuf, *outbuf, *inbuf;
 
   if(!str)
     return NULL;
 
-  int len = strlen(str);
-  int buflen = len * 6+3;
-  char *realbuf = alloca(buflen);
-  char *outbuf = realbuf;
-  char *inbuf = str;
+  len = strlen(str);
+  buflen = len * 6+3;
+  realbuf = alloca(buflen);
+  outbuf = realbuf;
+  inbuf = str;
   if (!ic) {
     return strdup(str);
   }
