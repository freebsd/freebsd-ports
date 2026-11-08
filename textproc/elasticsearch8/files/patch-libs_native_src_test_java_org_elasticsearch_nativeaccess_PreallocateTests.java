--- libs/native/src/test/java/org/elasticsearch/nativeaccess/PreallocateTests.java.orig	2026-10-28 21:29:53 UTC
+++ libs/native/src/test/java/org/elasticsearch/nativeaccess/PreallocateTests.java
@@ -9,6 +9,9 @@ package org.elasticsearch.nativeaccess;
 
 package org.elasticsearch.nativeaccess;
 
+import org.elasticsearch.env.NodeEnvironment;
+import org.elasticsearch.monitor.fs.FsInfo;
+import org.elasticsearch.monitor.fs.FsProbe;
 import org.elasticsearch.test.ESTestCase;
 import org.junit.Before;
 
@@ -24,6 +27,21 @@ public class PreallocateTests extends ESTestCase {
     public void setup() {
         assumeFalse("no preallocate on windows", System.getProperty("os.name").startsWith("Windows"));
         assumeFalse("preallocate not supported on encrypted block devices", "encryption-at-rest".equals(System.getenv("BUILDKITE_LABEL")));
+
+        FsInfo.Path fsPath;
+        try {
+            fsPath = FsProbe.getFSInfo(new FakeDataPath(createTempDir()));
+            assumeFalse("Cannot preallocate on a ZFS dataset", fsPath.getType().equals("zfs"));
+        } catch (IOException e) {
+            throw new RuntimeException(e);
+        }
+    }
+
+    static class FakeDataPath extends NodeEnvironment.DataPath {
+
+        FakeDataPath(Path path) throws IOException {
+            super(path);
+        }
     }
 
     public void testPreallocate() throws IOException {
