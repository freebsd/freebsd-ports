--- build/make/rtcd.sh.orig	2012-06-24 13:12:00.000000000 +0200
+++ build/make/rtcd.sh	2012-06-24 13:13:01.000000000 +0200
@@ -1,5 +1,6 @@
 #!/bin/sh
 self=$0
+LANG=C
 
 usage() {
   cat <<EOF >&2
