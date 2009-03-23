--- src/createtorrent_imp.cpp.orig	2009-03-07 07:22:19.000000000 +0900
+++ src/createtorrent_imp.cpp	2009-03-23 02:00:49.000000000 +0900
@@ -245,7 +245,11 @@
     }
     if(abort) return;
     // calculate the hash for all pieces
+#if defined(__GNUC__) && __GNUC__ <= 3
+    set_piece_hashes(t, full_path.branch_path(), boost::bind(&sendProgressUpdateSignal, _1, t.num_pieces(), parent));
+#else
     set_piece_hashes(t, full_path.branch_path(), boost::bind<void>(&sendProgressUpdateSignal, _1, t.num_pieces(), parent));
+#endif
     // Set qBittorrent as creator and add user comment to
     // torrent_info structure
     t.set_creator(creator_str);
