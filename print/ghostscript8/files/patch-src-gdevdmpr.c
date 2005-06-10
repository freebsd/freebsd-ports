--- src/gdevdmpr.c.orig	Tue May 13 20:43:37 1997
+++ src/gdevdmpr.c	Thu Jun  9 02:52:25 2005
@@ -41,7 +41,7 @@
 /* include library header. */
 #include "dviprlib.h"
 
-extern FILE *lib_fopen(P1(const char *));
+extern FILE *lib_fopen(const char *);
 
 #define LOCAL_DEBUG 0
 
@@ -87,12 +87,12 @@
 private dev_proc_close_device(gdev_dmprt_close);
 
 /* declarations of sub functions to get printer properties. */
-private void gdev_dmprt_init_printer_props(P1(gx_device_dmprt *));
-private int gdev_dmprt_get_printer_props(P2(gx_device_dmprt *,char *));
-private int gdev_dmprt_check_code_props(P2(byte * ,int ));
-private FILE *gdev_dmprt_dviprt_lib_fopen(P2(const char *,char *));
+private void gdev_dmprt_init_printer_props(gx_device_dmprt *);
+private int gdev_dmprt_get_printer_props(gx_device_dmprt *,char *);
+private int gdev_dmprt_check_code_props(byte * ,int );
+private FILE *gdev_dmprt_dviprt_lib_fopen(const char *,char *);
 
-private int gdev_dmprt_error_no_dviprt_to_gs(P1(int ));
+private int gdev_dmprt_error_no_dviprt_to_gs(int );
 
 /* The device descriptor */
 gx_device_procs prn_dmprt_procs = {
@@ -833,6 +833,7 @@
   return code;
 }
 
+private const char * gp_file_name_concat_string(const char *, unsigned);
 private FILE *
 gdev_dmprt_dviprt_lib_fopen(const char *fnamebase,char *fname)
 {
@@ -845,9 +846,7 @@
     env = getenv("TEXCFG");
     if (env) {
       strcpy(fname,env);
-      strcat(fname,
-        gp_file_name_concat_string(env,strlen(env),fname,strlen(fnamebase)));
-      strcat(fname,fnamebase);
+      strcat(fname, gp_file_name_concat_string(env,strlen(env)));
       fp = fopen(fname,gp_fmode_rb);
     }
   }
@@ -867,4 +866,15 @@
   default:
     return -1;
   }
+}
+
+/* Answer the string to be used for combining a directory/device prefix */
+/* with a base file name. The prefix directory/device is examined to    */
+/* determine if a separator is needed and may return an empty string    */
+private const char *
+gp_file_name_concat_string(const char *prefix, unsigned plen)
+{
+    if (plen > 0 && prefix[plen - 1] == '/')
+        return "";
+    return "/";
 }
