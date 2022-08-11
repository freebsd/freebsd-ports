--- src/libbluray/bdj/java/java/io/BDFileSystem.java.orig	2022-03-03 17:05:27 UTC
+++ src/libbluray/bdj/java/java/io/BDFileSystem.java
@@ -227,6 +227,17 @@ public abstract class BDFileSystem extends FileSystem 
         return fs.isAbsolute(f);
     }
 
+    public boolean isInvalid(File f) {
+        try {
+            Method m = fs.getClass().getDeclaredMethod("isInvalid", new Class[] { File.class });
+            Object[] args = new Object[] {(Object)f};
+            Boolean result = (Boolean)m.invoke(fs, args);
+            return result.booleanValue();
+        } finally {
+            return false;
+        }
+    }
+
     public String resolve(File f) {
         if (!booted)
             return fs.resolve(f);
