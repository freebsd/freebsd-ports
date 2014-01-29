--- scripts/aspcud.sh.orig	2014-01-10 16:00:28.000000000 +0000
+++ scripts/aspcud.sh	2014-01-10 16:25:29.000000000 +0000
@@ -7,7 +7,7 @@
 
 function enc()
 {
-	for x in "." "$base" "$base/encodings"; do
+	for x in "@@PREFIX@@/share/aspcud"; do
 		[[ -e "$x/$1" ]] && { echo "$x/$1"; return 0; }
 	done
 	echo "$x"
@@ -27,7 +27,7 @@
 
 function usage()
 {
-	echo "Usage: ${0} [OPTION]... CUDFIN CUDFOUT [CRITERIA]"
+	echo "Usage: ${0} [OPTION]... CUDFIN CUDFOUT CRITERIA"
 	echo "  -h       print this help"
 	echo "  -c OPT   append clasp option OPT"
 	echo "  -e ENC   append encoding ENC"
@@ -135,7 +135,7 @@
 trap usrtrap USR1 TERM INT
 
 cat <<EOF > "$tmp/parse.py"
-#!/usr/bin/python
+#!/usr/bin/env python
 import signal, re, sys
 
 def ignore(x, y): pass
