--- src/util/tracer.h.orig	2014-06-13 15:42:33.000000000 +0200
+++ src/util/tracer.h	2014-06-13 15:42:58.000000000 +0200
@@ -21,12 +21,12 @@
 
 
 #if !defined WIN32 && !defined WINCE
-#define TRACE __PRETTY_FUNCTION__<<" ("__FILE__<<':'<<std::dec<<__LINE__<<")"
+#define TRACE __PRETTY_FUNCTION__<<" ("<<__FILE__<<':'<<std::dec<<__LINE__<<")"
 #define LOCATION	(__oss.str(""), \
                    __oss<<__FILE__<<":"<<std::dec<<__LINE__<<"::"<<__PRETTY_FUNCTION__, \
 									 __oss.str())
 #elif defined WIN32
-#define TRACE __FUNCSIG__<<" ("__FILE__<<':'<<std::dec<<__LINE__<<")"
+#define TRACE __FUNCSIG__<<" ("<<__FILE__<<':'<<std::dec<<__LINE__<<")"
 #define LOCATION	(__oss.str(""), \
                    __oss<<__FILE__<<":"<<std::dec<<__LINE__<<"::"<<__FUNCTION__, \
 									 __oss.str())
