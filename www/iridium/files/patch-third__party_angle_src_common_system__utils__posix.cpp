--- third_party/angle/src/common/system_utils_posix.cpp.orig	2022-03-28 18:11:04 UTC
+++ third_party/angle/src/common/system_utils_posix.cpp
@@ -248,7 +248,9 @@ Library *OpenSharedLibraryWithExtensionAndGetError(con
     int extraFlags = 0;
     if (searchType == SearchType::AlreadyLoaded)
     {
+#if !defined(__OpenBSD__)
         extraFlags = RTLD_NOLOAD;
+#endif
     }
 
     std::string fullPath = directory + libraryName;
