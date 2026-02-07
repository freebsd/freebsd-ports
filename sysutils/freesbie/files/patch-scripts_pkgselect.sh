--- scripts/pkgselect.sh.orig	2006-05-26 23:20:09 UTC
+++ scripts/pkgselect.sh
@@ -21,7 +21,7 @@ PKGFILE=${PKGFILE:-${LOCALDIR}/conf/pack
 
 # Check if there are packages installed on the system
 check_pkgs() {
-    count=$(pkg_info -Qoa | wc -l)
+    count=$(pkg query -a "%n-%v:%o" | wc -l)
     if [ ${count} -eq 0 ]; then
 	/usr/bin/dialog --title "FreeSBIE Packages selection" --clear \
 	--msgbox "Sorry, you don't have any packages installed.\n\nPlease install at least the packages you want\nto include in your distribution." 10 50
@@ -40,7 +40,7 @@ create_lists() {
     # Create a different file for each category. Each row in each file
     # will look like:
     # PKGNAME PKGNAME-version    
-    pkg_info -Qoa | awk \
+    pkg query -a "%n-%v:%o" | awk \
 ' BEGIN { FS=":|/" } 
 { 
     a=$1;
@@ -63,7 +63,7 @@ create_lists() {
 
 	    # pkg_info might fail if the listed package isn't present
 	    set +e
-	    origins=$(pkg_info -QoX "^$(escape_pkg ${pkg})($|-[^-]+$)")
+	    origins=$(pkg query -x "%n-%v:%o" "^$(escape_pkg ${pkg})($|-[^-]+$)")
 	    retval=$?
 	    set -e
 	    if [ ${retval} -eq 0 ]; then
