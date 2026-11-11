--- core/DesktopEditor/common/Directory.cpp.orig	2026-10-11 14:54:04 UTC
+++ core/DesktopEditor/common/Directory.cpp
@@ -38,7 +38,7 @@
 #include "windef.h"
 #include <shlobj.h>
 #include <Rpc.h>
-#elif __linux__
+#elif defined(__linux__) || defined(__FreeBSD__)
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
@@ -127,7 +127,7 @@
 		FindClose( hRes );
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 		BYTE* pUtf8 = NULL;
 		LONG lLen = 0;
 		NSFile::CUtf8Converter::GetUtf8StringFromUnicode(strDirectory.c_str(), strDirectory.length(), pUtf8, lLen, false);
@@ -242,7 +242,7 @@
 			}
 		} while( FindNextFileW( hRes, &oFD ) );
 		FindClose( hRes );
-#elif __linux__
+#elif defined(__linux__) || defined(__FreeBSD__)
 		BYTE* pUtf8 = NULL;
 		LONG lLen = 0;
 		NSFile::CUtf8Converter::GetUtf8StringFromUnicode(strDirectory.c_str(), strDirectory.length(), pUtf8, lLen, false);
@@ -306,7 +306,7 @@
 #if defined(_WIN32) || defined (_WIN64)
 		DWORD dwAttrib = ::GetFileAttributesW(strDirectory.c_str());
 		return (dwAttrib != INVALID_FILE_ATTRIBUTES && 0 != (dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
-#elif __linux__
+#elif defined(__linux__) || defined(__FreeBSD__)
 		BYTE* pUtf8 = NULL;
 		LONG lLen = 0;
 		NSFile::CUtf8Converter::GetUtf8StringFromUnicode(strDirectory.c_str(), strDirectory.length(), pUtf8, lLen, false);
@@ -405,7 +405,7 @@
 		return true;
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 		BYTE* pUtf8 = NULL;
 		LONG lLen = 0;
 		NSFile::CUtf8Converter::GetUtf8StringFromUnicode(strSrc.c_str(), strSrc.length(), pUtf8, lLen, false);
@@ -486,7 +486,7 @@
 
 		return false;
 	}
-#if defined(__linux__) || defined(MAC) || defined(_IOS)
+#if defined(__linux__) || defined(MAC) || defined(_IOS) || defined(__FreeBSD__)
 	static bool IsSymbolicLink(const std::wstring& strPath)
 	{
 		std::string sPath = NSFile::CUtf8Converter::GetUtf8StringFromUnicode(strPath);
@@ -541,19 +541,19 @@
 		std::vector<std::wstring> aDirectories = GetDirectories(strDirectory);
 		for(size_t i = 0; i < aDirectories.size(); ++i)
 		{
-#if defined(__linux__) || defined(MAC) || defined(_IOS)
+#if defined(__linux__) || defined(MAC) || defined(_IOS) || defined(__FreeBSD__)
 			// with DT_UNKNOWN (XFS) GetDirectories follows a link to a directory, never delete through it
 			if (IsSymbolicLink(aDirectories[i]))
 				continue;
 #endif
 			DeleteDirectory(aDirectories[i]);
 		}
-#if defined(__linux__) || defined(MAC) || defined(_IOS)
+#if defined(__linux__) || defined(MAC) || defined(_IOS) || defined(__FreeBSD__)
 		RemoveSymbolicLinks(strDirectory);
 #endif
 #if defined(_WIN32) || defined (_WIN64)
 		if (deleteRoot) RemoveDirectoryW(strDirectory.c_str());
-#elif __linux__
+#elif defined(__linux__) || defined(__FreeBSD__)
 		BYTE* pUtf8 = NULL;
 		LONG lLen = 0;
 		NSFile::CUtf8Converter::GetUtf8StringFromUnicode(strDirectory.c_str(), strDirectory.length(), pUtf8, lLen, false);
