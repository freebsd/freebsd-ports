--- src/lib/bsnprintf.c	2021-08-04 23:06:43.246164000 -0500
+++ src/lib/bsnprintf.c	2021-08-04 23:07:16.549429000 -0500
@@ -618,6 +618,7 @@
    return result;
 }
 
+#if !defined __FreeBSD__
 static int64_t round(LDOUBLE value)
 {
    int64_t intpart;
@@ -629,6 +630,7 @@
 
    return intpart;
 }
+#endif
 
 static int32_t fmtfp(char *buffer, int32_t currlen, int32_t maxlen,
                   LDOUBLE fvalue, int min, int max, int flags)
