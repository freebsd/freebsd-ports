--- org/gudy/azureus2/platform/unix/ScriptBeforeStartup.java.orig	2007-12-06 16:43:38.000000000 +0100
+++ org/gudy/azureus2/platform/unix/ScriptBeforeStartup.java	2008-05-30 16:21:32.000000000 +0200
@@ -139,6 +139,7 @@
 						return false;
 					}
 				});
+				possibleDirs.add(new File("/usr/local/lib"));
 				possibleDirs.add(new File("/usr/local"));
 				possibleDirs.add(new File("/opt"));
 
