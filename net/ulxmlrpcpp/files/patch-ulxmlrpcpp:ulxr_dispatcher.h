--- ulxmlrpcpp/ulxr_dispatcher.h.orig	Fri Sep  3 17:06:46 2004
+++ ulxmlrpcpp/ulxr_dispatcher.h	Fri Sep  3 17:06:57 2004
@@ -108,8 +108,6 @@
 
    typedef hidden::MethodWrapperBase*  DynamicMethodCall_t;    // call Wrappers call();
 
-   struct MethodCallDescriptor;
-
    enum   CallType { CallNone,
                      CallSystem,
                      CallStatic,
