--- include/brynet/net/EventLoop.hpp.orig	2022-11-07 05:58:53 UTC
+++ include/brynet/net/EventLoop.hpp
@@ -72,7 +72,11 @@ class EventLoop : public brynet::base::NonCopyable (pu
         mIsInBlock = true;
 
         reAllocEventSize(1024);
+#if defined BRYNET_PLATFORM_FREEBSD
+        mSelfThreadID = nullptr;
+#else
         mSelfThreadID = -1;
+#endif
         mTimer = std::make_shared<brynet::base::TimerMgr>();
         mSelfThreadIDIsInitialized.store(false);
     }
