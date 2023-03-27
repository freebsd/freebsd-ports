--- liba2ps/printers.c.orig	2022-06-11 20:35:11 UTC
+++ liba2ps/printers.c
@@ -287,8 +287,8 @@ a2ps_printers_new (struct a2ps_common_s * common)
   res->ppd = NULL;		/* Printer's ppd are not read yet */
 
   /* Output */
-  /* Default is to send to default printer */
-  res->flag_output_is_printer = true;
+  /* Default is to send to stdout */
+  res->flag_output_is_printer = false;
   res->flag_output_name = NULL;
   res->output_is_file = true;
   res->output_name = NULL;
