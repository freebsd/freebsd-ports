--- contrib/japanese/gdevdmpr.c.orig	2011-08-05 20:12:20.000000000 +0900
+++ contrib/japanese/gdevdmpr.c	2011-12-06 15:36:10.000000000 +0900
@@ -32,7 +32,7 @@
 
 #include "gdevprn.h"
 #include "gp.h"
-#include "errors.h"
+#include "psi/ierrors.h"
 #include "gsparam.h"
 #include "gsstate.h"
 #include "math_.h"
@@ -41,8 +41,6 @@
 /* include library header. */
 #include "dviprlib.h"
 
-extern FILE *lib_fopen(const char *);
-
 #define LOCAL_DEBUG 0
 
 #define DEVICE_NAME "dmprt"
@@ -402,8 +400,6 @@
   if (pddev->dmprt.max_height>0 && pddev->dmprt.max_height<pddev->height)
     pddev->height = pddev->dmprt.max_height;
 
-  dviprt_setmessagestream(pddev->dmprt.debug_f ? stderr : NULL);
-
   return code;
 }
 
@@ -422,8 +418,6 @@
   if (code < 0) return code;
   if (code == 0) pddev->dmprt.debug_f = vbool;
 
-  dviprt_setmessagestream(pddev->dmprt.debug_f ? stderr : NULL);
-
   code = param_read_bool(plist, "Verbose", &vbool);
   if (code < 0) return code;
   pddev->dmprt.verbose_f = vbool;
@@ -846,13 +840,12 @@
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
