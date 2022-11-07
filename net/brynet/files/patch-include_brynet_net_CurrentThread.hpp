--- include/brynet/net/CurrentThread.hpp.orig	2022-11-07 05:56:13 UTC
+++ include/brynet/net/CurrentThread.hpp
@@ -23,7 +23,11 @@ namespace brynet { namespace net { namespace current_t
 #ifdef BRYNET_PLATFORM_WINDOWS
 using THREAD_ID_TYPE = DWORD;
 #elif defined BRYNET_PLATFORM_LINUX || defined BRYNET_PLATFORM_DARWIN || defined BRYNET_PLATFORM_FREEBSD
+#  if defined BRYNET_PLATFORM_FREEBSD
+using THREAD_ID_TYPE = pthread_t;
+#  else
 using THREAD_ID_TYPE = int;
+#  endif
 #endif
 
 static THREAD_ID_TYPE& tid()
@@ -41,12 +45,16 @@ static THREAD_ID_TYPE& tid()
 #elif defined BRYNET_PLATFORM_LINUX
         cachedTid = static_cast<pid_t>(::syscall(SYS_gettid));
 #elif defined BRYNET_PLATFORM_DARWIN || defined BRYNET_PLATFORM_FREEBSD
+#  if defined BRYNET_PLATFORM_FREEBSD
+        cachedTid = pthread_self();
+#  else
         // warning: 'syscall' is deprecated:
         // first deprecated in macOS 10.12 - syscall(2) is unsupported;
         // please switch to a supported interface.
         uint64_t tid64;
         pthread_threadid_np(NULL, &tid64);
         cachedTid = (pid_t) tid64;
+#  endif
 #endif
     }
 
