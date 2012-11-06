--- bin/build-index.sh.orig	2012-05-31 07:28:54.000000000 +0100
+++ bin/build-index.sh	2012-11-06 20:13:04.887047813 +0000
@@ -1,8 +1,8 @@
-#!/bin/bash
+#!/bin/sh
 
 if [ "$GRAPHITE_ROOT" = "" ]
 then
-  GRAPHITE_ROOT="/opt/graphite"
+  GRAPHITE_ROOT="/usr/local/graphite"
 fi
 
 if [ "$GRAPHITE_STORAGE_DIR" = "" ]
@@ -11,7 +11,7 @@
 fi
 
 
-WHISPER_DIR="${GRAPHITE_STORAGE_DIR}/whisper"
+WHISPER_DIR="/usr/local/storage/whisper"
 
 if [ ! -d "$WHISPER_DIR" ]
 then
@@ -26,6 +26,6 @@
 cd $WHISPER_DIR
 touch $INDEX_FILE
 echo "[`date`]  building index..."
-find -L . -name '*.wsp' | perl -pe 's!^[^/]+/(.+)\.wsp$!$1!; s!/!.!g' > $TMP_INDEX
+find -L . -name '*.wsp' | sed -E 's!^[^/]+/(.+)\.wsp$!\1!; s!/!.!g' > $TMP_INDEX
 echo "[`date`]  complete, switching to new index file"
 mv -f $TMP_INDEX $INDEX_FILE
