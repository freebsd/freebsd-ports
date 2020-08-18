--- vendor/source/igraph/bootstrap.sh.orig	2020-08-17 08:48:54 UTC
+++ vendor/source/igraph/bootstrap.sh
@@ -4,7 +4,7 @@ cd "`dirname $0`"
 
 ## Find out our version number, need git for this
 printf "Finding out version number/string... "
-tools/getversion.sh > IGRAPH_VERSION
+#tools/getversion.sh > IGRAPH_VERSION
 cat IGRAPH_VERSION
 
 for i in glibtoolize libtoolize; do
