--- lib/FXAtomic.cpp.orig	2012-04-27 18:46:09.000000000 +0200
+++ lib/FXAtomic.cpp	2012-06-20 10:39:15.000000000 +0200
@@ -298,7 +298,7 @@
   LONGLONG duet[2]={(LONGLONG)a,(LONGLONG)b};
   return (_InterlockedCompareExchange128((LONGLONG volatile*)ptr,(LONGLONG)cmpb,(LONGLONG)cmpa,duet));
 #elif (defined(HAVE_INLINE_ASSEMBLY) && defined(__i386__))
-#if (defined(__PIC__) || defined(__PIE__)
+#if defined(__PIC__) || defined(__PIE__)
   register FXbool ret;
   __asm__ __volatile__ ("xchgl  %%esi, %%ebx\n\t"
                         "lock\n\t"
