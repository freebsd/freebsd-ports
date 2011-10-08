--- net/instaweb/util/pthread_shared_mem.cc.orig
+++ net/instaweb/util/pthread_shared_mem.cc
@@ -24,6 +24,7 @@
 #include <cstddef>
 #include <map>
 #include <utility>
+#include <semaphore.h>
 #include "net/instaweb/util/public/abstract_shared_mem.h"
 #include "net/instaweb/util/public/abstract_mutex.h"
 #include "net/instaweb/util/public/basictypes.h"
@@ -70,12 +71,34 @@
   DISALLOW_COPY_AND_ASSIGN(PthreadSharedMemMutex);
 };
 
+// Some OSs does not support PTHREAD_PROCESS_SHARED attribute. (ex. FreeBSD < 9R, MacOS)
+// So, we use the semaphore instead. But nested lock is not supported.
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
+
 class PthreadSharedMemSegment : public AbstractSharedMemSegment {
  public:
   // We will be representing memory mapped in the [base, base + size) range.
-  PthreadSharedMemSegment(char* base, size_t size, MessageHandler* handler)
+  PthreadSharedMemSegment(char* base, size_t size, MessageHandler* handler, const char* name)
       : base_(base),
-        size_(size) {
+        size_(size),
+        sem_(NULL) {
+    std::sprintf(name_, "/%s_sem", name);
   }
 
   virtual ~PthreadSharedMemSegment() {
@@ -86,10 +109,15 @@
   }
 
   virtual size_t SharedMutexSize() const {
+#if 0
     return sizeof(pthread_mutex_t);
+#else
+    return 0;
+#endif
   }
 
   virtual bool InitializeSharedMutex(size_t offset, MessageHandler* handler) {
+#if 0
     pthread_mutexattr_t attr;
     if (pthread_mutexattr_init(&attr) != 0) {
       handler->Message(kError, "pthread_mutexattr_init failed with errno:%d",
@@ -113,19 +141,33 @@
 
     pthread_mutexattr_destroy(&attr);
     return true;
+#else
+//std::printf("sem: %s\n", name_);
+    sem_ = sem_open(name_, O_CREAT, 0755, 1);
+    return sem_ ? true : false;
+#endif
   }
 
   virtual AbstractMutex* AttachToSharedMutex(size_t offset) {
+#if 0
     return new PthreadSharedMemMutex(MutexPtr(offset));
+#else
+    sem_ = sem_open(name_, O_EXCL);
+    return new SemSharedMemMutex(sem_);
+#endif
   }
 
  private:
+#if 0
   pthread_mutex_t* MutexPtr(size_t offset) {
     return reinterpret_cast<pthread_mutex_t*>(base_ + offset);
   }
+#endif
 
   char* const base_;
   const size_t size_;
+  char name_[256];
+  sem_t* sem_;
 
   DISALLOW_COPY_AND_ASSIGN(PthreadSharedMemSegment);
 };
@@ -143,7 +185,11 @@
 }
 
 size_t PthreadSharedMem::SharedMutexSize() const {
+#if 0
   return sizeof(pthread_mutex_t);
+#else
+  return 0;
+#endif
 }
 
 AbstractSharedMemSegment* PthreadSharedMem::CreateSegment(
@@ -167,7 +213,7 @@
   SegmentBaseMap* bases = AcquireSegmentBases();
   (*bases)[name] = base;
   UnlockSegmentBases();
-  return new PthreadSharedMemSegment(base, size, handler);
+  return new PthreadSharedMemSegment(base, size, handler, name.c_str());
 }
 
 AbstractSharedMemSegment* PthreadSharedMem::AttachToSegment(
@@ -182,7 +228,7 @@
   }
   char* base = i->second;
   UnlockSegmentBases();
-  return new PthreadSharedMemSegment(base, size, handler);
+  return new PthreadSharedMemSegment(base, size, handler, name.c_str());
 }
 
 void PthreadSharedMem::DestroySegment(const GoogleString& name,
