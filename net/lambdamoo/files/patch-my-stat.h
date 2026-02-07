--- my-stat.h.orig	2024-10-18 08:58:26 UTC
+++ my-stat.h
@@ -31,11 +31,6 @@ extern int mkfifo(const char *, mode_t);
 extern int mkfifo(const char *, mode_t);
 #endif
 
-#if !HAVE_MKFIFO
-extern int mknod(const char *file, int mode, int dev);
-#define mkfifo(path, mode)	mknod(path, S_IFIFO | (mode), 0)
-#endif
-
 /* 
  * $Log: my-stat.h,v $
  * Revision 1.3  1998/12/14 13:18:15  nop
