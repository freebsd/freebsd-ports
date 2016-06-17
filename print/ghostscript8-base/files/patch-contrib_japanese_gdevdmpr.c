--- contrib/japanese/gdevdmpr.c.orig	2007-09-25 13:31:24 UTC
+++ contrib/japanese/gdevdmpr.c
@@ -41,8 +41,6 @@
 /* include library header. */
 #include "dviprlib.h"
 
-extern FILE *lib_fopen(const char *);
-
 #define LOCAL_DEBUG 0
 
 #define DEVICE_NAME "dmprt"
@@ -405,8 +403,6 @@ gdev_dmprt_put_params(gx_device *pdev, g
   if (pddev->dmprt.max_height>0 && pddev->dmprt.max_height<pddev->height)
     pddev->height = pddev->dmprt.max_height;
   
-  dviprt_setmessagestream(pddev->dmprt.debug_f ? stderr : NULL);
-  
   return code;
 }
 
@@ -425,8 +421,6 @@ gdev_dmprt_put_dmprt_params(gx_device *p
   if (code < 0) return code;
   if (code == 0) pddev->dmprt.debug_f = vbool;
   
-  dviprt_setmessagestream(pddev->dmprt.debug_f ? stderr : NULL);
-  
   code = param_read_bool(plist, "Verbose", &vbool);
   if (code < 0) return code;
   pddev->dmprt.verbose_f = vbool;
@@ -841,13 +835,12 @@ gdev_dmprt_dviprt_lib_fopen(const char *
   char *env;
 
   strcpy(fname,fnamebase);
-  fp = lib_fopen(fname);
+  fp = fopen(fname,"r");
   if (fp == NULL) {
     env = getenv("TEXCFG");
     if (env) {
       strcpy(fname,env);
       strcat(fname, gp_file_name_concat_string(env,strlen(env)));
-      strcat(fname,fnamebase);
       fp = fopen(fname,gp_fmode_rb);
     }
   }
