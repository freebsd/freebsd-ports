--- src/Core/Banshee.Core/Banshee.Collection/TrackInfo.cs.orig	2008-09-11 09:01:14.000000000 +0800
+++ src/Core/Banshee.Core/Banshee.Collection/TrackInfo.cs	2008-09-11 09:14:56.000000000 +0800
@@ -356,17 +356,17 @@
             
             // Properties specified by the XMMS2 player spec
             dict.Add ("URI", Uri == null ? String.Empty : Uri.AbsoluteUri);
-            dict.Add ("length", Duration.TotalSeconds);
-            dict.Add ("name", TrackTitle);
-            dict.Add ("artist", ArtistName);
-            dict.Add ("album", AlbumTitle);
+            dict.Add ("length", Duration == null ? 0 : Duration.TotalSeconds);
+            dict.Add ("name", TrackTitle == null ? String.Empty : TrackTitle);
+            dict.Add ("artist", ArtistName == null ? String.Empty : ArtistName);
+            dict.Add ("album", AlbumTitle == null ? String.Empty : AlbumTitle);
             
             // Our own
-            dict.Add ("track-number", TrackNumber);
-            dict.Add ("track-count", TrackCount);
-            dict.Add ("disc", Disc);
-            dict.Add ("year", year);
-            dict.Add ("rating", rating);
+            dict.Add ("track-number", TrackNumber == null ? 0 : TrackNumber);
+            dict.Add ("track-count", TrackCount == null ? 0 : TrackCount);
+            dict.Add ("disc", Disc == null ? 0 : Disc);
+            dict.Add ("year", year == null ? 0 : year);
+            dict.Add ("rating", rating == null ? 0 : rating);
             
             return dict;
         }
