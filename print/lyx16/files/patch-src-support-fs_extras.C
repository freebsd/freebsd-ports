--- src/support/fs_extras.C.orig	2005-05-07 18:31:16.000000000 +0400
+++ src/support/fs_extras.C	2009-03-23 18:01:11.000000000 +0300
@@ -93,13 +93,15 @@
 {
 
 #ifdef BOOST_POSIX
+#include <boost/version.hpp>
 	int const infile = ::open(source.string().c_str(), O_RDONLY);
         if (infile == -1) {
 		boost::throw_exception(
-			filesystem_error(
+			basic_filesystem_error<path>(
 				"boost::filesystem::copy_file",
 				source, target,
-				fs::detail::system_error_code()));
+				boost::system::error_code(errno, boost::system::get_system_category()))
+			);
 	}
 
         struct stat source_stat;
@@ -107,10 +109,11 @@
         if (ret == -1) {
                 ::close(infile);
 		boost::throw_exception(
-			filesystem_error(
+			basic_filesystem_error<path>(
 				"boost::filesystem::copy_file",
 				source, target,
-				fs::detail::system_error_code()));
+				boost::system::error_code(errno, boost::system::get_system_category()))
+			);
         }
 
         int const flags = O_WRONLY | O_CREAT | (noclobber ? O_EXCL : O_TRUNC);
@@ -119,10 +122,11 @@
         if (outfile == -1) {
                 ::close(infile);
 		boost::throw_exception(
-			filesystem_error(
+			basic_filesystem_error<path>(
 				"boost::filesystem::copy_file",
 				source, target,
-				fs::detail::system_error_code()));
+				boost::system::error_code(errno, boost::system::get_system_category()))
+			);	
         }
 
         std::size_t const buf_sz = 32768;
@@ -149,10 +153,11 @@
 
         if (in == -1 || out == -1)
 		boost::throw_exception(
-			filesystem_error(
+			basic_filesystem_error<path>(
 				"boost::filesystem::copy_file",
 				source, target,
-				fs::detail::system_error_code()));
+				boost::system::error_code(errno, boost::system::get_system_category()))
+			);	
 #endif
 #ifdef BOOST_WINDOWS
 	if (::CopyFile(source.string().c_str(), target.string().c_str(), noclobber) == 0) {
