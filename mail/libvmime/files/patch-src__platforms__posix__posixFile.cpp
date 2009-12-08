--- ./src/platforms/posix/posixFile.cpp.orig	2008-10-12 02:42:23.000000000 -0700
+++ ./src/platforms/posix/posixFile.cpp	2009-12-08 09:48:30.536227969 -0800
@@ -166,7 +166,7 @@
 	if ((c = ::read(m_fd, data, count)) == -1)
 		posixFileSystemFactory::reportError(m_path, errno);
 
-	if (c == 0)
+	if (c == 0 && count != 0)
 		m_eof = true;
 
 	return static_cast <size_type>(c);
