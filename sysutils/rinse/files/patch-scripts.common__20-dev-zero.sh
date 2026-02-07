--- scripts.common/20-dev-zero.sh~
+++ scripts.common/20-dev-zero.sh
@@ -30,15 +30,19 @@ fi
 #
 #  Create the node
 #
+if [ !  -e "${prefix}/dev/null" ]; then
+    mount -t devfs none "${prefix}/dev"
+    devfs -m "${prefix}/dev" rule apply hide
+    devfs -m "${prefix}/dev" rule apply path null unhide
+fi
+
 if [ !  -e "${prefix}/dev/zero" ]; then
-    mknod -m 666 "${prefix}/dev/zero" c 1 5
+    devfs -m "${prefix}/dev" rule apply path zero unhide
 fi
 
 if [ !  -e "${prefix}/dev/random" ]; then
-    mknod -m 666 "${prefix}/dev/random" c 1 8
-    chown root:root "${prefix}/dev/random"
+    devfs -m "${prefix}/dev" rule apply path random unhide
 fi
 if [ !  -e "${prefix}/dev/urandom" ]; then
-    mknod -m 666 "${prefix}/dev/urandom" c 1 9
-    chown root:root "${prefix}/dev/urandom"
+    devfs -m "${prefix}/dev" rule apply path urandom unhide
 fi
