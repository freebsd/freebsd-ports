--- ../mlmmj-0.8.1.orig/src/mlmmj-make-ml.sh	Fri Jun 25 02:05:43 2004
+++ src/mlmmj-make-ml.sh	Sun Jun 27 20:31:18 2004
@@ -5,6 +5,7 @@
 
 VERSION="0.1"
 DEFAULTDIR="/var/spool/mlmmj"
+PREFIX="%%PREFIX%%"
 
 USAGE="mlmmj-make-ml "$VERSION"
 "$0" [OPTIONS]
@@ -81,8 +82,11 @@
 fi
 echo "$OWNER" > "$LISTDIR"/"control/owner"
 
-echo -n "The path to texts for the list? (listtexts/ dir in the src) [] : "
+echo -n "The path to texts for the list? (listtexts/ dir in the src) [$PREFIX/share/mlmmj/text.skel] : "
 read TEXTPATH
+if [ -z "$TEXTPATH" ]; then
+	TEXTPATH="$PREFIX/share/mlmmj/text.skel"
+fi
 if [ -z "$TEXTPATH" -o ! -d "$TEXTPATH" ]; then
 	echo "**NOTE** Could not copy the texts for the list"
 	echo "Please manually copy the files from the listtexts/ directory"
