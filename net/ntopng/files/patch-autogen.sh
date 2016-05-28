--- autogen.sh.orig	2016-05-05 13:23:53 UTC
+++ autogen.sh
@@ -30,8 +30,3 @@ fi
 cat configure.seed | sed "s/@VERSION@/$VERSION/g" | sed "s/@SHORT_VERSION@/$SHORT_VERSION/g" | sed "s/@GIT_TAG@/$GIT_TAG/g" | sed "s/@GIT_DATE@/$GIT_DATE/g" | sed "s/@GIT_RELEASE@/$GIT_RELEASE/g" | sed "s/@GIT_BRANCH@/$GIT_BRANCH/g"  | sed "s/@PRO_GIT_RELEASE@/$PRO_GIT_RELEASE/g" | sed "s/@PRO_GIT_DATE@/$PRO_GIT_DATE/g" > configure.ac
 
 /bin/rm -f config.h config.h.in *~ #*
-
-echo "Wait please..."
-autoreconf -if
-echo ""
-echo "Now run ./configure"
