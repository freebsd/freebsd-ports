--- tools/mockup.sh.orig	2019-12-13 15:40:41 UTC
+++ tools/mockup.sh
@@ -6,8 +6,13 @@ if [ $# -eq 0 ]; then
     set -- $(while read -r LINE; do
 	case "$LINE" in
 	    *undefined\ reference\ to*)
+		# file.cc:(.text+0x10): undefined reference to `foo()'
 		LINE=${LINE#*undefined reference to \`}
 		echo "${LINE%\'*}"
+		;;
+	    *undefined\ symbol:*)
+		# ld: error: undefined symbol: foo()
+		echo "${LINE#*undefined symbol: }"
 		;;
 	    *)
 		continue
