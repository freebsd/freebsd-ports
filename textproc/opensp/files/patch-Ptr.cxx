--- include/Ptr.cxx.orig	Fri Jul 18 14:11:13 2003
+++ include/Ptr.cxx	Fri Jul 18 14:11:32 2003
@@ -19,7 +19,7 @@
 Ptr<T>::~Ptr()
 {
   if (ptr_) {
-    if (ptr_->unref())
+    if (((Resource*)ptr_)->unref())
       delete ptr_;
     ptr_ = 0;
   }
