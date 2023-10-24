Index: src/3rdparty/PhysX/source/foundation/src/unix/PsUnixThread.cpp
--- src/3rdparty/PhysX/source/foundation/src/unix/PsUnixThread.cpp.orig	2023-09-24 11:12:43 UTC
+++ src/3rdparty/PhysX/source/foundation/src/unix/PsUnixThread.cpp
@@ -36,7 +36,7 @@
 #include "PsThread.h"
 
 #include <math.h>
-#if !PX_APPLE_FAMILY && !defined(ANDROID) && !defined(__CYGWIN__) && !PX_PS4 && !PX_EMSCRIPTEN && __GLIBC__
+#if !PX_APPLE_FAMILY && !defined(ANDROID) && !defined(__CYGWIN__) && !PX_PS4 && !PX_EMSCRIPTEN && !PX_FREEBSD && __GLIBC__
 #include <bits/local_lim.h> // PTHREAD_STACK_MIN
 #endif
 #include <stdio.h>
@@ -44,7 +44,7 @@
 #include <unistd.h>
 #if !PX_PS4
 #include <sys/syscall.h>
-#if !PX_APPLE_FAMILY && !PX_EMSCRIPTEN
+#if !PX_APPLE_FAMILY && !PX_EMSCRIPTEN && !PX_FREEBSD
 #include <asm/unistd.h>
 #include <sys/resource.h>
 #endif
@@ -111,11 +111,11 @@ static void setTid(_ThreadImpl& threadImpl)
 static void setTid(_ThreadImpl& threadImpl)
 {
 // query TID
-#if PX_PS4 || (defined (TARGET_OS_TV) && TARGET_OS_TV)
+#if PX_PS4 || (defined (TARGET_OS_TV) && TARGET_OS_TV) || PX_FREEBSD
 // AM: TODO: neither of the below are implemented
-#elif PX_APPLE_FAMILY
+#elif PX_APPLE_FAMILY || !PX_FREEBSD
 	threadImpl.tid = syscall(SYS_gettid);
-#elif PX_EMSCRIPTEN
+#elif PX_EMSCRIPTEN || PX_FREEBSD
 	threadImpl.tid = pthread_self();
 #else
 	threadImpl.tid = syscall(__NR_gettid);
@@ -311,7 +311,7 @@ uint32_t ThreadImpl::setAffinityMask(uint32_t mask)
 	{
 #if PX_PS4
 		prevMask = setAffinityMaskPS4(getThread(this)->thread, mask);
-#elif PX_EMSCRIPTEN
+#elif PX_EMSCRIPTEN || PX_FREEBSD
 		// not supported
 #elif !PX_APPLE_FAMILY // Apple doesn't support syscall with getaffinity and setaffinity
 		int32_t errGet = syscall(__NR_sched_getaffinity, getThread(this)->tid, sizeof(prevMask), &prevMask);
