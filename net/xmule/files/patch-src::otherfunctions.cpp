--- src/otherfunctions.cpp.orig	Mon May 26 12:05:22 2003
+++ src/otherfunctions.cpp	Mon May 26 12:05:37 2003
@@ -546,7 +546,7 @@
 }
 
 #ifdef __FreeBSD__   
-long long atoll( char * s ){
+long long atoll(const char * s){
 return  strtoll(s, (char **)NULL, 10);
 }
 #endif /* __FreeBSD__ */
