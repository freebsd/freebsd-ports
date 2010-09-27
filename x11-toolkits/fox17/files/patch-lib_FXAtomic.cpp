--- lib/FXAtomic.cpp.orig	2010-09-18 00:09:37.000000000 +0000
+++ lib/FXAtomic.cpp	2010-09-27 18:35:26.000000000 +0000
@@ -101,7 +101,7 @@
 // Have API to find out which.
 
 // If neither windows, nor inline assembly, then fallback to global mutex
-#if !(defined(WIN32) || (defined(HAVE_INLINE_ASSEMBLY) && (defined(__i386__) || defined(__x86_64__))))
+#if !(defined(WIN32) || (defined(HAVE_INLINE_ASSEMBLY) && (defined(__i386__) || defined(__x86_64__)))) || defined(__FreeBSD__)
 static pthread_mutex_t global_mutex=PTHREAD_MUTEX_INITIALIZER;
 #endif
 
@@ -323,7 +323,7 @@
                         "movl %%esi,%%ebx\n\t"                  // Swap ESI back to restore EBX
                         "setz %0\n\t" : "=a"(ret), "=D"(ptr) : "D"(ptr), "a"(cmpa), "d"(cmpb), "S"(a), "c"(b) : "memory", "cc");
   return ret;
-#elif (defined(HAVE_INLINE_ASSEMBLY) && defined(__x86_64__))
+#elif (defined(HAVE_INLINE_ASSEMBLY) && defined(__x86_64__)) && !defined(__FreeBSD__)
   register FXbool ret;
   // CMPXCHG16B: if(RDX:RAX == MEM128){ MEM128 = RCX:RBX } else { RDX:RAX = MEM128; }
   __asm__ __volatile__ ("lock\n\t"
