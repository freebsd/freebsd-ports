--- gatling.c.orig	2020-04-07 13:25:34 UTC
+++ gatling.c
@@ -1950,7 +1950,7 @@ usage:
     Y=sizeof(workgroup_utf16);
     x=workgroup;
     y=workgroup_utf16;
-#ifdef __sun__
+#if defined(__sun__) || defined(__FreeBSD__)
     if (iconv(i,(const char**)&x,&X,&y,&Y)) panic("UTF-16 conversion of workgroup failed.\n");
 #else
     if (iconv(i,&x,&X,&y,&Y)) panic("UTF-16 conversion of workgroup failed.\n");
