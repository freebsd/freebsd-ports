--- ulxmlrpcpp/ulxmlrpcpp.h.orig	Sat Jan 27 12:57:48 2007
+++ ulxmlrpcpp/ulxmlrpcpp.h	Sat Jan 27 12:58:07 2007
@@ -743,7 +743,7 @@
 #if defined(__CYGWIN__)
 # define ulxr_snprintf   snprintf
 #else
-# define ulxr_snprintf   std::snprintf
+# define ulxr_snprintf   snprintf
 #endif
 
 # define ulxr_swprintf   std::swprintf
