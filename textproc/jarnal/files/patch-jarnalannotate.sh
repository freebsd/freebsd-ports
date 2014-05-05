--- jarnalannotate.sh.orig	2013-05-01 23:14:48.000000000 +0200
+++ jarnalannotate.sh	2014-04-28 21:48:45.000000000 +0200
@@ -1,23 +1,24 @@
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
 	cp -f upgrade-jarnal.jar jarnal.jar
 	rm -f upgrade-jarnal.jar
 fi
-java -Dfile.encoding=UTF-8 -Xmx192m -jar jarnal.jar -t templates/annotate.jaj -b "$1" "$2" "$3" "$4" "$5"
+java -Dfile.encoding=UTF-8 -Xmx192m -jar jarnal.jar -t %%DATADIR%%/templates/annotate.jaj -b "$1" "$2" "$3" "$4" "$5"
