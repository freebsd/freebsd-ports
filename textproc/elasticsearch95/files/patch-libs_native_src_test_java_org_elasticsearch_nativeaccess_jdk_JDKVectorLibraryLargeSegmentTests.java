--- libs/native/src/test/java/org/elasticsearch/nativeaccess/jdk/JDKVectorLibraryLargeSegmentTests.java.orig	2026-10-28 21:58:41 UTC
+++ libs/native/src/test/java/org/elasticsearch/nativeaccess/jdk/JDKVectorLibraryLargeSegmentTests.java
@@ -49,7 +49,7 @@ public class JDKVectorLibraryLargeSegmentTests extends
         var osName = System.getProperty("os.name");
         return jdkVersion >= 21
             && ((arch.equals("aarch64") && (osName.startsWith("Mac") || osName.equals("Linux")))
-                || (arch.equals("amd64") && osName.equals("Linux")));
+                || (arch.equals("amd64") && (osName.equals("Linux") || osName.equals("FreeBSD"))));
     }
 
     static VectorSimilarityFunctions functions;
