--- org/gudy/azureus2/platform/unix/ScriptBeforeStartup.java.orig	2007-10-13 16:57:39.000000000 -0400
+++ org/gudy/azureus2/platform/unix/ScriptBeforeStartup.java	2007-10-13 16:58:03.000000000 -0400
@@ -136,6 +136,7 @@
 						return false;
 					}
 				});
+				possibleDirs.add(new File("/usr/local/lib"));
 				possibleDirs.add(new File("/usr/local"));
 				possibleDirs.add(new File("/opt"));
 
