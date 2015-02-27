--- bc/load.c~	2000-09-13 11:22:38.000000000 -0700
+++ bc/load.c	2005-08-02 11:06:00.000000000 -0700
@@ -156,7 +156,7 @@ load_code (code)
   long  label_no;
   long  vaf_name;	/* variable, array or function number. */
   long  func;
-  program_counter save_adr;
+  static program_counter save_adr; /* saved across calls to load_code */
 
   /* Initialize. */
   str = code;
