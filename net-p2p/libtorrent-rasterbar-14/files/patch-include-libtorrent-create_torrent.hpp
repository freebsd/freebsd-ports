--- include/libtorrent/create_torrent.hpp.orig	2012-01-27 21:05:27.000000000 +0300
+++ include/libtorrent/create_torrent.hpp	2012-01-27 21:05:56.000000000 +0300
@@ -152,7 +152,7 @@
 #if BOOST_VERSION < 103600
 					std::string leaf = i->path().leaf();
 #else
-					std::string leaf = i->path().filename();
+					std::string leaf = i->path().filename().string();
 #endif
 					if (leaf == ".." || leaf == ".") continue;
 					add_files_impl(fs, p, l / leaf, pred);
