--- src/Preferences.cpp.orig	Mon May 26 12:08:45 2003
+++ src/Preferences.cpp	Mon May 26 12:10:14 2003
@@ -65,7 +65,7 @@
 extern int sprintf(char *__restrict __s,__const char*__restrict __format,...) __attribute__ ((__format__ (__printf__, 2,3)));
 
 #ifdef __FreeBSD__
-extern long long atoll(char *s);
+extern long long atoll(const char *s);
 #endif /* __FreeBSD__ */
 
 /// new implementation
