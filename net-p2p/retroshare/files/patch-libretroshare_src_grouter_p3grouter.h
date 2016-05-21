--- libretroshare/src/grouter/p3grouter.h.orig	2016-02-05 19:04:46 UTC
+++ libretroshare/src/grouter/p3grouter.h
@@ -225,7 +225,7 @@ private:
     void handleLowLevelTransactionAckItem(RsGRouterTransactionAcknItem*) ;
 
     static Sha1CheckSum computeDataItemHash(RsGRouterGenericDataItem *data_item);
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 public:
 #endif
     class nullstream: public std::ostream {};
@@ -236,7 +236,7 @@ public:
 
         return _debug_enabled?(std::cerr):null;
     }
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 private:
 #endif
     void routePendingObjects() ;
