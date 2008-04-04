--- lib/scripts/timestart.bash.orig	Thu Dec  8 01:23:22 2005
+++ lib/scripts/timestart.bash	Sat Jan 12 17:53:32 2008
@@ -10,9 +10,11 @@
 #set by configure
 AUTO_PERL=perl
 
-function get_times () {
-  local TMP="/tmp/get_times$$"
+get_times () {
+  local TMP SECONDS
+  TMP="/tmp/get_times$$"
   times > "$TMP"   # No pipe here!
+  SECONDS=$(( `date +'%j * 86400 + %H * 3600 + %M * 60 + %S'` ))
   TIMES_RESULT="$SECONDS $(echo $(cat "$TMP") | "$AUTO_PERL" -pe 's,\d+m\d+\.\d+s \d+m\d+\.\d+s (\d+)m(\d+)\.\d+s +(\d+)m(\d+)\.\d+s, $1 * 60 + $2 + $3 * 60 + $4,e')"
   rm -f "$TMP"
 }
