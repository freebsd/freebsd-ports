--- third_party/angle/src/common/system_utils_posix.cpp.orig	2022-02-07 13:39:41 UTC
+++ third_party/angle/src/common/system_utils_posix.cpp
@@ -159,7 +159,9 @@ Library *OpenSharedLibraryWithExtension(const char *li
     int extraFlags = 0;
     if (searchType == SearchType::AlreadyLoaded)
     {
+#if !defined(__OpenBSD__)
         extraFlags = RTLD_NOLOAD;
+#endif
     }
 
     std::string fullPath = directory + libraryName;
