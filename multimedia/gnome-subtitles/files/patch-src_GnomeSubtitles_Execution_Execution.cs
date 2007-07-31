--- src/GnomeSubtitles/Execution/Execution.cs.orig	Thu Jun 21 22:53:01 2007
+++ src/GnomeSubtitles/Execution/Execution.cs	Thu Jul 12 17:32:18 2007
@@ -107,8 +107,7 @@
 				return path;
 			else {
 				return Path.Combine(SystemShareDir,
-							Path.Combine("gnome",
-							Path.Combine("help", applicationID)));
+							Path.Combine("help", applicationID));
 			}
 		}
 	}
