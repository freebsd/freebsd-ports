--- src/support/fs_extras.cpp.orig	2007-05-29 02:27:45.000000000 +0400
+++ src/support/fs_extras.cpp	2009-03-23 17:40:47.000000000 +0300
@@ -97,10 +97,10 @@
 	int const infile = ::open(source.string().c_str(), O_RDONLY);
 	if (infile == -1) {
 		boost::throw_exception(
-			filesystem_path_error(
+			basic_filesystem_error<path>(
 				"boost::filesystem::copy_file",
 				source, target,
-				fs::lookup_errno(errno)));
+				boost::system::error_code(errno, boost::system::get_system_category())));
 	}
 
 		struct stat source_stat;
@@ -108,10 +108,10 @@
 		if (ret == -1) {
 		int err = errno;
 		::close(infile);
-		boost::throw_exception(filesystem_path_error(
+		boost::throw_exception(basic_filesystem_error<path>(
 			   "boost::filesystem::copy_file",
 			   source, target,
-			   fs::lookup_errno(err)));
+			   boost::system::error_code(err, boost::system::get_system_category())));
 	}
 
 	int const flags = O_WRONLY | O_CREAT | (noclobber ? O_EXCL : O_TRUNC);
@@ -121,10 +121,10 @@
 		int err = errno;
 		::close(infile);
 		boost::throw_exception(
-			filesystem_path_error(
+			basic_filesystem_error<path>(
 				"boost::filesystem::copy_file",
 				source, target,
-				fs::lookup_errno(err)));
+				boost::system::error_code(err, boost::system::get_system_category())));
 	}
 
 	std::size_t const buf_sz = 32768;
@@ -153,10 +153,10 @@
 
 	if (in == -1 || out == -1)
 		boost::throw_exception(
-			filesystem_path_error(
+			basic_filesystem_error<path>(
 				"boost::filesystem::copy_file",
 				source, target,
-				fs::lookup_errno(err)));
+				boost::system::error_code(err, boost::system::get_system_category())));
 #endif
 #ifdef BOOST_WINDOWS
 	if (::CopyFile(source.string().c_str(), target.string().c_str(), noclobber) == 0) {
