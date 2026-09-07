--- src/java/module-info.java.orig	2026-09-07 19:40:35 UTC
+++ src/java/module-info.java
@@ -5,4 +5,5 @@ module org.tanukisoftware.wrapper {
     exports org.tanukisoftware.wrapper.security;
 
     requires static java.management;
+    requires java.logging;
 }
