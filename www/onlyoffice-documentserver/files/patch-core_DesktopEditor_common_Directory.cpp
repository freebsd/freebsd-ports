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
@@ -120,7 +120,7 @@ namespace NSDirectory
 		FindClose( hRes );
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 		BYTE* pUtf8 = NULL;
 		LONG lLen = 0;
 		NSFile::CUtf8Converter::GetUtf8StringFromUnicode(strDirectory.c_str(), strDirectory.length(), pUtf8, lLen, false);
@@ -235,7 +235,7 @@ namespace NSDirectory
 			}
 		} while( FindNextFileW( hRes, &oFD ) );
 		FindClose( hRes );
-#elif __linux__
+#elif defined(__linux__) || defined(__FreeBSD__)
 		BYTE* pUtf8 = NULL;
 		LONG lLen = 0;
 		NSFile::CUtf8Converter::GetUtf8StringFromUnicode(strDirectory.c_str(), strDirectory.length(), pUtf8, lLen, false);
@@ -299,7 +299,7 @@ namespace NSDirectory
 #if defined(_WIN32) || defined (_WIN64)
 		DWORD dwAttrib = ::GetFileAttributesW(strDirectory.c_str());
 		return (dwAttrib != INVALID_FILE_ATTRIBUTES && 0 != (dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
-#elif __linux__
+#elif defined(__linux__) || defined(__FreeBSD__)
 		BYTE* pUtf8 = NULL;
 		LONG lLen = 0;
 		NSFile::CUtf8Converter::GetUtf8StringFromUnicode(strDirectory.c_str(), strDirectory.length(), pUtf8, lLen, false);
@@ -398,7 +398,7 @@ namespace NSDirectory
 		return true;
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 		BYTE* pUtf8 = NULL;
 		LONG lLen = 0;
 		NSFile::CUtf8Converter::GetUtf8StringFromUnicode(strSrc.c_str(), strSrc.length(), pUtf8, lLen, false);
@@ -495,7 +495,7 @@ namespace NSDirectory
 		}
 #if defined(_WIN32) || defined (_WIN64)
 		if (deleteRoot) RemoveDirectoryW(strDirectory.c_str());
-#elif __linux__
+#elif defined(__linux__) || defined(__FreeBSD__)
 		BYTE* pUtf8 = NULL;
 		LONG lLen = 0;
 		NSFile::CUtf8Converter::GetUtf8StringFromUnicode(strDirectory.c_str(), strDirectory.length(), pUtf8, lLen, false);
