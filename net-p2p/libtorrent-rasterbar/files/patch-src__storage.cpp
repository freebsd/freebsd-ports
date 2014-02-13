--- ./src/storage.cpp.orig	2014-01-24 11:05:39.000000000 +0100
+++ ./src/storage.cpp	2014-02-13 21:33:49.000000000 +0100
@@ -1223,7 +1223,7 @@
 			// if the file has priority 0, don't allocate it
 			int file_index = files().file_index(*file_iter);
 			if (m_allocate_files && (op.mode & file::rw_mask) != file::read_only
-				&& (m_file_priority.size() < file_index || m_file_priority[file_index] > 0))
+				&& (m_file_priority.size() <= file_index || m_file_priority[file_index] > 0))
 			{
 				TORRENT_ASSERT(m_file_created.size() == files().num_files());
 				if (m_file_created[file_index] == false)
