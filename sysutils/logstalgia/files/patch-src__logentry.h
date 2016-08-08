--- src/logentry.h.orig	2011-02-15 23:52:06 UTC
+++ src/logentry.h
@@ -41,7 +41,7 @@ public:
     void setSuccess();
     void setResponseColour();
 
-    long timestamp;
+    time_t timestamp;
 
     std::string hostname;
     std::string vhost;
