--- ./include/httpd.h.orig	2010-10-07 22:24:15.000000000 +0000
+++ ./include/httpd.h	2010-10-21 05:40:55.841622281 +0000
@@ -41,7 +41,7 @@
 
 #include "os.h"
 
-#include "pcreposix.h"
+#include "ap_regex.h"
 
 /* Note: util_uri.h is also included, see below */
 
@@ -1523,40 +1523,15 @@
  *   @li #REG_NEWLINE  - Match-any-character operators don't match new-line
  * @return The compiled regular expression
  */
-AP_DECLARE(regex_t *) ap_pregcomp(apr_pool_t *p, const char *pattern,
-				   int cflags);
-
+AP_DECLARE(ap_regex_t *) ap_pregcomp(apr_pool_t *p, const char *pattern,
+                                     int cflags);
+    
 /**
  * Free the memory associated with a compiled regular expression
  * @param p The pool the regex was allocated from
  * @param reg The regular expression to free
  */
-AP_DECLARE(void) ap_pregfree(apr_pool_t *p, regex_t *reg);
-
-/**
- * Match a null-terminated string against a pre-compiled regex.
- * @param preg The pre-compiled regex
- * @param string The string to match
- * @param nmatch Provide information regarding the location of any matches
- * @param pmatch Provide information regarding the location of any matches
- * @param eflags Bitwise or of any of:
- *   @li #REG_NOTBOL - match-beginning-of-line operator always
- *     fails to match
- *   @li #REG_NOTEOL - match-end-of-line operator always fails to match
- * @return 0 for successful match, #REG_NOMATCH otherwise
- */ 
-AP_DECLARE(int)    ap_regexec(regex_t *preg, const char *string,
-                              size_t nmatch, regmatch_t pmatch[], int eflags);
-
-/**
- * Return the error code returned by regcomp or regexec into error messages
- * @param errcode the error code returned by regexec or regcomp
- * @param preg The precompiled regex
- * @param errbuf A buffer to store the error in
- * @param errbuf_size The size of the buffer
- */
-AP_DECLARE(size_t) ap_regerror(int errcode, const regex_t *preg, 
-                               char *errbuf, size_t errbuf_size);
+AP_DECLARE(void) ap_pregfree(apr_pool_t *p, ap_regex_t *reg);
 
 /**
  * After performing a successful regex match, you may use this function to 
@@ -1570,7 +1545,7 @@
  * @param pmatch the pmatch array returned from ap_pregex
  */
 AP_DECLARE(char *) ap_pregsub(apr_pool_t *p, const char *input, const char *source,
-                              size_t nmatch, regmatch_t pmatch[]);
+                              size_t nmatch, ap_regmatch_t pmatch[]);
 
 /**
  * We want to downcase the type/subtype for comparison purposes
