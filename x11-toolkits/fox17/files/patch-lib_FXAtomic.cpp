--- lib/FXAtomic.cpp.orig	2010-09-27 15:06:25.000000000 +0000
+++ lib/FXAtomic.cpp	2010-09-27 15:29:53.000000000 +0000
@@ -323,7 +323,7 @@
                         "movl %%esi,%%ebx\n\t"                  // Swap ESI back to restore EBX
                         "setz %0\n\t" : "=a"(ret), "=D"(ptr) : "D"(ptr), "a"(cmpa), "d"(cmpb), "S"(a), "c"(b) : "memory", "cc");
   return ret;
-#elif (defined(HAVE_INLINE_ASSEMBLY) && defined(__x86_64__))
+#elif (defined(HAVE_INLINE_ASSEMBLY) && defined(__x86_64__)) && !defined(__FreeBSD__)
   register FXbool ret;
   // CMPXCHG16B: if(RDX:RAX == MEM128){ MEM128 = RCX:RBX } else { RDX:RAX = MEM128; }
   __asm__ __volatile__ ("lock\n\t"
