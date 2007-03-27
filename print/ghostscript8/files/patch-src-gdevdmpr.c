--- src/gdevdmpr.c.orig	Tue May 13 20:43:37 1997
+++ src/gdevdmpr.c	Sat Mar 24 15:41:48 2007
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
@@ -405,7 +405,9 @@
   if (pddev->dmprt.max_height>0 && pddev->dmprt.max_height<pddev->height)
     pddev->height = pddev->dmprt.max_height;
   
+#if 0
   dviprt_setmessagestream(pddev->dmprt.debug_f ? stderr : NULL);
+#endif
   
   return code;
 }
@@ -425,7 +427,9 @@
   if (code < 0) return code;
   if (code == 0) pddev->dmprt.debug_f = vbool;
   
+#if 0
   dviprt_setmessagestream(pddev->dmprt.debug_f ? stderr : NULL);
+#endif
   
   code = param_read_bool(plist, "Verbose", &vbool);
   if (code < 0) return code;
@@ -475,14 +479,14 @@
   code = param_read_string(plist, "FileName", &vstr);
   if (code < 0) return code;
   if (code == 0) {
-    char *filename = gs_malloc(vstr.size + 1, 1,
+    char *filename = gs_malloc(pdev->memory, vstr.size + 1, 1,
 			       "gdev_dmprt_put_props(filename)");
     int ccode;
     if (filename == 0) return e_VMerror;
     strncpy(filename, (const char*)vstr.data, vstr.size);
     filename[vstr.size] = '\0';
     ccode = gdev_dmprt_get_printer_props(pddev,filename);
-    gs_free(filename, vstr.size+1, 1, "gdev_dmprt_put_props(filename)");
+    gs_free(pdev->memory, filename, vstr.size+1, 1, "gdev_dmprt_put_props(filename)");
     if (ccode < 0) return ccode;
   }
 
@@ -686,7 +690,7 @@
   byte *in;
   
   /* get work buffer */
-  in = (byte *)gs_malloc(1, i_buf_size ,"gdev_dmprt_print_page(in)");
+  in = (byte *)gs_malloc(pdev->memory, 1, i_buf_size ,"gdev_dmprt_print_page(in)");
   if ( in == 0 )
     return e_VMerror;
   
@@ -737,7 +741,7 @@
     eprintf1(" %lu bytes\n",dviprt_getoutputbytes(pprint)-prev_bytes);
   }
 error_ex:
-  gs_free((char *)in, 1, i_buf_size,"gdev_dmprt_print_page(in)");
+  gs_free(pdev->memory, (char *)in, 1, i_buf_size,"gdev_dmprt_print_page(in)");
   
   return code;
 }
@@ -797,7 +801,7 @@
   dviprt_cfg_t cfg;
   char *fname;
 
-  fname = gs_malloc(256,1,"dviprt_lib_fname");
+  fname = gs_malloc(pdev->memory, 256,1,"dviprt_lib_fname");
   if (fname == NULL) return e_VMerror;
   
   fp = gdev_dmprt_dviprt_lib_fopen(fnamebase,fname);
@@ -828,11 +832,12 @@
       cfg.integer[CFG_Y_DPI] > 0 ? cfg.integer[CFG_Y_DPI] : pddev->dmprt.orig_x_dpi;
   }
   
-  gs_free(fname,256,1,"dviprt_lib_fname");
+  gs_free(pdev->memory, fname,256,1,"dviprt_lib_fname");
   
   return code;
 }
 
+private const char * gp_file_name_concat_string(const char *, unsigned);
 private FILE *
 gdev_dmprt_dviprt_lib_fopen(const char *fnamebase,char *fname)
 {
@@ -845,9 +850,7 @@
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
@@ -867,4 +870,15 @@
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
