--- src/lib/util/misc/scint.h.org	Sat May  4 13:26:17 2002
+++ src/lib/util/misc/scint.h	Sat May  4 13:26:30 2002
@@ -117,7 +117,7 @@
 
 # ifdef ULLONG_MAX
 //#    if ULLONG_MAX == 18446744073709551615 // 2**64 - 1
-#    if ULONGLONG_MAX == (0xffffffffffffffffuLL) // uLL reqd for xlC
+#    if ULLONG_MAX == (0xffffffffffffffffuLL) // uLL reqd for xlC
      typedef long long            sc_intmax_t;
      typedef unsigned long long   sc_uintmax_t;
      typedef long long            sc_int64_t;
