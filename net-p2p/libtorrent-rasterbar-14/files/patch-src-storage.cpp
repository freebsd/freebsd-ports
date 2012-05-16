--- src/storage.cpp.orig	2010-09-06 03:59:03.000000000 +0400
+++ src/storage.cpp	2012-01-27 20:39:22.000000000 +0300
@@ -161,7 +161,7 @@
 	template <class Path>
 	void recursive_copy(Path const& old_path, Path const& new_path, error_code& ec)
 	{
-		using boost::filesystem::basic_directory_iterator;
+		using boost::filesystem::directory_iterator;
 #ifndef BOOST_NO_EXCEPTIONS
 		try {
 #endif
@@ -169,7 +169,7 @@
 		if (is_directory(old_path))
 		{
 			create_directory(new_path);
-			for (basic_directory_iterator<Path> i(old_path), end; i != end; ++i)
+			for (directory_iterator i(old_path), end; i != end; ++i)
 			{
 #if BOOST_VERSION < 103600
 				recursive_copy(i->path(), new_path / i->path().leaf(), ec);
@@ -202,13 +202,13 @@
 	template <class Path>
 	void recursive_remove(Path const& old_path)
 	{
-		using boost::filesystem::basic_directory_iterator;
+		using boost::filesystem::directory_iterator;
 #ifndef BOOST_NO_EXCEPTIONS
 		try {
 #endif
 		if (is_directory(old_path))
 		{
-			for (basic_directory_iterator<Path> i(old_path), end; i != end; ++i)
+			for (directory_iterator i(old_path), end; i != end; ++i)
 				recursive_remove(i->path());
 			remove(old_path);
 		}
@@ -301,7 +301,7 @@
 				|| (!compact_mode && size < s->first))
 			{
 				if (error) *error = "filesize mismatch for file '"
-					+ i->path.external_file_string()
+					+ i->path.native()
 					+ "', size: " + boost::lexical_cast<std::string>(size)
 					+ ", expected to be " + boost::lexical_cast<std::string>(s->first)
 					+ " bytes";
@@ -314,7 +314,7 @@
 				(!compact_mode && (time > s->second + 5 * 60 || time < s->second - 1)))
 			{
 				if (error) *error = "timestamp mismatch for file '"
-					+ i->path.external_file_string()
+					+ i->path.native()
 					+ "', modification date: " + boost::lexical_cast<std::string>(time)
 					+ ", expected to have modification date "
 					+ boost::lexical_cast<std::string>(s->second);
@@ -334,7 +334,7 @@
 			if (mapped) m_mapped_files.reset(new file_storage(*mapped));
 
 			TORRENT_ASSERT(m_files.begin() != m_files.end());
-			m_save_path = fs::complete(path);
+			m_save_path = fs::absolute(path);
 			TORRENT_ASSERT(m_save_path.is_complete());
 		}
 
@@ -781,7 +781,7 @@
 			{
 				if (i->size != fs->first)
 				{
-					error = "file size for '" + i->path.external_file_string()
+					error = "file size for '" + i->path.native()
 						+ "' was expected to be "
 						+ boost::lexical_cast<std::string>(i->size) + " bytes";
 					return false;
@@ -828,7 +828,7 @@
 		for (file_storage::iterator i = f.begin()
 			, end(f.end()); i != end; ++i)
 		{
-			to_move.insert(to_move.begin(), *i->path.begin());
+                        to_move.insert(to_move.begin(), (*i->path.begin()).string());
 		}
 
 		for (std::set<std::string>::const_iterator i = to_move.begin()
@@ -1461,7 +1461,7 @@
 	{
 		if (m_storage->move_storage(save_path))
 		{
-			m_save_path = fs::complete(save_path);
+			m_save_path = fs::absolute(save_path);
 			return 0;
 		}
 		return -1;
