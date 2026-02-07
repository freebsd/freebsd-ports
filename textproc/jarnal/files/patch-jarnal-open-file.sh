--- jarnal-open-file.sh.orig	2014-02-20 07:10:52.000000000 +0100
+++ jarnal-open-file.sh	2014-04-28 21:58:13.000000000 +0200
@@ -1,19 +1,20 @@
-#! /bin/bash
+#! /bin/sh
 
-SOURCE=$0
-echo $SOURCE
-while [ -h "$SOURCE" ]; do
- DIR="$( cd -P "$( dirname "$SOURCE" )" && pwd )"
- SOURCE="$(readlink "$SOURCE")"
- [[ $SOURCE != /* ]] && SOURCE="$DIR/$SOURCE"
-done
-DIR="$( cd -P "$( dirname "$SOURCE" )" && pwd )"
-cd $DIR 
+#SOURCE=$0
+#echo $SOURCE
+#while [ -h "$SOURCE" ]; do
+# DIR="$( cd -P "$( dirname "$SOURCE" )" && pwd )"
+# SOURCE="$(readlink "$SOURCE")"
+# [[ $SOURCE != /* ]] && SOURCE="$DIR/$SOURCE"
+#done
+#DIR="$( cd -P "$( dirname "$SOURCE" )" && pwd )"
+#cd $DIR
+cd %%JAVAJARDIR%%
 
 if [ -d upgrade-lib ]; then
 	cp -fr lib old-lib
 	cp -fr upgrade-lib lib
-	rm -fr upgrade-lib 
+	rm -fr upgrade-lib
 fi
 if [ -f upgrade-jarnal.jar ]; then
 	cp -f jarnal.jar old-jarnal.jar
