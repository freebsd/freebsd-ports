--- third_party/closure/download.sh.orig	2017-10-07 01:47:55 UTC
+++ third_party/closure/download.sh
@@ -37,7 +37,6 @@ JAR=$DIR/compiler.jar
 # verison.
 if [[ ! -e $JAR || -z "$(java -jar $JAR --version | grep $VERSION)" ]]
 then
-  curl https://dl.google.com/closure-compiler/$ZIP --create-dirs -o $DIR/$ZIP
   unzip -o $DIR/$ZIP -d $DIR
   cp $JAR_IN $JAR
 fi
