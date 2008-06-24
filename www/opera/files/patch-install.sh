--- install.sh.orig	2008-06-17 14:57:32.206032200 +0200
+++ install.sh	2008-06-17 14:58:16.609863511 +0200
@@ -1274,7 +1274,6 @@
     mkdir $mkdirv $mkdirp $plugin_dir/
 
     # Wrapper
-    backup ${wrapper_dir}/opera opera
     debug_msg 1 "Wrapper"
     mkdir $mkdirv $mkdirp $wrapper_dir/
 
@@ -1282,7 +1281,7 @@
     generate_wrapper
     chmod $chmodv 755 $wrapper_dir/opera
 
-    if test -z "$OPERADESTDIR"
+    if false
     then
 	# System wide configuration files
 	case $os in AnyBSD|OpenBSD) config_dir="/usr/local/etc";; *) config_dir="/etc";; esac
