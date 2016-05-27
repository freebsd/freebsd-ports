--- libretroshare/src/util/argstream.h.orig	2016-02-05 19:04:46 UTC
+++ libretroshare/src/util/argstream.h
@@ -141,7 +141,7 @@ namespace 
 			inline OptionHolder(char s,
 					const char* l,
 					const char* desc);  
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
  			friend OptionHolder help(char s,
  					const char* l,
  					const char* desc);
