--- install.sh.orig	2008-04-22 16:06:18.000000000 +0200
+++ install.sh	2008-04-24 13:49:24.470507835 +0200
@@ -865,7 +865,7 @@
 		error 'os'
 	;;
     esac
-    wrapper_file="${wrapper_dir}/opera"
+    wrapper_file="${wrapper_dir}/opera-devel"
 
     wrapper_contain="#!/bin/sh
 
@@ -877,6 +877,10 @@
 OPERA_BINARYDIR=${str_localdirexec}
 export OPERA_BINARYDIR
 
+# Location of Opera personal dir
+OPERA_PERSONALDIR=\${HOME}/.opera-devel
+export OPERA_PERSONALDIR
+
 # Parse commandline parameters
 toset=
 _QTSTYLE_FROM_CMDLINE_='NO'
@@ -1259,7 +1263,6 @@
     manifest_contains operapluginwrapper-native && part_install "`manifest_path operapluginwrapper-native`" "$exec_dir" Binaries
     manifest_contains operapluginwrapper-ia32-linux && part_install "`manifest_path operapluginwrapper-ia32-linux`" "$exec_dir" Binaries
     part_install "`manifest_path LICENSE`" "$doc_dir" Documentation
-    part_install "`manifest_path man1/opera.1`" "$man_dir" "Manual page"
 
     share_src="`manifest_path 'html40_entities\.dtd'`"
     part_install "$share_src" "$share_dir" "Shared resources"
@@ -1268,15 +1271,14 @@
     mkdir $mkdirv $mkdirp $plugin_dir/
 
     # Wrapper
-    backup ${wrapper_dir}/opera opera
     debug_msg 1 "Wrapper"
     mkdir $mkdirv $mkdirp $wrapper_dir/
 
     #cp $cpv $cpf wrapper.sh $wrapper_dir/opera
     generate_wrapper
-    chmod $chmodv 755 $wrapper_dir/opera
+    chmod $chmodv 755 $wrapper_dir/opera-devel
 
-    if test -z "$OPERADESTDIR"
+    if false
     then
 	# System wide configuration files
 	case $os in AnyBSD|OpenBSD) config_dir="/usr/local/etc";; *) config_dir="/etc";; esac
