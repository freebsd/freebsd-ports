--- erpcd/tms_dbm.c.orig	Thu Dec 14 13:25:31 2006
+++ erpcd/tms_dbm.c	Thu Dec 14 13:27:08 2006
@@ -1505,13 +1505,14 @@
  *
  ************************************************************/
 
+static char ctoh();
+
 static int
 parse_addmod(argc, argv, adding)
   int  argc;
   char **argv;
   int  adding;
 {
-  char ctoh();
   static char inv_val[] = "Invalid %s value \"%s\"\n";
 
   static struct kw_entry {
