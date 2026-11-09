--- x-pack/plugin/esql-datasource-parquet-rs/src/main/java/org/elasticsearch/xpack/esql/datasource/parquet/parquetrs/NativeLibLoader.java.orig	2026-10-28 21:58:41 UTC
+++ x-pack/plugin/esql-datasource-parquet-rs/src/main/java/org/elasticsearch/xpack/esql/datasource/parquet/parquetrs/NativeLibLoader.java
@@ -70,7 +70,7 @@ final class NativeLibLoader {
         String libName;
         if (os.contains("mac") || os.contains("darwin")) {
             libName = "libesql_parquet_rs.dylib";
-        } else if (os.contains("linux")) {
+        } else if (os.contains("linux") || os.contains("freebsd")) {
             libName = "libesql_parquet_rs.so";
         } else {
             throw new UnsupportedOperationException("Unsupported OS: " + os);
@@ -80,14 +80,17 @@ final class NativeLibLoader {
         if (arch.contains("aarch64") || arch.contains("arm64")) {
             platform = os.contains("mac") ? "aarch64-apple-darwin" : "aarch64-unknown-linux-gnu";
         } else if (arch.contains("amd64") || arch.contains("x86_64")) {
-            platform = os.contains("mac") ? "x86_64-apple-darwin" : "x86_64-unknown-linux-gnu";
+            platform = os.contains("mac") ? "x86_64-apple-darwin"
+                : os.contains("linux") ? "x86_64-unknown-linux-gnu"
+                : os.contains("freebsd") ? "x86_64-unknown-freebsd"
+                : "";
         } else {
             throw new UnsupportedOperationException("Unsupported architecture: " + arch);
         }
 
         InputStream resource = null;
         String resourcePath = "";
-        if (Build.current().isSnapshot()) {
+        if (Build.current().isSnapshot() || os.contains("freebsd")) {
             resourcePath = "/platform/" + libName;
             // Try a local build first
             resource = NativeLibLoader.class.getResourceAsStream(resourcePath);
