diff -urN mlmmj-0.7.1.orig/src/mlmmj-make-ml.sh mlmmj-0.7.1/src/mlmmj-make-ml.sh
--- mlmmj-0.7.1.orig/src/mlmmj-make-ml.sh	Sun Jun  6 20:26:51 2004
+++ src/mlmmj-make-ml.sh	Sat Jun 12 15:39:29 2004
@@ -5,6 +5,7 @@
 
 VERSION="0.1"
 DEFAULTDIR="/var/spool/mlmmj"
+PREFIX="%%PREFIX%%"
 
 USAGE="mlmmj-make-ml "$VERSION"
 "$0" [OPTIONS]
@@ -74,8 +75,11 @@
 	FQDN=`domainname`
 fi
 
-echo -n "The path to the directory with the texts for the list? [] : "
+echo -n "The path to the directory with the texts for the list? [$PREFIX/share/mlmmj/listtexts] : "
 read TEXTPATH
+if [ -z "$TEXTPATH" ]; then
+	TEXTPATH="$PREFIX/share/mlmmj/listtexts"
+fi
 if [ -z "$TEXTPATH" -o ! -d "$TEXTPATH" ]; then
 	echo "**NOTE** Could not copy the texts for the list"
 	echo "Please manually copy the files from the listtexts/ directory"
