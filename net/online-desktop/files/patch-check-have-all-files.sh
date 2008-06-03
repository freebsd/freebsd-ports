--- check-have-all-files.sh.orig	2008-04-23 23:06:43.000000000 +0530
+++ check-have-all-files.sh	2008-05-28 11:50:41.000000000 +0530
@@ -1,4 +1,4 @@
-#! /bin/bash
+#! /bin/sh
 
 set -e
 
@@ -12,8 +12,8 @@
 
 FILES_WE_SHOULD_HAVE=`(cd $SRCDIR && echo $GLOB_WE_SHOULD_HAVE)`
 
-FILES_WE_SHOULD_HAVE=`echo $FILES_WE_SHOULD_HAVE | sed -e 's/ /\n/g' | sort | uniq`
-FILES_WE_HAVE=`echo $FILES_WE_HAVE | sed -e 's/ /\n/g' | sort | uniq`
+FILES_WE_SHOULD_HAVE=`echo $FILES_WE_SHOULD_HAVE | sed -e 'y/ /\n/' | sort | uniq`
+FILES_WE_HAVE=`echo $FILES_WE_HAVE | sed -e 'y/ /\n/' | sort | uniq`
 
 #echo "we have files: $FILES_WE_HAVE"
 #echo "we should have files: $FILES_WE_SHOULD_HAVE"
