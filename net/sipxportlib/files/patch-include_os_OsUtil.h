--- ./include/os/OsUtil.h.orig	Wed Aug 17 13:30:25 2005
+++ ./include/os/OsUtil.h	Thu Dec 28 16:14:44 2006
@@ -47,7 +47,8 @@
       PLATFORM_MACOSX=97,
       PLATFORM_SOLARIS=98,
       PLATFORM_LINUX=99,
-      PLATFORM_WIN32=100
+      PLATFORM_WIN32=100,
+      PLATFORM_FREEBSD=101
    };
 
    enum OsProductType
