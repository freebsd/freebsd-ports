-- On FreeBSD, pthread_rwlock_destroy() and pthread_mutex_destroy() return
-- EBUSY when the lock is still held. This happens during C++ static destructor
-- execution at program exit (the lock may still be held by an ongoing log
-- operation). glog's SAFE_PTHREAD macro calls abort() on any non-zero return,
-- causing SIGABRT. Fix: ignore errors in the destructor (the process is exiting
-- anyway so leaked resources do not matter).
--- third_party/glog/src/base/mutex.h.orig	2026-06-20 03:41:08 UTC
+++ third_party/glog/src/base/mutex.h
@@ -246,7 +246,7 @@ Mutex::Mutex() {
   SetIsSafe();
   if (is_safe_ && pthread_rwlock_init(&mutex_, NULL) != 0) abort();
 }
-Mutex::~Mutex()            { SAFE_PTHREAD(pthread_rwlock_destroy); }
+Mutex::~Mutex()            { if (is_safe_) pthread_rwlock_destroy(&mutex_); }
 void Mutex::Lock()         { SAFE_PTHREAD(pthread_rwlock_wrlock); }
 void Mutex::Unlock()       { SAFE_PTHREAD(pthread_rwlock_unlock); }
 #ifdef GMUTEX_TRYLOCK
@@ -268,7 +268,7 @@ Mutex::Mutex()             {
   SetIsSafe();
   if (is_safe_ && pthread_mutex_init(&mutex_, NULL) != 0) abort();
 }
-Mutex::~Mutex()            { SAFE_PTHREAD(pthread_mutex_destroy); }
+Mutex::~Mutex()            { if (is_safe_) pthread_mutex_destroy(&mutex_); }
 void Mutex::Lock()         { SAFE_PTHREAD(pthread_mutex_lock); }
 void Mutex::Unlock()       { SAFE_PTHREAD(pthread_mutex_unlock); }
 #ifdef GMUTEX_TRYLOCK
