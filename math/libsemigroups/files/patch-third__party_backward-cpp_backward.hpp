--- third_party/backward-cpp/backward.hpp.orig	2025-04-01 12:04:08 UTC
+++ third_party/backward-cpp/backward.hpp
@@ -52,6 +52,9 @@
 // #define BACKWARD_SYSTEM_DARWIN
 //	- specialization for Mac OS X 10.5 and later.
 //
+// #define BACKWARD_SYSTEM_FREEBSD
+//	- specialization for FreeBSD.
+//
 // #define BACKWARD_SYSTEM_WINDOWS
 //  - specialization for Windows (Clang 9 and MSVC2017)
 //
@@ -60,6 +63,7 @@
 //
 #if defined(BACKWARD_SYSTEM_LINUX)
 #elif defined(BACKWARD_SYSTEM_DARWIN)
+#elif defined(BACKWARD_SYSTEM_FREEBSD)
 #elif defined(BACKWARD_SYSTEM_UNKNOWN)
 #elif defined(BACKWARD_SYSTEM_WINDOWS)
 #else
@@ -67,12 +71,18 @@
 #define BACKWARD_SYSTEM_LINUX
 #elif defined(__APPLE__)
 #define BACKWARD_SYSTEM_DARWIN
+#elif defined(__FreeBSD__)
+#define BACKWARD_SYSTEM_FREEBSD
 #elif defined(_WIN32)
 #define BACKWARD_SYSTEM_WINDOWS
 #else
 #define BACKWARD_SYSTEM_UNKNOWN
 #endif
 #endif
+#if defined(__FreeBSD__)
+#include <pthread_np.h>
+#include <sys/ucontext.h>
+#endif
 
 #define NOINLINE __attribute__((noinline))
 
@@ -263,7 +273,7 @@
 
 #endif  // defined(BACKWARD_SYSTEM_LINUX)
 
-#if defined(BACKWARD_SYSTEM_DARWIN)
+#if defined(BACKWARD_SYSTEM_DARWIN) || defined(BACKWARD_SYSTEM_FREEBSD)
 // On Darwin, backtrace can back-trace or "walk" the stack using the following
 // libraries:
 //
@@ -329,7 +339,7 @@
     || (BACKWARD_HAS_BACKTRACE_SYMBOL == 1)
 #include <execinfo.h>
 #endif
-#endif  // defined(BACKWARD_SYSTEM_DARWIN)
+#endif  // defined(BACKWARD_SYSTEM_DARWIN) || defined(BACKWARD_SYSTEM_FREEBSD)
 
 #if defined(BACKWARD_SYSTEM_WINDOWS)
 
@@ -462,6 +472,7 @@ namespace backward {
     struct linux_tag;  // seems that I cannot call that "linux" because the name
     // is already defined... so I am adding _tag everywhere.
     struct darwin_tag;
+    struct freebsd_tag;
     struct windows_tag;
     struct unknown_tag;
 
@@ -469,6 +480,8 @@ namespace backward {
     typedef linux_tag current_tag;
 #elif defined(BACKWARD_SYSTEM_DARWIN)
     typedef darwin_tag current_tag;
+#elif defined(BACKWARD_SYSTEM_FREEBSD)
+    typedef freebsd_tag current_tag;
 #elif defined(BACKWARD_SYSTEM_WINDOWS)
     typedef windows_tag current_tag;
 #elif defined(BACKWARD_SYSTEM_UNKNOWN)
@@ -496,7 +509,7 @@ namespace backward {
 #else
 #error "You shall not pass, until you know what you want."
 #endif
-#elif defined(BACKWARD_SYSTEM_DARWIN)
+#elif defined(BACKWARD_SYSTEM_DARWIN) || defined(BACKWARD_SYSTEM_FREEBSD)
     struct backtrace_symbol;
 
 #if BACKWARD_HAS_BACKTRACE_SYMBOL == 1
@@ -654,7 +667,7 @@ namespace backward {
       }
     };
 
-#if defined(BACKWARD_SYSTEM_LINUX) || defined(BACKWARD_SYSTEM_DARWIN)
+#if defined(BACKWARD_SYSTEM_LINUX) || defined(BACKWARD_SYSTEM_DARWIN) || defined(BACKWARD_SYSTEM_FREEBSD)
 
     template <>
     struct demangler_impl<system_tag::current_tag> {
@@ -678,7 +691,7 @@ namespace backward {
       size_t                 _demangle_buffer_length;
     };
 
-#endif  // BACKWARD_SYSTEM_LINUX || BACKWARD_SYSTEM_DARWIN
+#endif  // BACKWARD_SYSTEM_LINUX || BACKWARD_SYSTEM_DARWIN || defined(BACKWARD_SYSTEM_FREEBSD)
 
     struct demangler : public demangler_impl<system_tag::current_tag> {};
 
@@ -812,7 +825,7 @@ namespace backward {
         // I like to keep little secret sometimes.
         _thread_id = 0;
       }
-#elif defined(BACKWARD_SYSTEM_DARWIN)
+#elif defined(BACKWARD_SYSTEM_DARWIN) || defined(BACKWARD_SYSTEM_FREEBSD)
       _thread_id = reinterpret_cast<size_t>(pthread_self());
       if (pthread_main_np() == 1) {
         // If the thread is the main one, let's hide that.
@@ -1097,6 +1110,36 @@ namespace backward {
         }
         _stacktrace[index] = reinterpret_cast<void*>(ctx.data[16]);
         ++index;
+#elif defined(__FreeBSD__) && defined(__x86_64__)
+        unw_getcontext(&ctx);
+        ctx.data[0]  = uctx->uc_mcontext.mc_rax;
+        ctx.data[1]  = uctx->uc_mcontext.mc_rbx;
+        ctx.data[2]  = uctx->uc_mcontext.mc_rcx;
+        ctx.data[3]  = uctx->uc_mcontext.mc_rdx;
+        ctx.data[4]  = uctx->uc_mcontext.mc_rdi;
+        ctx.data[5]  = uctx->uc_mcontext.mc_rsi;
+        ctx.data[6]  = uctx->uc_mcontext.mc_rbp;
+        ctx.data[7]  = uctx->uc_mcontext.mc_rsp;
+        ctx.data[8]  = uctx->uc_mcontext.mc_r8;
+        ctx.data[9]  = uctx->uc_mcontext.mc_r9;
+        ctx.data[10] = uctx->uc_mcontext.mc_r10;
+        ctx.data[11] = uctx->uc_mcontext.mc_r11;
+        ctx.data[12] = uctx->uc_mcontext.mc_r12;
+        ctx.data[13] = uctx->uc_mcontext.mc_r13;
+        ctx.data[14] = uctx->uc_mcontext.mc_r14;
+        ctx.data[15] = uctx->uc_mcontext.mc_r15;
+        ctx.data[16] = uctx->uc_mcontext.mc_rip;
+
+        // If the IP is the same as the crash address we have a bad function
+        // dereference The caller's address is pointed to by %rsp, so we
+        // dereference that value and set it to be the next frame's IP.
+        if (uctx->uc_mcontext.mc_rip
+            == reinterpret_cast<__uint64_t>(error_addr())) {
+          ctx.data[16]
+              = *reinterpret_cast<__uint64_t*>(uctx->uc_mcontext.mc_rsp);
+        }
+        _stacktrace[index] = reinterpret_cast<void*>(ctx.data[16]);
+        ++index;
 #elif defined(__APPLE__)
         unw_getcontext(&ctx);
         // TODO: Convert the ucontext_t to libunwind's unw_context_t like
@@ -1108,6 +1151,17 @@ namespace backward {
         _stacktrace[index]
             = reinterpret_cast<void*>(ctx.uc_mcontext->__ss.__eip);
         ++index;
+#elif defined(__FreeBSD__)
+        unw_getcontext(&ctx);
+        // TODO: Convert the ucontext_t to libunwind's unw_context_t like
+        // we do in 64 bits
+        if (ctx.uc_mcontext.mc_eip
+            == reinterpret_cast<greg_t>(error_addr())) {
+          ctx.uc_mcontext.mc_eip = ctx.uc_mcontext.mc_esp;
+        }
+        _stacktrace[index]
+            = reinterpret_cast<void*>(ctx.uc_mcontext.mc_eip);
+        ++index;
 #endif
       }
 
@@ -3659,7 +3713,7 @@ namespace backward {
 
 #endif  // BACKWARD_SYSTEM_LINUX
 
-#ifdef BACKWARD_SYSTEM_DARWIN
+#if defined(BACKWARD_SYSTEM_DARWIN) || defined(BACKWARD_SYSTEM_FREEBSD)
 
   template <typename STACKTRACE_TAG>
   class TraceResolverDarwinImpl;
@@ -3739,10 +3793,14 @@ namespace backward {
   };
 
   template <>
+#ifdef BACKWARD_SYSTEM_DARWIN
   class TraceResolverImpl<system_tag::darwin_tag>
+#else	// BACKWARD_SYSTEM_FREEBSD
+  class TraceResolverImpl<system_tag::freebsd_tag>
+#endif
       : public TraceResolverDarwinImpl<trace_resolver_tag::current> {};
 
-#endif  // BACKWARD_SYSTEM_DARWIN
+#endif  // BACKWARD_SYSTEM_DARWIN || BACKWARD_SYSTEM_FREEBSD
 
 #ifdef BACKWARD_SYSTEM_WINDOWS
 
@@ -4408,7 +4466,7 @@ namespace backward {
 
   /*************** SIGNALS HANDLING ***************/
 
-#if defined(BACKWARD_SYSTEM_LINUX) || defined(BACKWARD_SYSTEM_DARWIN)
+#if defined(BACKWARD_SYSTEM_LINUX) || defined(BACKWARD_SYSTEM_DARWIN) || defined(BACKWARD_SYSTEM_FREEBSD)
 
   class SignalHandling {
    public:
@@ -4426,7 +4484,7 @@ namespace backward {
         SIGTRAP,  // Trace/breakpoint trap
         SIGXCPU,  // CPU time limit exceeded (4.2BSD)
         SIGXFSZ,  // File size limit exceeded (4.2BSD)
-#if defined(BACKWARD_SYSTEM_DARWIN)
+#if defined(BACKWARD_SYSTEM_DARWIN) || defined(BACKWARD_SYSTEM_FREEBSD)
         SIGEMT,  // emulation instruction executed
 #endif
       };
@@ -4496,6 +4554,8 @@ namespace backward {
 #elif defined(__aarch64__)
 #if defined(__APPLE__)
       error_addr = reinterpret_cast<void*>(uctx->uc_mcontext->__ss.__pc);
+#elif defined(__FreeBSD__)
+      error_addr = reinterpret_cast<void*>(uctx->uc_mcontext.mc_pc);
 #else
       error_addr = reinterpret_cast<void*>(uctx->uc_mcontext.pc);
 #endif
@@ -4511,8 +4571,12 @@ namespace backward {
       error_addr = reinterpret_cast<void*>(uctx->uc_mcontext.psw.addr);
 #elif defined(__APPLE__) && defined(__x86_64__)
       error_addr = reinterpret_cast<void*>(uctx->uc_mcontext->__ss.__rip);
+#elif defined(__FreeBSD__) && defined(__x86_64__)
+      error_addr = reinterpret_cast<void*>(uctx->uc_mcontext.mc_rip);
 #elif defined(__APPLE__)
       error_addr = reinterpret_cast<void*>(uctx->uc_mcontext->__ss.__eip);
+#elif defined(__FreeBSD__)
+      error_addr = reinterpret_cast<void*>(uctx->uc_mcontext.mc_eip);
 #else
 #warning ":/ sorry, ain't know no nothing none not of your architecture!"
 #endif
@@ -4555,7 +4619,7 @@ namespace backward {
     }
   };
 
-#endif  // BACKWARD_SYSTEM_LINUX || BACKWARD_SYSTEM_DARWIN
+#endif  // BACKWARD_SYSTEM_LINUX || BACKWARD_SYSTEM_DARWIN || BACKWARD_SYSTEM_FREEBSD
 
 #ifdef BACKWARD_SYSTEM_WINDOWS
 
