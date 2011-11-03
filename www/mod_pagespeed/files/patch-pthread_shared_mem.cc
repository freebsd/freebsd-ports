--- net/instaweb/util/pthread_shared_mem.cc.orig	2011-10-31 14:25:06.000000000 +0000
+++ net/instaweb/util/pthread_shared_mem.cc	2011-10-31 22:04:15.000000000 +0000
@@ -24,6 +24,9 @@
 #include <cstddef>
 #include <map>
 #include <utility>
+#if defined(__FreeBSD__)
+#include <semaphore.h>
+#endif
 #include "net/instaweb/util/public/abstract_shared_mem.h"
 #include "net/instaweb/util/public/abstract_mutex.h"
 #include "net/instaweb/util/public/basictypes.h"
@@ -70,13 +73,45 @@
   DISALLOW_COPY_AND_ASSIGN(PthreadSharedMemMutex);
 };
 
+#if defined(__FreeBSD__)
+// Some OSs does not support PTHREAD_PROCESS_SHARED attribute. (ex. FreeBSD < 9R, MacOS)
+// FreeBSD lacks PTHREAD_PROCESS_SHARED support before 9.0R, so we use a semaphore
+// instead. But nested locking is not supported.
+class SemSharedMemMutex : public AbstractMutex {
+ public:
+  explicit SemSharedMemMutex(sem_t* sem)
+      : sem_(sem) {}
+
+  virtual void Lock() {
+    sem_wait(sem_);
+  }
+
+  virtual void Unlock() {
+    sem_post(sem_);
+  }
+
+private:
+  sem_t* sem_;
+  DISALLOW_COPY_AND_ASSIGN(SemSharedMemMutex);
+};
+#endif
+
 class PthreadSharedMemSegment : public AbstractSharedMemSegment {
  public:
   // We will be representing memory mapped in the [base, base + size) range.
+#if defined(__FreeBSD__)
+  PthreadSharedMemSegment(char* base, size_t size, MessageHandler* handler, const char* name)
+      : base_(base),
+        size_(size),
+        sem_(NULL) {
+    std::sprintf(name_, "/%s_sem", name);
+  }
+#else
   PthreadSharedMemSegment(char* base, size_t size, MessageHandler* handler)
       : base_(base),
         size_(size) {
   }
+#endif
 
   virtual ~PthreadSharedMemSegment() {
   }
@@ -86,10 +121,18 @@
   }
 
   virtual size_t SharedMutexSize() const {
+#if defined(__FreeBSD__)
+    return 0;
+#else
     return sizeof(pthread_mutex_t);
+#endif
   }
 
   virtual bool InitializeSharedMutex(size_t offset, MessageHandler* handler) {
+#if defined(__FreeBSD__)
+    sem_ = sem_open(name_, O_CREAT, 0755, 1);
+    return sem_ ? true : false;
+#else
     pthread_mutexattr_t attr;
     if (pthread_mutexattr_init(&attr) != 0) {
       handler->Message(kError, "pthread_mutexattr_init failed with errno:%d",
@@ -113,19 +156,32 @@
 
     pthread_mutexattr_destroy(&attr);
     return true;
+#endif
   }
 
   virtual AbstractMutex* AttachToSharedMutex(size_t offset) {
+#if defined(__FreeBSD__)
+    sem_ = sem_open(name_, O_EXCL);
+    return new SemSharedMemMutex(sem_);
+#else
     return new PthreadSharedMemMutex(MutexPtr(offset));
+#endif
   }
 
  private:
+#if defined(__FreeBSD__)
+#else
   pthread_mutex_t* MutexPtr(size_t offset) {
     return reinterpret_cast<pthread_mutex_t*>(base_ + offset);
   }
+#endif
 
   char* const base_;
   const size_t size_;
+#if defined(__FreeBSD__)
+  char name_[256];
+  sem_t* sem_;
+#endif
 
   DISALLOW_COPY_AND_ASSIGN(PthreadSharedMemSegment);
 };
@@ -143,7 +199,11 @@
 }
 
 size_t PthreadSharedMem::SharedMutexSize() const {
+#if defined(__FreeBSD__)
+  return 0;
+#else
   return sizeof(pthread_mutex_t);
+#endif
 }
 
 AbstractSharedMemSegment* PthreadSharedMem::CreateSegment(
@@ -167,7 +227,11 @@
   SegmentBaseMap* bases = AcquireSegmentBases();
   (*bases)[name] = base;
   UnlockSegmentBases();
+#if defined(__FreeBSD__)
+  return new PthreadSharedMemSegment(base, size, handler, name.c_str());
+#else
   return new PthreadSharedMemSegment(base, size, handler);
+#endif
 }
 
 AbstractSharedMemSegment* PthreadSharedMem::AttachToSegment(
@@ -182,7 +246,11 @@
   }
   char* base = i->second;
   UnlockSegmentBases();
+#if defined(__FreeBSD__)
+  return new PthreadSharedMemSegment(base, size, handler, name.c_str());
+#else
   return new PthreadSharedMemSegment(base, size, handler);
+#endif
 }
 
 void PthreadSharedMem::DestroySegment(const GoogleString& name,
