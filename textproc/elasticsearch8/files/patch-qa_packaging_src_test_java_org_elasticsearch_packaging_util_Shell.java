--- qa/packaging/src/test/java/org/elasticsearch/packaging/util/Shell.java.orig	2026-10-28 21:29:53 UTC
+++ qa/packaging/src/test/java/org/elasticsearch/packaging/util/Shell.java
@@ -88,6 +88,7 @@ public class Shell {
     public void chown(Path path, String newOwner) throws Exception {
         logger.info("Chowning " + path + " to " + newOwner);
         Platforms.onLinux(() -> run("chown -R elasticsearch:elasticsearch " + path));
+        Platforms.onFreeBSD(() -> run("chown -R elasticsearch:elasticsearch " + path));
         Platforms.onWindows(() -> run(String.format(Locale.ROOT, """
             $account = New-Object System.Security.Principal.NTAccount '%s';
             $pathInfo = Get-Item '%s';
@@ -105,6 +106,7 @@ public class Shell {
 
     public void extractZip(Path zipPath, Path destinationDir) throws Exception {
         Platforms.onLinux(() -> run("unzip \"" + zipPath + "\" -d \"" + destinationDir + "\""));
+        Platforms.onFreeBSD(() -> run("unzip -d \"" + destinationDir + "\" \"" + zipPath + "\""));
         Platforms.onWindows(() -> run("Expand-Archive -Path \"" + zipPath + "\" -DestinationPath \"" + destinationDir + "\""));
     }
 
