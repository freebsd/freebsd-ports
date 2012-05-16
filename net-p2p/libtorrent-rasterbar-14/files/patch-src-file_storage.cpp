--- src/file_storage.cpp.orig	2012-01-27 20:52:46.000000000 +0300
+++ src/file_storage.cpp	2012-01-27 20:54:50.000000000 +0300
@@ -147,9 +147,9 @@
 		else
 		{
 			if (m_files.empty())
-				m_name = *file.begin();
+                                m_name = (*file.begin()).string();
 		}
-		TORRENT_ASSERT(m_name == *file.begin());
+		TORRENT_ASSERT(m_name == (*file.begin()).string());
 		file_entry e;
 		m_files.push_back(e);
 		m_files.back().size = size;
