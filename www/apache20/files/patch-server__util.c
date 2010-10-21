--- ./server/util.c.orig	2006-07-12 07:40:55.000000000 +0000
+++ ./server/util.c	2010-10-21 05:40:53.646625433 +0000
@@ -247,25 +247,25 @@
 }
 
 /*
- * Here's a pool-based interface to POSIX regex's regcomp().
- * Note that we return regex_t instead of being passed one.
- * The reason is that if you use an already-used regex_t structure,
+ * Here's a pool-based interface to the POSIX-esque ap_regcomp().
+ * Note that we return ap_regex_t instead of being passed one.
+ * The reason is that if you use an already-used ap_regex_t structure,
  * the memory that you've already allocated gets forgotten, and
  * regfree() doesn't clear it. So we don't allow it.
  */
 
 static apr_status_t regex_cleanup(void *preg)
 {
-    regfree((regex_t *) preg);
+    ap_regfree((ap_regex_t *) preg);
     return APR_SUCCESS;
 }
 
-AP_DECLARE(regex_t *) ap_pregcomp(apr_pool_t *p, const char *pattern,
-                                   int cflags)
+AP_DECLARE(ap_regex_t *) ap_pregcomp(apr_pool_t *p, const char *pattern,
+                                     int cflags)
 {
-    regex_t *preg = apr_palloc(p, sizeof(regex_t));
+    ap_regex_t *preg = apr_palloc(p, sizeof *preg);
 
-    if (regcomp(preg, pattern, cflags)) {
+    if (ap_regcomp(preg, pattern, cflags)) {
         return NULL;
     }
 
@@ -275,9 +275,9 @@
     return preg;
 }
 
-AP_DECLARE(void) ap_pregfree(apr_pool_t *p, regex_t * reg)
+AP_DECLARE(void) ap_pregfree(apr_pool_t *p, ap_regex_t *reg)
 {
-    regfree(reg);
+    ap_regfree(reg);
     apr_pool_cleanup_kill(p, (void *) reg, regex_cleanup);
 }
 
@@ -344,29 +344,10 @@
     return bigstring;
 }
 
-/* 
- * Apache stub function for the regex libraries regexec() to make sure the
- * whole regex(3) API is available through the Apache (exported) namespace.
- * This is especially important for the DSO situations of modules.
- * DO NOT MAKE A MACRO OUT OF THIS FUNCTION!
- */
-AP_DECLARE(int) ap_regexec(regex_t *preg, const char *string,
-                           size_t nmatch, regmatch_t pmatch[], int eflags)
-{
-    return regexec(preg, string, nmatch, pmatch, eflags);
-}
-
-AP_DECLARE(size_t) ap_regerror(int errcode, const regex_t *preg, char *errbuf,
-                               size_t errbuf_size)
-{
-    return regerror(errcode, preg, errbuf, errbuf_size);
-}
-
-
 /* This function substitutes for $0-$9, filling in regular expression
  * submatches. Pass it the same nmatch and pmatch arguments that you
  * passed ap_regexec(). pmatch should not be greater than the maximum number
- * of subexpressions - i.e. one more than the re_nsub member of regex_t.
+ * of subexpressions - i.e. one more than the re_nsub member of ap_regex_t.
  *
  * input should be the string with the $-expressions, source should be the
  * string that was matched against.
@@ -379,7 +360,7 @@
 
 AP_DECLARE(char *) ap_pregsub(apr_pool_t *p, const char *input,
                               const char *source, size_t nmatch,
-                              regmatch_t pmatch[])
+                              ap_regmatch_t pmatch[])
 {
     const char *src = input;
     char *dest, *dst;
