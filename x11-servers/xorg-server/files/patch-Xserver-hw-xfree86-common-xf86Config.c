Index: programs/Xserver/hw/xfree86/common/xf86Config.c
diff -u -p programs/Xserver/hw/xfree86/common/xf86Config.c.orig programs/Xserver/hw/xfree86/common/xf86Config.c
--- programs/Xserver/hw/xfree86/common/xf86Config.c.orig	Wed Dec 21 07:30:50 2005
+++ programs/Xserver/hw/xfree86/common/xf86Config.c	Thu Jan 26 15:10:39 2006
@@ -505,8 +505,12 @@ GenerateDriverlist(char * dirname, char 
 {
 #ifdef XFree86LOADER
     char **ret;
-    char *subdirs[] = { dirname, NULL };
+    char *subdirs[2];
     static const char *patlist[] = {"(.*)_drv\\.so", "(.*)_drv\\.o", NULL};
+
+    subdirs[0] = dirname;
+    subdirs[1] = NULL;
+
     ret = LoaderListDirs(subdirs, patlist);
     
     /* fix up the probe order for video drivers */
