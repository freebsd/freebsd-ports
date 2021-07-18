--- 3rdparty/gmock/src/gmock-spec-builders.cc.orig	2014-10-22 20:07:20 UTC
+++ 3rdparty/gmock/src/gmock-spec-builders.cc
@@ -325,7 +325,7 @@ const char* UntypedFunctionMockerBase::Name() const
 // Calculates the result of invoking this mock function with the given
 // arguments, prints it, and returns it.  The caller is responsible
 // for deleting the result.
-const UntypedActionResultHolderBase*
+UntypedActionResultHolderBase*
 UntypedFunctionMockerBase::UntypedInvokeWith(const void* const untyped_args)
     GTEST_LOCK_EXCLUDED_(g_gmock_mutex) {
   if (untyped_expectations_.size() == 0) {
@@ -363,7 +363,7 @@ UntypedFunctionMockerBase::UntypedInvokeWith(const voi
     this->UntypedDescribeUninterestingCall(untyped_args, &ss);
 
     // Calculates the function result.
-    const UntypedActionResultHolderBase* const result =
+    UntypedActionResultHolderBase* const result =
         this->UntypedPerformDefaultAction(untyped_args, ss.str());
 
     // Prints the function result.
@@ -410,7 +410,7 @@ UntypedFunctionMockerBase::UntypedInvokeWith(const voi
     untyped_expectation->DescribeLocationTo(&loc);
   }
 
-  const UntypedActionResultHolderBase* const result =
+  UntypedActionResultHolderBase* const result =
       untyped_action == NULL ?
       this->UntypedPerformDefaultAction(untyped_args, ss.str()) :
       this->UntypedPerformAction(untyped_action, untyped_args);
