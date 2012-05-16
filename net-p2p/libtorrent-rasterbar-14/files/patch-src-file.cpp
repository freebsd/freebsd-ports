--- src/file.cpp.orig	2012-01-27 20:46:48.000000000 +0300
+++ src/file.cpp	2012-01-27 20:47:10.000000000 +0300
@@ -207,7 +207,7 @@
 			| S_IRGRP | S_IWGRP
 			| S_IROTH | S_IWOTH;
 
-		m_fd = ::open(path.external_file_string().c_str()
+		m_fd = ::open(path.native().c_str()
 			, map_open_mode(mode.m_mask), permissions);
 
 		if (m_fd == -1)
