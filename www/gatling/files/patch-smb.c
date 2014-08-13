--- smb.c.orig	2014-08-12 18:48:53.000000000 +0200
+++ smb.c	2014-08-12 18:49:02.000000000 +0200
@@ -511,7 +511,11 @@
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
 
