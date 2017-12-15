--- scripts/build-aux/genver.sh.orig	2017-10-27 12:42:43 UTC
+++ scripts/build-aux/genver.sh
@@ -1,11 +1,11 @@
 #!/bin/sh
 
-GITDESC=$(git describe --dirty|sed -e 's/-/./g' 2>/dev/null)
+GITDESC=$(git describe --dirty 2>/dev/null | sed -e 's/-/./g')
 VERCLEAN=$(echo $GITDESC|sed -Ee 's/^.*v([0-9]+\.[0-9]+(\.[0-9]+|bp)).*$/\1/')
 
 GITDESC="$VERCLEAN-$GITDESC"
 
-if [ -z "$GITDESC" ]; then
+if [ "$GITDESC" = "-" ]; then
 	if [ -f ".version" ]; then
 		GITDESC=$(cat .version)
 	else
