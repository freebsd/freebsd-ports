--- lib/tc_command.sh.orgi	2009-12-27 14:53:40.000000000 +0100
+++ lib/tc_command.sh	2009-12-27 14:53:52.000000000 +0100
@@ -223,7 +223,7 @@
 #---------------------------------------------------------------------------
 
 Setup () {
-    MAN_PREREQS="lang/perl5.[81]"
+    MAN_PREREQS="lang/perl5.[81]*"
     OPT_PREREQS="lang/php[45] databases/pear-MDB2 www/php[45]-session"
     PREF_FILES="tinderbox.ph"
     README="$(tinderLoc scripts README)"
