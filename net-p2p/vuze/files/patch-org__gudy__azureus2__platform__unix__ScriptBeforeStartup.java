--- org/gudy/azureus2/platform/unix/ScriptBeforeStartup.java.orig	2008-06-03 11:25:03.000000000 -0400
+++ org/gudy/azureus2/platform/unix/ScriptBeforeStartup.java	2008-06-03 11:27:27.000000000 -0400
@@ -139,6 +139,7 @@
 						return false;
 					}
 				});
+				possibleDirs.add(new File("/usr/local/lib"));
 				possibleDirs.add(new File("/usr/local"));
 				possibleDirs.add(new File("/opt"));
 
