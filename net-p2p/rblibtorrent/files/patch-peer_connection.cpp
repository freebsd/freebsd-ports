--- src/peer_connection.cpp.orig	Fri Dec 16 00:32:21 2005
+++ src/peer_connection.cpp	Thu Feb 23 13:07:01 2006
@@ -1011,6 +1011,7 @@
 
 		if (b != m_download_queue.end())
 		{
+/*
 			for (i = m_download_queue.begin();
 				i != b; ++i)
 			{
@@ -1023,7 +1024,7 @@
 				// be requested from other peers
 				picker.abort_download(*i);
 			}
-		
+*/
 #ifdef TORRENT_VERBOSE_LOGGING
 			(*m_logger) << to_simple_string(second_clock::universal_time())
 				<< " <== PIECE   [ piece: " << p.piece << " | "
@@ -1031,12 +1032,14 @@
 				"s: " << p.start << " | "
 				"l: " << p.length << " ]\n";
 #endif
-
+/*
 			// remove the request that just finished
 			// from the download queue plus the
 			// skipped blocks.
 			m_download_queue.erase(m_download_queue.begin()
 				, boost::next(b));
+*/
+			m_download_queue.erase(b);
 			send_block_requests();
 		}
 		else
