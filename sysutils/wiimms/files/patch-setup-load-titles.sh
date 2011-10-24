--- setup/load-titles.sh.orig	2011-08-04 07:50:20.000000000 +0200
+++ setup/load-titles.sh	2011-08-04 07:51:47.000000000 +0200
@@ -28,7 +28,7 @@
 
 #------------------------------------------------------------------------------
 
-NEEDED="wit wget tr"
+NEEDED="wit tr"
 
 BASE_PATH="@@INSTALL-PATH@@"
 SHARE_PATH="@@SHARE-PATH@@"
@@ -68,7 +68,7 @@
 
     echo "***    load $DEST from $URI"
 
-    if wget -q -O- "$URI" | wit titles / - >"$DEST.tmp" && test -s "$DEST.tmp"
+    if fetch -q -o- "$URI" | wit titles / - >"$DEST.tmp" && test -s "$DEST.tmp"
     then
 	if [[ $ADD != "" ]]
 	then
