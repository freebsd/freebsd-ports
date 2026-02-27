--- doc/asciidoc-helper.sh.orig	2026-02-27 06:06:19 UTC
+++ doc/asciidoc-helper.sh
@@ -12,11 +12,6 @@ fi
     exit 1
 fi
 
-if [ -z "$SOURCE_DATE_EPOCH" ]; then
-    SOURCE_DATE_EPOCH="$(git -C "$(dirname "$0")" show --no-patch --format='%ct')"
-    export SOURCE_DATE_EPOCH
-fi
-
 output=$3
 
 if [ "$1" = "html" ]; then
