--- ./src/logentry.h.orig	2011-02-16 00:52:06.000000000 +0100
+++ ./src/logentry.h	2011-10-31 23:20:56.000000000 +0100
@@ -41,7 +41,7 @@
     void setSuccess();
     void setResponseColour();
 
-    long timestamp;
+    time_t timestamp;
 
     std::string hostname;
     std::string vhost;
