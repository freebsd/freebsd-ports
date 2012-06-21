--- lib/FXAtomic.cpp.orig	2012-04-27 18:46:09.000000000 +0200
+++ lib/FXAtomic.cpp	2012-06-21 15:22:43.000000000 +0200
@@ -298,7 +298,7 @@
   LONGLONG duet[2]={(LONGLONG)a,(LONGLONG)b};
   return (_InterlockedCompareExchange128((LONGLONG volatile*)ptr,(LONGLONG)cmpb,(LONGLONG)cmpa,duet));
 #elif (defined(HAVE_INLINE_ASSEMBLY) && defined(__i386__))
-#if (defined(__PIC__) || defined(__PIE__)
+#if defined(__PIC__) || defined(__PIE__)
   register FXbool ret;
   __asm__ __volatile__ ("xchgl  %%esi, %%ebx\n\t"
                         "lock\n\t"
@@ -308,7 +308,7 @@
                         "xchgl  %%esi, %%ebx\n\t" : "=a"(ret) : "D"(ptr), "a"(cmpa), "d"(cmpb), "S"(a), "c"(b) : "memory", "cc");
   return ret;
 #else
-  register TBool ret;
+  register FXbool ret;
   __asm__ __volatile__ ("lock\n\t"
                         "cmpxchg8b (%1)\n\t"
                         "setz   %%al\n\t"
