--- gatling.c.orig	2014-08-12 18:41:26.000000000 +0200
+++ gatling.c	2014-08-12 18:42:24.000000000 +0200
@@ -1736,7 +1736,7 @@
     Y=sizeof(workgroup_utf16);
     x=workgroup;
     y=workgroup_utf16;
-#ifdef __sun__
+#if defined(__sun__) || defined(__FreeBSD__)
     if (iconv(i,(const char**)&x,&X,&y,&Y)) panic("UTF-16 conversion of workgroup failed.\n");
 #else
     if (iconv(i,&x,&X,&y,&Y)) panic("UTF-16 conversion of workgroup failed.\n");
