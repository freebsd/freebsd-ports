--- doc/generate-settings.sh.orig	2019-09-25 00:51:22 UTC
+++ doc/generate-settings.sh
@@ -33,13 +33,13 @@ grep -e "^{" ../src/docsis_symtable.h \
 	| grep -v "*" \
 	| grep -v "decode_md5" \
 	| awk '{print $5 "_" $3 " " $7 " " $8 " " $9}' \
-	| sed 's/\"//g' \
+	| sed 's/"//g' \
 	| sed 's/^0,_//g' \
 	| sed 's/^[0-9]*,_/\&nbsp\;\&nbsp\;\&nbsp\;\&nbsp\;/g' \
-	| sed 's/\decode_//g' \
-	| sed 's/\ //g' | tr -s "\(\)" "%%" \
+	| sed 's/decode_//g' \
+	| sed 's/ //g' | tr -s "\(\)" "%%" \
 	| sed 's/^/<tr><td><b>/g' \
-	| sed 's/,\%/<\/b><\/td><td>/g' \
+	| sed 's/,%/<\/b><\/td><td>/g' \
 	| sed 's/%,/<\/td><td>/g' \
 	| sed 's/,/-/g' \
 	| sed 's/$/<\/td><\/tr>/g'\
