--- src/resource.c.orig	Sun Nov 14 10:16:12 2004
+++ src/resource.c	Wed Dec 29 22:06:11 2004
@@ -121,7 +121,7 @@
 {
   XrmDatabase db=NULL;
   String *sP;
-  String s,t;
+  String s,t,rpath;
   char tmp[GV_MAX_FILENAME_LENGTH];
 #ifdef VMS
   int b;
@@ -150,7 +150,7 @@
     //  s = XtResolvePathname(display,"app-defaults",NULL,NULL,NULL,NULL,0,NULL);
     /* #endif */
 
-    String rpath = GV_XtNewString(GV_LIBDIR);
+    rpath = GV_XtNewString(GV_LIBDIR);
     if (rpath) {
       INFSMESSAGE(merging system resource file into database,rpath)
 	XrmCombineFileDatabase(rpath,&db,True);
