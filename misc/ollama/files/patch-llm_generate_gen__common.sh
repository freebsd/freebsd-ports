--- llm/generate/gen_common.sh.orig	1979-11-30 08:00:00 UTC
+++ llm/generate/gen_common.sh
@@ -68,13 +68,8 @@ apply_patches() {
     if [ -n "$(ls -A ../patches/*.diff)" ]; then
         # apply temporary patches until fix is upstream
         for patch in ../patches/*.diff; do
-            for file in $(grep "^+++ " ${patch} | cut -f2 -d' ' | cut -f2- -d/); do
-                (cd ${LLAMACPP_DIR}; git checkout ${file})
-            done
+            (cd ${LLAMACPP_DIR} && patch -B '' -p1 < ${patch})
         done
-        for patch in ../patches/*.diff; do
-            (cd ${LLAMACPP_DIR} && git apply ${patch})
-        done
     fi
 }
 
@@ -106,14 +101,8 @@ compress() {
 }
 
 # Keep the local tree clean after we're done with the build
-cleanup() {
-    (cd ${LLAMACPP_DIR}/ && git checkout CMakeLists.txt)
 
-    if [ -n "$(ls -A ../patches/*.diff)" ]; then
-        for patch in ../patches/*.diff; do
-            for file in $(grep "^+++ " ${patch} | cut -f2 -d' ' | cut -f2- -d/); do
-                (cd ${LLAMACPP_DIR}; git checkout ${file})
-            done
-        done
-    fi
+cleanup() {
+    echo "cleanup done"
 }
+
