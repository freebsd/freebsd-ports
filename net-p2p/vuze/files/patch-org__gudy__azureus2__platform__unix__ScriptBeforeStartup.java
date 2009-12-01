--- org/gudy/azureus2/platform/unix/ScriptBeforeStartup.java.orig	2009-09-20 15:37:15.000000000 -0500
+++ org/gudy/azureus2/platform/unix/ScriptBeforeStartup.java	2009-09-20 15:53:35.000000000 -0500
@@ -141,10 +141,12 @@
 						return false;
 					}
 				});
+				possibleDirs.add(new File("/usr/local/lib"));
 				possibleDirs.add(new File("/usr/local"));
 				possibleDirs.add(new File("/opt"));
 
 				final String[] possibleDirNames = {
+					"libxul",
 					"mozilla",
 					"firefox",
 					"seamonkey",
