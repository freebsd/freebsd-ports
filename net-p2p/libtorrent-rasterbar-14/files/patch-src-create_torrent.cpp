--- src/create_torrent.cpp.orig	2010-01-19 04:42:35.000000000 +0300
+++ src/create_torrent.cpp	2012-01-27 21:04:43.000000000 +0300
@@ -217,7 +217,7 @@
 					for (fs::path::iterator j = boost::next(i->path.begin());
 						j != i->path.end(); ++j)
 					{
-						path_e.list().push_back(entry(*j));
+                                                path_e.list().push_back(entry((*j).string()));
 					}
 				}
 			}
