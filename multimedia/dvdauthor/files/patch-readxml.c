--- src/readxml.c.orig	Fri Mar 12 23:57:39 2004
+++ src/readxml.c	Sun Dec  5 20:19:28 2004
@@ -221,13 +221,13 @@
 char *utf8tolocal(const char *in)
 {
     iconv_t c=get_conv();
-    int inlen=strlen(in);
-    int outlen=inlen*5;
+    size_t inlen=strlen(in);
+    size_t outlen=inlen*5;
     char *r=malloc(outlen+1);
     char *out=r;
-    int v;
+    size_t v;
 
-    v=iconv(c,ICONV_CAST &in,&inlen,&out,&outlen);
+    v=iconv(c,&in,&inlen,&out,&outlen);
     if(v==-1) {
         fprintf(stderr,"ERR:  Cannot convert UTF8 string '%s': %s\n",in,strerror(errno));
         exit(1);

