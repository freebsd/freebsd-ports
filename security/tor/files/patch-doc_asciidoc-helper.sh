--- doc/asciidoc-helper.sh.orig	2022-02-04 16:24:11 UTC
+++ doc/asciidoc-helper.sh
@@ -12,7 +12,6 @@ if [ $# != 3 ]; then
   exit 1;
 fi
 
-SOURCE_DATE_EPOCH="$(git show --no-patch --format='%ct')"
 export SOURCE_DATE_EPOCH
 
 output=$3
