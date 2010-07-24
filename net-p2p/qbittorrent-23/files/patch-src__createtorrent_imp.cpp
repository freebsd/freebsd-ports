--- src/createtorrent_imp.cpp.orig	2009-09-21 10:02:50.000000000 +0000
+++ src/createtorrent_imp.cpp	2009-09-21 10:05:18.000000000 +0000
@@ -257,7 +257,11 @@
     }
     if(abort) return;
     // calculate the hash for all pieces
+#if defined(__GNUC__) && __GNUC__ <= 3
+    set_piece_hashes(t, full_path.branch_path(), boost::bind(&sendProgressUpdateSignal, _1, t.num_pieces(), this));
+#else
     set_piece_hashes(t, full_path.branch_path(), boost::bind<void>(&sendProgressUpdateSignal, _1, t.num_pieces(), this));
+#endif
     // Set qBittorrent as creator and add user comment to
     // torrent_info structure
     t.set_creator(creator_str);
