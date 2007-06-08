--- src/GnomeSubtitles/Execution/Execution.cs.bak	Thu Jun  7 20:49:51 2007
+++ src/GnomeSubtitles/Execution/Execution.cs	Thu Jun  7 20:51:10 2007
@@ -97,8 +97,7 @@
 	public string SystemHelpDir {
 		get {
 			return Path.Combine(SystemShareDir,
-				Path.Combine("gnome",
-				Path.Combine("help", applicationID)));
+				Path.Combine("help", applicationID));
 		}
 	}
 	
