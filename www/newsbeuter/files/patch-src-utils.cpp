--- src/utils.cpp.orig	2015-02-19 10:56:59 UTC
+++ src/utils.cpp
@@ -274,7 +274,8 @@ std::string utils::convert_text(const st
 	 * of all the Unix-like systems around there, only Linux/glibc seems to
 	 * come with a SuSv3-conforming iconv implementation.
 	 */
-#if !(__linux) && !defined(__GLIBC__) && !defined(__APPLE__) && !defined(__OpenBSD__)
+#if !(__linux) && !defined(__GLIBC__) && !defined(__APPLE__) \
+ && !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__DragonFly__)
 	const char * inbufp;
 #else
 	char * inbufp;
