--- src/lib/bsnprintf.c.orig	2021-11-18 14:05:23 UTC
+++ src/lib/bsnprintf.c
@@ -618,6 +618,7 @@ static LDOUBLE pow10(int exp)
    return result;
 }
 
+#if !defined __FreeBSD__
 static int64_t round(LDOUBLE value)
 {
    int64_t intpart;
@@ -629,6 +630,9 @@ static int64_t round(LDOUBLE value)
 
    return intpart;
 }
+#else
+#include <math.h>
+#endif
 
 static int32_t fmtfp(char *buffer, int32_t currlen, int32_t maxlen,
                   LDOUBLE fvalue, int min, int max, int flags)
