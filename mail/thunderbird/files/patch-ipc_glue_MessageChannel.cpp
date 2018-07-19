To be removed after FreeBSD 10.* EOL

--- ipc/glue/MessageChannel.cpp.orig	2017-11-02 16:16:32 UTC
+++ ipc/glue/MessageChannel.cpp
@@ -685,6 +685,11 @@ MessageChannel::WillDestroyCurrentMessageLoop()
     mWorkerLoop = nullptr;
 }
 
+#if defined(_LIBCPP_VERSION) && _LIBCPP_VERSION < 4000
+// Work around UB in __tree crashing mPendingPromises.clear()
+// http://llvm.org/viewvc/llvm-project?view=revision&revision=276003
+[[clang::optnone]]
+#endif
 void
 MessageChannel::Clear()
 {
