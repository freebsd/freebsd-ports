--- src/log.h.orig	2017-06-20 14:47:37 UTC
+++ src/log.h
@@ -14,7 +14,7 @@ void setLogLevel(int l);
 #define log0 if(logLevel>=0)
 
 #define log1 if(logLevel>=1)
-#define log2 if(logLevel>=2)
+#define gfan_log2 if(logLevel>=2)
 #define log3 if(logLevel>=3)
 
 #endif
