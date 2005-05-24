--- lib/folder.tcl.orig	Wed Dec 29 23:39:51 2004
+++ lib/folder.tcl	Wed May 25 00:02:21 2005
@@ -311,17 +311,17 @@
 
     set out [open $fn w]
     puts $out "wm withdraw ."
-    puts $out "source $exmh(library)/folder.tcl"
+    puts $out [list lappend auto_path $exmh(library)]
     puts $out [list set mhProfile(delprefix) $mhProfile(delprefix)]
     puts $out [list set mhProfile(purgeage) $mhProfile(purgeage)]
     puts $out [list set mhProfile(path) $mhProfile(path)]
-    puts $out "proc Exmh_Status { s } \{catch \{send \"[winfo name .]\" \[list Exmh_Status \$s]\}\}"
+    puts $out "proc Exmh_Status { s args } \{catch \{send \"[winfo name .]\" \[list Exmh_Status \$s]\}\}"
     puts $out "proc Exmh_Debug { args } {}"
-    puts $out [list proc File_Delete [info args File_Delete] [info body File_Delete]]
+    puts $out "Env_Init"
     foreach folder $folderlist {
-	puts $out "Folder_Purge $folder"
+	puts $out [list Folder_Purge $folder]
     }
-    puts $out "File_Delete $fn"
+    puts $out [list File_Delete $fn]
     puts $out exit
     close $out
     exec $wish -f $fn &
