--- varia/themes/emoticons/get-all.sh.orig	2008-12-01 00:15:08.000000000 +0100
+++ varia/themes/emoticons/get-all.sh	2009-03-12 23:56:25.000000000 +0100
@@ -2,7 +2,7 @@
 
 available_emots_themes=""
 for dir in *; do
-	if [ -f "$dir/emots.txt" ]; then
+	if [ "`find $dir -name emots.txt`" ]; then
 		available_emots_themes="$available_emots_themes $dir"
 	fi
 done
