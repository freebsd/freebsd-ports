--- third-party/glog/src/utilities.h.orig	2015-04-16 17:06:51 UTC
+++ third-party/glog/src/utilities.h
@@ -81,54 +81,6 @@
 #include "config.h"
 #include "glog/logging.h"
 
-// There are three different ways we can try to get the stack trace:
-//
-// 1) The libunwind library.  This is still in development, and as a
-//    separate library adds a new dependency, but doesn't need a frame
-//    pointer.  It also doesn't call malloc.
-//
-// 2) Our hand-coded stack-unwinder.  This depends on a certain stack
-//    layout, which is used by gcc (and those systems using a
-//    gcc-compatible ABI) on x86 systems, at least since gcc 2.95.
-//    It uses the frame pointer to do its work.
-//
-// 3) The gdb unwinder -- also the one used by the c++ exception code.
-//    It's obviously well-tested, but has a fatal flaw: it can call
-//    malloc() from the unwinder.  This is a problem because we're
-//    trying to use the unwinder to instrument malloc().
-//
-// Note: if you add a new implementation here, make sure it works
-// correctly when GetStackTrace() is called with max_depth == 0.
-// Some code may do that.
-
-#if defined(HAVE_LIB_UNWIND)
-# define STACKTRACE_H "stacktrace_libunwind-inl.h"
-#elif !defined(NO_FRAME_POINTER)
-# if defined(__i386__) && __GNUC__ >= 2
-#  define STACKTRACE_H "stacktrace_x86-inl.h"
-# elif defined(__x86_64__) && __GNUC__ >= 2 && HAVE_UNWIND_H
-#  define STACKTRACE_H "stacktrace_x86_64-inl.h"
-# elif (defined(__ppc__) || defined(__PPC__)) && __GNUC__ >= 2
-#  define STACKTRACE_H "stacktrace_powerpc-inl.h"
-# endif
-#endif
-
-#if !defined(STACKTRACE_H) && defined(HAVE_EXECINFO_H)
-# define STACKTRACE_H "stacktrace_generic-inl.h"
-#endif
-
-#if defined(STACKTRACE_H)
-# define HAVE_STACKTRACE
-#endif
-
-// defined by gcc
-#if defined(__ELF__) && defined(OS_LINUX)
-# define HAVE_SYMBOLIZE
-#elif defined(OS_MACOSX) && defined(HAVE_DLADDR)
-// Use dladdr to symbolize.
-# define HAVE_SYMBOLIZE
-#endif
-
 #ifndef ARRAYSIZE
 // There is a better way, but this is good enough for our purpose.
 # define ARRAYSIZE(a) (sizeof(a) / sizeof(*(a)))
