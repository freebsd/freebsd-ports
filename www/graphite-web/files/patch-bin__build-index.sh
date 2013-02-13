--- ./bin/build-index.sh.orig	2012-05-23 15:55:20.000000000 +0900
+++ ./bin/build-index.sh	2012-05-23 15:55:39.000000000 +0900
@@ -2,7 +2,7 @@
 
 if [ "$GRAPHITE_ROOT" = "" ]
 then
-  GRAPHITE_ROOT="/opt/graphite"
+  GRAPHITE_ROOT="%%WWWDIR%%"
 fi
 
 if [ "$GRAPHITE_STORAGE_DIR" = "" ]
