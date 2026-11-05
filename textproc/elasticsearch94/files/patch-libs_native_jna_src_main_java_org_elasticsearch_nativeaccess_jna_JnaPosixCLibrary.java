--- libs/native/jna/src/main/java/org/elasticsearch/nativeaccess/jna/JnaPosixCLibrary.java.orig	2026-10-28 21:29:53 UTC
+++ libs/native/jna/src/main/java/org/elasticsearch/nativeaccess/jna/JnaPosixCLibrary.java
@@ -161,12 +161,16 @@ class JnaPosixCLibrary implements PosixCLibrary {
     JnaPosixCLibrary() {
         this.functions = Native.load("c", NativeFunctions.class);
         FStat64Function fstat64;
+        String fstatFunc = "fstat64";
         try {
+            if (System.getProperty("os.name").equals("FreeBSD")) {
+                fstatFunc = "fstat";
+            }
             // JNA lazily finds symbols, so even though we try to bind two different functions below, if fstat64
             // isn't found, we won't know until runtime when calling the function. To force resolution of the
             // symbol we get a function object directly from the native library. We don't use it, we just want to
             // see if it will throw UnsatisfiedLinkError
-            NativeLibrary.getInstance("c").getFunction("fstat64");
+            NativeLibrary.getInstance("c").getFunction(fstatFunc);
             fstat64 = Native.load("c", FStat64Function.class);
         } catch (UnsatisfiedLinkError e) {
             // fstat has a long history in linux from the 32-bit architecture days. On some modern linux systems,
