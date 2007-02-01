--- ./src/os/OsUtil.cpp.orig	Tue Jul 25 17:05:55 2006
+++ ./src/os/OsUtil.cpp	Thu Dec 28 16:14:44 2006
@@ -426,6 +426,8 @@
    platform = PLATFORM_LINUX;
 #elif defined(sun) /* ] [ */
    platform = PLATFORM_SOLARIS;
+#elif defined(__FreeBSD__)
+   platform = PLATFORM_FREEBSD;
 #else /* ] [ */
 #error Unexpected Platform/CPU type
 #endif /* ] ]*/
