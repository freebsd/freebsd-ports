--- src/net/psammead/commonist/util/Loader.java.orig	2008-06-19 23:45:43.667197457 +0200
+++ src/net/psammead/commonist/util/Loader.java	2008-06-19 23:46:41.729154606 +0200
@@ -32,7 +32,7 @@
 			File	settingsFile	= new File(settingsDir, path);
 			if (settingsFile.exists()) {
 				log.debug("loading from settings: " + path);
-				return settingsFile.toURL();
+				return settingsFile.toURI().toURL();
 			}
 		}
 		catch (MalformedURLException e) {
@@ -43,7 +43,7 @@
 			File	projectFile	= new File(projectDir, path);
 			if (projectFile.exists()) {
 				log.debug("loading from project: " + path);
-				return projectFile.toURL();
+				return projectFile.toURI().toURL();
 			}
 		}
 		catch (MalformedURLException e) {
