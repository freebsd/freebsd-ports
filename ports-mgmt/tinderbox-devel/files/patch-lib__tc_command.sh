--- ./lib/tc_command.sh.orig	2008-11-12 22:31:40.000000000 +0200
+++ ./lib/tc_command.sh	2008-11-12 22:32:00.000000000 +0200
@@ -288,9 +288,9 @@
 #---------------------------------------------------------------------------
 
 Upgrade () {
-    VERSION="3.0"
+    VERSION="3.1"
     TINDERBOX_URL="http://tinderbox.marcuscom.com/"
-    DB_MIGRATION_PATH="${VERSION}"
+    DB_MIGRATION_PATH="3.0 ${VERSION}"
 
     bkup_file=""
 
