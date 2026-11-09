--- qa/packaging/src/test/java/org/elasticsearch/packaging/test/PackagingTestCase.java.orig	2026-10-28 21:29:53 UTC
+++ qa/packaging/src/test/java/org/elasticsearch/packaging/test/PackagingTestCase.java
@@ -129,7 +129,7 @@ public abstract class PackagingTestCase extends Assert
         if (Platforms.WINDOWS) {
             systemJavaHome = initShell.run("$Env:SYSTEM_JAVA_HOME").stdout().trim();
         } else {
-            assert Platforms.LINUX || Platforms.DARWIN;
+            assert Platforms.LINUX || Platforms.DARWIN || Platforms.FREEBSD;
             systemJavaHome = initShell.run("echo $SYSTEM_JAVA_HOME").stdout().trim();
         }
     }
@@ -194,6 +194,7 @@ public abstract class PackagingTestCase extends Assert
         sh.reset();
         if (distribution().hasJdk == false) {
             Platforms.onLinux(() -> sh.getEnv().put("ES_JAVA_HOME", systemJavaHome));
+            Platforms.onFreeBSD(() -> sh.getEnv().put("ES_JAVA_HOME", systemJavaHome));
             Platforms.onWindows(() -> sh.getEnv().put("ES_JAVA_HOME", systemJavaHome));
         }
         if (installation != null
