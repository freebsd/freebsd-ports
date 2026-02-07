/usr gets changed to ${LOCALBASE} in post-patch:, so we
cheat and set xpdf's path to /usr/lib.

--- src/plugins/fts/decode2text.sh.orig	2017-10-28 12:21:20 UTC
+++ src/plugins/fts/decode2text.sh
@@ -79,16 +79,20 @@ wait_timeout() {
 LANG=en_US.UTF-8
 export LANG
 if [ $fmt = "pdf" ]; then
-  /usr/bin/pdftotext $path - 2>/dev/null&
+  if [ -x /usr/lib/xpdf/pdftotext ]; then
+    /usr/lib/xpdf/pdftotext $path - 2>/dev/null&
+  else
+    /usr/local/bin/pdftotext $path - 2>/dev/null&
+  fi
   wait_timeout 2>/dev/null
 elif [ $fmt = "doc" ]; then
-  (/usr/bin/catdoc $path; true) 2>/dev/null&
+  (/usr/local/bin/catdoc $path; true) 2>/dev/null&
   wait_timeout 2>/dev/null
 elif [ $fmt = "ppt" ]; then
-  (/usr/bin/catppt $path; true) 2>/dev/null&
+  (/usr/local/bin/catppt $path; true) 2>/dev/null&
   wait_timeout 2>/dev/null
 elif [ $fmt = "xls" ]; then
-  (/usr/bin/xls2csv $path; true) 2>/dev/null&
+  (/usr/local/bin/xls2csv $path; true) 2>/dev/null&
   wait_timeout 2>/dev/null
 elif [ $fmt = "odt" -o $fmt = "ods" -o $fmt = "odp" ]; then
   xmlunzip "content.xml"
