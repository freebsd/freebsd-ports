--- doc/asciidoc-helper.sh.orig	2022-03-02 04:01:16 UTC
+++ doc/asciidoc-helper.sh
@@ -12,9 +12,6 @@ if [ $# != 3 ]; then
     exit 1
 fi
 
-SOURCE_DATE_EPOCH="$(git show --no-patch --format='%ct')"
-export SOURCE_DATE_EPOCH
-
 output=$3
 
 if [ "$1" = "html" ]; then
