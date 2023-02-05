--- gen/strgen.sh.orig	2023-02-02 08:17:32 UTC
+++ gen/strgen.sh
@@ -62,7 +62,6 @@ remove_tabs="$7"
 label="$5"
 define="$6"
 remove_tabs="$7"
-check_bool_arg "$remove_tabs"
 
 tmpinput=$(mktemp -t "${input##*/}_XXXXXX")
 
