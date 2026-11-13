--- cargo-crates/gmp-mpfr-sys-1.6.5/gmp-6.3.0-c/longlong.h.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/gmp-mpfr-sys-1.6.5/gmp-6.3.0-c/longlong.h
@@ -378,6 +378,9 @@ long __MPN(count_leading_zeros) (UDItype);
 #if __GNUC__ < 2
 #define __CLOBBER_CC
 #define __AND_CLOBBER_CC
+#elif HAVE_HOST_CPU_FAMILY_power || HAVE_HOST_CPU_FAMILY_powerpc
+#define __CLOBBER_CC : "cc", "xer"
+#define __AND_CLOBBER_CC , "cc", "xer"
 #else /* __GNUC__ >= 2 */
 #define __CLOBBER_CC : "cc"
 #define __AND_CLOBBER_CC , "cc"
