--- core/DesktopEditor/common/File.cpp.orig	2021-09-30 12:13:32 UTC
+++ core/DesktopEditor/common/File.cpp
@@ -39,11 +39,15 @@
     #include <windows.h>
 #endif
 
-#ifdef _LINUX
+#if defined(_LINUX) || defined(__FreeBSD__)
 #include <unistd.h>
 #include <string.h>
 #include <sys/stat.h>
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/sysctl.h>
 #endif
+#endif
 
 #ifdef _IOS
     const char* fileSystemRepresentation(const std::wstring& sFileName);
@@ -1613,6 +1617,22 @@ namespace NSFile
             return L"";
         }
 
+        std::string sUTF8(buf);
+        std::wstring sRet = CUtf8Converter::GetUnicodeStringFromUTF8((BYTE*)sUTF8.c_str(), sUTF8.length());
+        return sRet;
+#endif
+
+#if defined(__FreeBSD__)
+        int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1};
+        char buf[NS_FILE_MAX_PATH];
+        size_t size = NS_FILE_MAX_PATH;
+
+        memset(buf, 0, NS_FILE_MAX_PATH);
+        if (sysctl(mib, 4, &buf, &size, NULL, 0) != 0) {
+            size = readlink("/proc/curproc/file", buf, size - 1);
+            if (size < 0)
+            return L"";
+        }
         std::string sUTF8(buf);
         std::wstring sRet = CUtf8Converter::GetUnicodeStringFromUTF8((BYTE*)sUTF8.c_str(), sUTF8.length());
         return sRet;
