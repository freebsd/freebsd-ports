--- libs/core/src/main/java/org/elasticsearch/core/IOUtils.java.orig	2026-10-28 21:29:53 UTC
+++ libs/core/src/main/java/org/elasticsearch/core/IOUtils.java
@@ -259,6 +259,7 @@ public final class IOUtils {
     public static final boolean WINDOWS = System.getProperty("os.name").startsWith("Windows");
     public static final boolean LINUX = System.getProperty("os.name").startsWith("Linux");
     public static final boolean MAC_OS_X = System.getProperty("os.name").startsWith("Mac OS X");
+    public static final boolean FREEBSD = System.getProperty("os.name").startsWith("FreeBSD");
 
     /**
      * Ensure that any writes to the given file is written to the storage device that contains it. The {@code isDir} parameter specifies
@@ -299,7 +300,7 @@ public final class IOUtils {
                 file.force(metaData);
             } catch (final IOException e) {
                 if (isDir) {
-                    assert (LINUX || MAC_OS_X) == false
+                    assert (LINUX || MAC_OS_X || FREEBSD) == false
                         : "on Linux and MacOSX fsyncing a directory should not throw IOException, "
                             + "we just don't want to rely on that in production (undocumented); got: "
                             + e;
