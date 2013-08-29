--- lib/FXAtomic.cpp.orig	2013-07-26 16:35:43.000000000 +0200
+++ lib/FXAtomic.cpp	2013-08-29 09:24:35.000000000 +0200
@@ -71,6 +71,9 @@
 #if defined( __INTEL_COMPILER ) && !defined( __ia64__ )
 #undef HAVE_BUILTIN_SYNC
 #endif
+#if defined(__FreeBSD__) && defined(__amd64__) && __FreeBSD_version < 900000
+#undef HAVE_BUILTIN_SYNC
+#endif
 #endif
 
 
@@ -393,7 +396,7 @@
                         "andl   $1, %%eax\n\t" : "=a"(ret) : "D"(ptr), "a"(cmpa), "d"(cmpb), "b"(a), "c"(b) : "memory", "cc");
   return ret;
 #endif
-#elif ((defined(__GNUC__) || defined(__INTEL_COMPILER)) && defined(__x86_64__))
+#elif ((defined(__GNUC__) || defined(__INTEL_COMPILER)) && defined(__x86_64__)) && (!defined(__FreeBSD__) || __FreeBSD_version > 900000)
   register FXbool ret;
   __asm__ __volatile__ ("lock\n\t"
                         "cmpxchg16b (%1)\n\t"
