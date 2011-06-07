--- v8/src/platform-freebsd.cc.orig	2011-06-05 18:08:56.225331291 +0300
+++ v8/src/platform-freebsd.cc	2011-06-05 18:46:22.678164821 +0300
@@ -55,6 +55,7 @@
 
 #include "platform.h"
 #include "vm-state-inl.h"
+#include "v8threads.h"
 
 
 namespace v8 {
@@ -397,31 +398,6 @@
 };
 
 
-ThreadHandle::ThreadHandle(Kind kind) {
-  data_ = new PlatformData(kind);
-}
-
-
-void ThreadHandle::Initialize(ThreadHandle::Kind kind) {
-  data_->Initialize(kind);
-}
-
-
-ThreadHandle::~ThreadHandle() {
-  delete data_;
-}
-
-
-bool ThreadHandle::IsSelf() const {
-  return pthread_equal(data_->thread_, pthread_self());
-}
-
-
-bool ThreadHandle::IsValid() const {
-  return data_->thread_ != kNoThread;
-}
-
-
 Thread::Thread(Isolate* isolate, const Options& options)
     : data_(new PlatformData),
       isolate_(isolate),
@@ -448,8 +424,8 @@
   // This is also initialized by the first argument to pthread_create() but we
   // don't know which thread will run first (the original thread or the new
   // one) so we initialize it here too.
-  thread_->data_->thread_ = pthread_self();
-  ASSERT(thread->IsValid());
+  thread->data()->thread_ = pthread_self();
+  ASSERT(thread->data()->thread_ != kNoThread);
   Thread::SetThreadLocal(Isolate::isolate_key(), thread->isolate());
   thread->Run();
   return NULL;
@@ -470,13 +446,13 @@
     pthread_attr_setstacksize(&attr, static_cast<size_t>(stack_size_));
     attr_ptr = &attr;
   }
-  pthread_create(&thread_handle_data()->thread_, attr_ptr, ThreadEntry, this);
-  ASSERT(IsValid());
+  pthread_create(&data_->thread_, attr_ptr, ThreadEntry, this);
+  ASSERT(data_->thread_ != kNoThread);
 }
 
 
 void Thread::Join() {
-  pthread_join(thread_handle_data()->thread_, NULL);
+  pthread_join(data_->thread_, NULL);
 }
 
 
