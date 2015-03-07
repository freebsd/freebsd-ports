--- src/base/cl_low.h.orig	2015-01-28 09:25:18 UTC
+++ src/base/cl_low.h
@@ -207,7 +207,7 @@ inline uint32 mulu32_unchecked (uint32 a
   // declared inside a namespace!
 } extern "C" uint32 mulu32_high; namespace cln {        // -> High-Teil
 #else
-  extern "C" uint32 mulu32_high;                        // -> High-Teil
+}  extern "C" uint32 mulu32_high; namespace cln {       // -> High-Teil
 #endif
 #if defined(__GNUC__) && defined(__m68k__) && !defined(NO_ASM)
   #define mulu32(x,y,hi_zuweisung,lo_zuweisung)  \
@@ -439,7 +439,7 @@ inline uint32 mulu32_unchecked (uint32 a
   // Workaround MSVC compiler bug.
 } extern "C" uint16 divu_16_rest; namespace cln {         // -> Rest r
 #else
-  extern "C" uint16 divu_16_rest;                         // -> Rest r
+}  extern "C" uint16 divu_16_rest; namespace cln {        // -> Rest r
 #endif
 #endif
 #if defined(__GNUC__) && defined(__sparc64__) && !defined(NO_ASM)
@@ -589,7 +589,7 @@ inline uint32 mulu32_unchecked (uint32 a
   // Workaround MSVC compiler bug.
 } extern "C" uint32 divu_32_rest; namespace cln {         // -> Rest r
 #else
-  extern "C" uint32 divu_32_rest;                         // -> Rest r
+}  extern "C" uint32 divu_32_rest; namespace cln {        // -> Rest r
 #endif
 #if defined(__GNUC__) && defined(__sparc64__) && !defined(NO_ASM)
   #define divu_3232_3232(x,y,q_zuweisung,r_zuweisung)  \
