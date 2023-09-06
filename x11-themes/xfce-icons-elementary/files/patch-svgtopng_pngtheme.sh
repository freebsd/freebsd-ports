--- svgtopng/pngtheme.sh.orig	2023-09-06 10:58:55 UTC
+++ svgtopng/pngtheme.sh
@@ -18,13 +18,13 @@ echo " * Creating png icons from svg files and symlink
 
 echo " * Creating png icons from svg files and symlinks"
 #ignore list customized for elementary-xfce
-find "$icondir" -iname "*.svg" -not \( -wholename "*/scalable/*" -o -wholename "*/symbolic/*" -o -wholename "*-symbolic.svg" -o -wholename "*/animations/*process-*" -o -wholename "*/animations/*gnome-spinner*" -o -wholename "*/animations*pk-action-refresh*" \) -exec $cmd {} +
+find "$icondir" -iname "*.svg" -not \( -wholename "*/scalable/*" -o -wholename "*/symbolic/*" -o -wholename "*-symbolic.svg" -o -wholename "*-symbolic-rtl.svg" -o -wholename "*/animations/*process-*" -o -wholename "*/animations/*gnome-spinner*" -o -wholename "*/animations*pk-action-refresh*" \) -exec $cmd {} +
 
 echo " * Cleanup icon directory"
 find "$icondir" -name "untitled folder" -type d -exec rm -rf {} +
 
 echo " * Deleting svg files"
-find "$icondir" -iname '*.svg' -not \( -wholename "*/scalable/*" -o -wholename "*/symbolic/*" -o -wholename "*-symbolic.svg" -o -wholename "*/animations/*process-*" -o -wholename "*/animations/*gnome-spinner*" -o -wholename "*/animations*pk-action-refresh*" \) -delete
+find "$icondir" -iname '*.svg' -not \( -wholename "*/scalable/*" -o -wholename "*/symbolic/*" -o -wholename "*-symbolic.svg" -o -wholename "*-symbolic-rtl.svg" -o -wholename "*/animations/*process-*" -o -wholename "*/animations/*gnome-spinner*" -o -wholename "*/animations*pk-action-refresh*" \) -delete
 
 #ignore the output if the theme depends on another one (e.g. elementary-xfce-dark needs to be converted before elementary-xfce)
 echo " * Checking dangling symlinks"
