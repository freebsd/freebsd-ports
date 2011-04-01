--- third_party/WebKit/Source/WebCore/platform/sql/chromium/SQLiteFileSystemChromiumPosix.cpp.orig	2011-03-20 22:02:04.262978254 +0200
+++ third_party/WebKit/Source/WebCore/platform/sql/chromium/SQLiteFileSystemChromiumPosix.cpp	2011-03-20 22:02:04.435738199 +0200
@@ -755,6 +755,8 @@
     if (!success)
         success = !fsync(fd);
     return success;
+#elif OS(FREEBSD)
+    return !fsync(fd);
 #else
     return !fdatasync(fd);
 #endif
