/usr gets changed to ${LOCALBASE} in post-patch:, so we
cheat and set xpdf's path to /usr/lib.

--- src/plugins/fts/decode2text.sh.orig	2015-12-12 16:32:01 UTC
+++ src/plugins/fts/decode2text.sh
@@ -79,7 +79,11 @@ wait_timeout() {
 LANG=en_US.UTF-8
 export LANG
 if [ $fmt = "pdf" ]; then
-  /usr/bin/pdftotext $path - 2>/dev/null&
+  if [ -x /usr/lib/xpdf/pdftotext ]; then
+    /usr/lib/xpdf/pdftotext $path - 2>/dev/null&
+  else
+    /usr/bin/pdftotext $path - 2>/dev/null&
+  fi
   wait_timeout 2>/dev/null
 elif [ $fmt = "doc" ]; then
   (/usr/bin/catdoc $path; true) 2>/dev/null&
