--- src/storage.cpp.orig	2009-02-08 17:13:04.000000000 +0900
+++ src/storage.cpp	2009-04-19 05:32:24.000000000 +0900
@@ -82,9 +82,11 @@
 #include <cstdio>
 #endif
 
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__)
 // for getattrlist()
+#ifdef __APPLE__
 #include <sys/attr.h>
+#endif
 #include <unistd.h>
 // for statfs()
 #include <sys/param.h>
@@ -496,7 +498,7 @@
 			m_mapped_files->rename_file(index, new_filename);
 #ifndef BOOST_NO_EXCEPTIONS
 		}
-#if BOOST_VERSION >= 103500
+#if 0 // BOOST_VERSION >= 103500
 		catch (boost::system::system_error& e)
 		{
 			set_error(old_name, e.code());
