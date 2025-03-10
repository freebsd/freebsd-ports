--- ../passenger-6.0.26/src/cxx_supportlib/oxt/implementation.cpp.orig	2013-10-26 20:00:00.000000000 -0400
+++ ../passenger-6.0.26/src/cxx_supportlib/oxt/implementation.cpp	2025-02-04 14:00:31.804615000 -0500
@@ -397,9 +397,9 @@
 
 static void
 set_native_thread_name(const string &name) {
-	#if defined(__linux__)
+	#if defined(__linux__) || defined(__FreeBSD__)
 		pthread_setname_np(pthread_self(), name.c_str());
-	#elif defined(__APPLE__) || defined(__FreeBSD__)
+	#elif defined(__APPLE__)
 		pthread_setname_np(name.c_str());
 	#endif
 }
