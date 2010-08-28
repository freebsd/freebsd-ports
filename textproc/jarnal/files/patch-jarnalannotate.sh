--- jarnalannotate.sh.orig	2009-09-02 16:04:31.000000000 +0200
+++ jarnalannotate.sh	2010-08-28 16:34:02.000000000 +0200
@@ -1,10 +1,10 @@
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
