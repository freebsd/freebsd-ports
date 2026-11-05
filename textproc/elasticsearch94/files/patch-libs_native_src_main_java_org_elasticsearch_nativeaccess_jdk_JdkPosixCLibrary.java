--- libs/native/src/main/java/org/elasticsearch/nativeaccess/jdk/JdkPosixCLibrary.java.orig	2026-10-28 20:24:18 UTC
+++ libs/native/src/main/java/org/elasticsearch/nativeaccess/jdk/JdkPosixCLibrary.java
@@ -87,8 +87,12 @@ class JdkPosixCLibrary implements PosixCLibrary {
     private static final MethodHandle fstat$mh;
     static {
         MethodHandle fstat;
+        String fstatFunc = "fstat64";
         try {
-            fstat = downcallHandleWithErrno("fstat64", FunctionDescriptor.of(JAVA_INT, JAVA_INT, ADDRESS));
+            if (System.getProperty("os.name").equals("FreeBSD")) {
+                fstatFunc = "fstat";
+            }
+            fstat = downcallHandleWithErrno(fstatFunc, FunctionDescriptor.of(JAVA_INT, JAVA_INT, ADDRESS));
         } catch (LinkageError e) {
             // Due to different sizes of the stat structure for 32 vs 64 bit machines, on some systems fstat actually points to
             // an internal symbol. So we fall back to looking for that symbol.
