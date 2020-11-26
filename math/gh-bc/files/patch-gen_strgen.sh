--- gen/strgen.sh.orig	2020-11-26 16:00:16 UTC
+++ gen/strgen.sh
@@ -32,18 +32,19 @@ export LC_CTYPE=C
 
 progname=${0##*/}
 
-if [ $# -lt 4 ]; then
-	echo "usage: $progname input output name header [label [define [remove_tabs]]]"
+if [ $# -lt 3 ]; then
+	echo "usage: $progname input output name [label [define [remove_tabs]]]"
 	exit 1
 fi
 
+# gen/strgen gen/lib2.bc gen/lib2.c bc_lib2 bc_lib2_name "BC_ENABLED && BC_ENABLE_EXTRA_MATH" 1
+
 input="$1"
 output="$2"
 name="$3"
-header="$4"
-label="$5"
-define="$6"
-remove_tabs="$7"
+label="$4"
+define="$5"
+remove_tabs="$6"
 
 exec < "$input"
 exec > "$output"
