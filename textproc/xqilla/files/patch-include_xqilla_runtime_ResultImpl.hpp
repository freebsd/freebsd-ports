--- include/xqilla/runtime/ResultImpl.hpp.orig	2015-05-18 17:38:59 UTC
+++ include/xqilla/runtime/ResultImpl.hpp
@@ -59,7 +59,7 @@ protected:
   Result *resultPointer_;
 
 private:
-  ResultImpl(const ResultImpl &) {};
+  ResultImpl(const ResultImpl &) : LocationInfo() {};
   ResultImpl &operator=(const ResultImpl &) { return *this; };
 };
 
