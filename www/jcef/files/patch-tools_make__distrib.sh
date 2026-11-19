--- tools/make_distrib.sh.orig	2026-11-20 17:47:28 UTC
+++ tools/make_distrib.sh
@@ -61,21 +61,27 @@ else
       echo "ERROR: Native Release build output path does not exist"
       exit 1
     fi
-  
+
     # Create the JCEF JAR file.
     "${DIR}"/tools/make_jar.sh $1
 
-    # Copy JAR files to the bin directory.
-    cp -f "$JOGAMP_JAR_PATH"/gluegen-rt.jar "$DISTRIB_BIN_PATH"
-    cp -f "$JOGAMP_JAR_PATH"/jogl-all.jar "$DISTRIB_BIN_PATH"
+    # FreeBSD sets CLASSPATH to its jars
+    if [ $1 != "freebsd" ]; then
+      # Copy JAR files to the bin directory.
+      cp -f "$JOGAMP_JAR_PATH"/gluegen-rt.jar "$DISTRIB_BIN_PATH"
+      cp -f "$JOGAMP_JAR_PATH"/jogl-all.jar "$DISTRIB_BIN_PATH"
+    fi
 
     if [ $1 == "linux32" ]; then
       JOGAMP_JAR_SUFFIX="i586"
     else
       JOGAMP_JAR_SUFFIX="amd64"
     fi
-    cp -f "$JOGAMP_JAR_PATH"/gluegen-rt-natives-linux-$JOGAMP_JAR_SUFFIX.jar "$DISTRIB_BIN_PATH"
-    cp -f "$JOGAMP_JAR_PATH"/jogl-all-natives-linux-$JOGAMP_JAR_SUFFIX.jar "$DISTRIB_BIN_PATH"
+    # FreeBSD sets CLASSPATH to its jars
+    if [ $1 != "freebsd" ]; then
+      cp -f "$JOGAMP_JAR_PATH"/gluegen-rt-natives-linux-$JOGAMP_JAR_SUFFIX.jar "$DISTRIB_BIN_PATH"
+      cp -f "$JOGAMP_JAR_PATH"/jogl-all-natives-linux-$JOGAMP_JAR_SUFFIX.jar "$DISTRIB_BIN_PATH"
+    fi
     cp -f "$OUT_PATH"/$1/jcef.jar "$DISTRIB_BIN_PATH"
 
     # Copy test program source and JAR file to the bin directory.
@@ -87,20 +93,23 @@ else
       mkdir -p "$DISTRIB_LIB_PATH"
     fi
 
-    cp -f "$OUT_BINARY_PATH"/chrome-sandbox "$DISTRIB_LIB_PATH"
+    # FreeBSD sets USE_SANDBOX to Off
+    if [ $1 != "freebsd" ]; then
+      cp -f "$OUT_BINARY_PATH"/chrome-sandbox "$DISTRIB_LIB_PATH"
+      cp -f "$OUT_BINARY_PATH"/snapshot_blob.bin "$DISTRIB_LIB_PATH"
+    fi
     cp -f "$OUT_BINARY_PATH"/libjcef.so "$DISTRIB_LIB_PATH"
     cp -f "$OUT_BINARY_PATH"/jcef_helper "$DISTRIB_LIB_PATH"
     cp -f "$OUT_BINARY_PATH"/icudtl.dat "$DISTRIB_LIB_PATH"
     cp -f "$OUT_BINARY_PATH"/libcef.so "$DISTRIB_LIB_PATH"
     cp -f "$OUT_BINARY_PATH"/libEGL.so "$DISTRIB_LIB_PATH"
     cp -f "$OUT_BINARY_PATH"/libGLESv2.so "$DISTRIB_LIB_PATH"
-    cp -f "$OUT_BINARY_PATH"/snapshot_blob.bin "$DISTRIB_LIB_PATH"
     cp -f "$OUT_BINARY_PATH"/v8_context_snapshot.bin "$DISTRIB_LIB_PATH"
     cp -f "$OUT_BINARY_PATH"/*.pak "$DISTRIB_LIB_PATH"
     cp -rf "$OUT_BINARY_PATH"/locales/ "$DISTRIB_LIB_PATH"
     cp -f "$OUT_BINARY_PATH"/libvk_swiftshader.so "$DISTRIB_LIB_PATH"
     cp -f "$OUT_BINARY_PATH"/vk_swiftshader_icd.json "$DISTRIB_LIB_PATH"
-    cp -f "$OUT_BINARY_PATH"/libvulkan.so.1 "$DISTRIB_LIB_PATH"
+    cp -f "$OUT_BINARY_PATH"/libvulkan.so "$DISTRIB_LIB_PATH"
   fi
 fi
 
