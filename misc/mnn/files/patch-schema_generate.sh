--- schema/generate.sh.orig	2020-09-20 17:43:01 UTC
+++ schema/generate.sh
@@ -9,7 +9,7 @@ if [[ "$1" == "-lazy" ]] && [[ -d current ]]; then
 fi
 
 # check is flatbuffer installed or not
-FLATC=../3rd_party/flatbuffers/tmp/flatc
+FLATC=${FREEBSD_FLATC}
 if [ ! -e $FLATC ]; then
   echo "*** building flatc ***"
 
@@ -39,7 +39,7 @@ rm -f current/*.h
 # flatc all fbs
 pushd current > /dev/null
 echo "*** generating fbs under $DIR ***"
-find ../$DIR/*.fbs | xargs ../$FLATC -c -b --gen-object-api --reflect-names
+find ../$DIR/*.fbs | xargs $FLATC -c -b --gen-object-api --reflect-names
 popd > /dev/null
 
 # finish
