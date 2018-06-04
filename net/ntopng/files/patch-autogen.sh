--- autogen.sh.orig	2018-06-04 09:56:33 UTC
+++ autogen.sh
@@ -38,8 +38,3 @@ cat configure.seed | sed \
     > configure.ac
 
 rm -f config.h config.h.in *~ #*
-
-echo "Wait please..."
-autoreconf -if
-echo ""
-echo "Now run ./configure"
