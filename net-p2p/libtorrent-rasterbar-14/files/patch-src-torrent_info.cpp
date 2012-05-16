--- src/torrent_info.cpp.orig	2012-01-27 20:42:54.000000000 +0300
+++ src/torrent_info.cpp	2012-01-27 20:44:06.000000000 +0300
@@ -199,7 +199,7 @@
 		fs::path new_path;
 		for (fs::path::const_iterator i = p.begin(); i != p.end(); ++i)
 		{
-			if (!valid_path_element(*i)) continue;
+                        if (!valid_path_element((*i).string())) continue;
 			new_path /= *i;
 		}
 		TORRENT_ASSERT(!new_path.is_complete());
