--- src/Preferences.cpp.orig	Tue Sep  9 00:56:24 2003
+++ src/Preferences.cpp	Tue Sep  9 00:56:21 2003
@@ -60,7 +60,7 @@
 #endif
 
 #ifdef __FreeBSD__
-extern long long atoll(char *s);
+extern long long atoll(const char *s);
 #endif /* __FreeBSD__ */
 
 /// new implementation
