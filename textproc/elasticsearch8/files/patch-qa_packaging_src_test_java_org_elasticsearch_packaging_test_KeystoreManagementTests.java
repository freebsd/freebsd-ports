--- qa/packaging/src/test/java/org/elasticsearch/packaging/test/KeystoreManagementTests.java.orig	2026-10-28 21:29:53 UTC
+++ qa/packaging/src/test/java/org/elasticsearch/packaging/test/KeystoreManagementTests.java
@@ -433,6 +433,7 @@ public class KeystoreManagementTests extends Packaging
 
         // set the password by passing it to stdin twice
         Platforms.onLinux(() -> bin.keystoreTool.run("passwd", password + "\n" + password + "\n"));
+        Platforms.onFreeBSD(() -> bin.keystoreTool.run("passwd", password + "\n" + password + "\n"));
 
         Platforms.onWindows(
             () -> sh.run("Invoke-Command -ScriptBlock {echo '" + password + "'; echo '" + password + "'} | " + bin.keystoreTool + " passwd")
