
$FreeBSD$

Unbreak Youtube extension for streaming files from withing Banshee 1.6.1.
Taken from the git repository.

--- src/Extensions/Banshee.YouTube/Banshee.YouTube.Gui/YouTubeTile.cs.orig
+++ src/Extensions/Banshee.YouTube/Banshee.YouTube.Gui/YouTubeTile.cs
@@ -146,7 +146,7 @@
                 return null;
             }
 
-            Regex regex = new Regex ("'SWF_ARGS'.*\"t\": \"([^\"]+)\"");
+            Regex regex = new Regex ("swfHTML = .*&t=([^&]+)&");
             Match match = regex.Match (watch_page_contents);
 
             if (!match.Success) {
