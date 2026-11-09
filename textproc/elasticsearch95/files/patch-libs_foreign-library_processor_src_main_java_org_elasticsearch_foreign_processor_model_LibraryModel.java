--- libs/foreign-library/processor/src/main/java/org/elasticsearch/foreign/processor/model/LibraryModel.java.orig	2026-10-28 21:58:41 UTC
+++ libs/foreign-library/processor/src/main/java/org/elasticsearch/foreign/processor/model/LibraryModel.java
@@ -54,6 +54,7 @@ public record LibraryModel(
         "LINUX_AARCH64",
         "DARWIN_X64",
         "DARWIN_AARCH64",
+        "FREEBSD_X64",
         "WINDOWS_X64"
     );
 
