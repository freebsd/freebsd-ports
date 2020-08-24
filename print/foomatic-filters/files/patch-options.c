--- options.c.orig	2012-07-02 14:50:46 UTC
+++ options.c
@@ -38,15 +38,15 @@ typedef struct icc_mapping_entry_s {
 } icc_mapping_entry_t;
 
 /* Values from foomatic keywords in the ppd file */
-char printer_model [256];
+extern char printer_model [256];
 char printer_id [256];
 char driver [128];
 char cmd [4096];
 char cmd_pdf [4096];
-dstr_t *postpipe = NULL;  /* command into which the output of this
+extern dstr_t *postpipe;  /* command into which the output of this
                              filter should be piped */
 int ps_accounting = 1;
-char cupsfilter [256];
+extern char cupsfilter [256];
 int jobentitymaxlen = 0;
 int userentitymaxlen = 0;
 int hostentitymaxlen = 0;
