--- smb.c.orig	2017-03-13 11:29:29 UTC
+++ smb.c
@@ -512,7 +512,11 @@ static size_t utf16toutf8(char* dest,size_t dsize,uint
   X=ssize;
   Y=dsize?dsize-1:dsize;	// the -1 makes sure we have a 0 byte at the end
   memset(dest,0,dsize);
+#if defined(__sun__) || defined(__FreeBSD__)
+  if (iconv(wc2utf8,(const char**)&x,&X,&y,&Y)) return 0;
+#else
   if (iconv(wc2utf8,&x,&X,&y,&Y)) return 0;
+#endif
   return dsize-Y;
 }
 
