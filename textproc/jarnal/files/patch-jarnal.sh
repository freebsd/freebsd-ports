--- jarnal.sh.orig	2009-09-02 15:02:32.000000000 +0200
+++ jarnal.sh	2010-08-28 15:46:31.000000000 +0200
@@ -1,14 +1,14 @@
-#! /bin/bash
+#! /bin/sh
 
-cd `dirname $0`
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
-java -Dfile.encoding=UTF-8 -Xmx192m -jar jarnal.jar -t templates/default.jaj "$1" "$2" "$3" "$4" "$5"
+java -Dfile.encoding=UTF-8 -Xmx192m -jar jarnal.jar -t %%DATADIR%%/templates/default.jaj "$1" "$2" "$3" "$4" "$5"
