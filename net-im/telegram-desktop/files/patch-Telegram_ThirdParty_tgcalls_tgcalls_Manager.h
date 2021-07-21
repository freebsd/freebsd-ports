--- Telegram/ThirdParty/tgcalls/tgcalls/Manager.h.orig	2021-07-21 01:10:21 UTC
+++ Telegram/ThirdParty/tgcalls/tgcalls/Manager.h
@@ -17,7 +17,6 @@ class Manager final : public std::enable_shared_from_t
         bool isLowDataRequested = false;
 
         bool operator==(const ResolvedNetworkStatus &rhs);
-        bool operator!=(const ResolvedNetworkStatus &rhs);
     };
 
 public:
