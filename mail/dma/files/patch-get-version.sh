--- get-version.sh.orig	2016-02-07 12:41:49 UTC
+++ get-version.sh
@@ -2,10 +2,8 @@
 
 tmp=$1
 file=${tmp:=VERSION}
-gitver=$(git describe 2>/dev/null | tr - .)
 filever=$(cat ${file} 2>/dev/null)
 
-version=${gitver}
 : ${version:=$filever}
 
 echo "$version"
