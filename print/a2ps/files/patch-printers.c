--- lib/printers.c.orig	1999-10-11 22:01:59 UTC
+++ lib/printers.c
@@ -315,8 +315,8 @@ a2ps_printers_new (struct a2ps_common_s 
   res->ppd = NULL;		/* Printer's ppd are not read yet */
 
   /* Output */
-  /* Default is to send to default printer */
-  res->flag_output_is_printer = true;
+  /* Default is to send to stdout */
+  res->flag_output_is_printer = false;
   res->flag_output_name = NULL;
   res->output_is_file = true;
   res->output_name = NULL;
