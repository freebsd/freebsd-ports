--- core/DesktopEditor/common/Directory.cpp.orig	2021-09-30 12:13:32 UTC
+++ core/DesktopEditor/common/Directory.cpp
@@ -35,7 +35,7 @@
     #include "windef.h"
     #include <shlobj.h>
     #include <Rpc.h>
-#elif __linux__
+#elif defined(__linux__) || defined(__FreeBSD__)
     #include <sys/types.h>
     #include <sys/stat.h>
     #include <unistd.h>
@@ -121,7 +121,7 @@ namespace NSDirectory
         FindClose( hRes );
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         BYTE* pUtf8 = NULL;
         LONG lLen = 0;
         NSFile::CUtf8Converter::GetUtf8StringFromUnicode(strDirectory.c_str(), strDirectory.length(), pUtf8, lLen, false);
@@ -236,7 +236,7 @@ namespace NSDirectory
 			}
 		} while( FindNextFileW( hRes, &oFD ) );		
 		FindClose( hRes );
-#elif __linux__
+#elif defined(__linux__) || defined(__FreeBSD__)
 		BYTE* pUtf8 = NULL;
 		LONG lLen = 0;
         NSFile::CUtf8Converter::GetUtf8StringFromUnicode(strDirectory.c_str(), strDirectory.length(), pUtf8, lLen, false);
@@ -300,7 +300,7 @@ namespace NSDirectory
 #if defined(_WIN32) || defined (_WIN64)
 		DWORD dwAttrib = ::GetFileAttributesW(strDirectory.c_str());
 		return (dwAttrib != INVALID_FILE_ATTRIBUTES && 0 != (dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
-#elif __linux__
+#elif defined(__linux__) || defined(__FreeBSD__)
         BYTE* pUtf8 = NULL;
         LONG lLen = 0;
         NSFile::CUtf8Converter::GetUtf8StringFromUnicode(strDirectory.c_str(), strDirectory.length(), pUtf8, lLen, false);
@@ -399,7 +399,7 @@ namespace NSDirectory
         return true;
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         BYTE* pUtf8 = NULL;
         LONG lLen = 0;
         NSFile::CUtf8Converter::GetUtf8StringFromUnicode(strSrc.c_str(), strSrc.length(), pUtf8, lLen, false);
@@ -496,14 +496,14 @@ namespace NSDirectory
 		}
 #if defined(_WIN32) || defined (_WIN64)
 		if (deleteRoot) RemoveDirectoryW(strDirectory.c_str());
-#elif __linux__
+#elif defined(__linux__) || defined(__FreeBSD__)
 		BYTE* pUtf8 = NULL;
 		LONG lLen = 0;
         NSFile::CUtf8Converter::GetUtf8StringFromUnicode(strDirectory.c_str(), strDirectory.length(), pUtf8, lLen, false);
 		rmdir((char*)pUtf8);
 		delete [] pUtf8;
 
-		if (deleteRoot = false)CreateDirectory(strDirectory);
+		if (deleteRoot == false) CreateDirectory(strDirectory);
 #elif MAC
         BYTE* pUtf8 = NULL;
         LONG lLen = 0;
