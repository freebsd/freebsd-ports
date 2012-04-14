--- get-version.sh.orig	2012-03-08 17:37:54.000000000 +0000
+++ get-version.sh	2012-03-08 17:38:41.000000000 +0000
@@ -1,9 +1,7 @@
 #!/bin/sh
 
-gitver=$(git describe 2>/dev/null | tr - .)
 filever=$(cat VERSION)
 
-version=${gitver}
 : ${version:=$filever}
 
 echo "$version"
