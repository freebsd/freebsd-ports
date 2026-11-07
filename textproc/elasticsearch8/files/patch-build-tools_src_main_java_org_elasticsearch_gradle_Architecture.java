--- build-tools/src/main/java/org/elasticsearch/gradle/Architecture.java.orig	2026-10-28 21:29:53 UTC
+++ build-tools/src/main/java/org/elasticsearch/gradle/Architecture.java
@@ -40,7 +40,13 @@
         return switch (architecture) {
             case "amd64", "x86_64" -> X64;
             case "aarch64" -> AARCH64;
-            default -> throw new IllegalArgumentException("can not determine architecture from [" + architecture + "]");
+            default -> {
+                // the FreeBSD distribution is architecture-neutral
+                if (OS.current() == OS.FREEBSD) {
+                    yield X64;
+                }
+                throw new IllegalArgumentException("can not determine architecture from [" + architecture + "]");
+            }
         };
     }
 
