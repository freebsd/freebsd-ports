--- src/otherfunctions.cpp.orig	Mon Apr  5 19:58:46 2004
+++ src/otherfunctions.cpp	Mon Apr  5 19:59:45 2004
@@ -662,7 +662,7 @@
 }
 
 #ifdef __FreeBSD__
-long long atoll(char * s) {
+long long atoll(const char * s) {
 	return strtoll(s, (char **) NULL, 10);
 }
 
