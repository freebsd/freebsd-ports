--- applications/lwsrv/simple.c.orig	Sat Mar 20 12:03:13 2004
+++ applications/lwsrv/simple.c	Sat Mar 20 12:06:30 2004
@@ -139,8 +139,7 @@
   byte changeecho;
 #endif /* LWSRV8 */
 } toktbl[] =  {
-#ifndef LWSRV8
 #define TOKEN(token, tag) { (token), (sizeof(token)-1), (tag)}
   TOKEN("%%EOF", TOK_DROP),
   TOKEN("%%Title", TOK_TIT),
   TOKEN("%%Creator", TOK_CRE),
@@ -161,84 +159,24 @@
   TOKEN("%%BeginProcSet", TOK_BPS),
   TOKEN("%%EndProcSet", TOK_EPS),
   TOKEN("%%?BeginPrinterQuery", TOK_BEGINR),
   TOKEN("%%?EndPrinterQuery", TOK_ENDR),
   TOKEN("%%?BeginQuery", TOK_BEGINR),
   TOKEN("%%?EndQuery", TOK_ENDR),
-#else /* LWSRV8 */
-/* Now in SORTED order, because we do a binary search on it */
-#define TOKEN(token, tag, e) {(token), (tag), (sizeof(token)-1), (e)}
-  TOKEN("%!PS-Adobe-", TOK_PSA, ECHO_OFF),
-  TOKEN("%%?BeginFeatureQuery", TOK_BFEQ, ECHO_UNCHANGED),
-  TOKEN("%%?BeginFileQuery", TOK_BFIQ, ECHO_UNCHANGED),
-  TOKEN("%%?BeginFontListQuery", TOK_BFLQ, ECHO_UNCHANGED),
-  TOKEN("%%?BeginFontQuery", TOK_BFOQ, ECHO_UNCHANGED),
-  TOKEN("%%?BeginPrinterQuery", TOK_BPRQ, ECHO_UNCHANGED),
-  TOKEN("%%?BeginProcSetQuery", TOK_BPSQ, ECHO_UNCHANGED),
-  TOKEN("%%?BeginQuery", TOK_BQU, ECHO_UNCHANGED),
-  TOKEN("%%?BeginResourceListQuery", TOK_BRLQ, ECHO_UNCHANGED),
-  TOKEN("%%?BeginResourceQuery", TOK_BREQ, ECHO_UNCHANGED),
-  TOKEN("%%?BeginVMStatus", TOK_BVQ, ECHO_UNCHANGED),
-  TOKEN("%%?EndFeatureQuery", TOK_EFEQ, ECHO_UNCHANGED),
-  TOKEN("%%?EndFileQuery", TOK_EFIQ, ECHO_UNCHANGED),
-  TOKEN("%%?EndFontListQuery", TOK_EFLQ, ECHO_UNCHANGED),
-  TOKEN("%%?EndFontQuery", TOK_EFOQ, ECHO_UNCHANGED),
-  TOKEN("%%?EndPrinterQuery", TOK_EPRQ, ECHO_UNCHANGED),
-  TOKEN("%%?EndProcSetQuery", TOK_EPSQ, ECHO_UNCHANGED),
-  TOKEN("%%?EndQuery", TOK_EQU, ECHO_UNCHANGED),
-  TOKEN("%%?EndResourceListQuery", TOK_ERLQ, ECHO_UNCHANGED),
-  TOKEN("%%?EndResourceQuery", TOK_EREQ, ECHO_UNCHANGED),
-  TOKEN("%%?EndVMStatus", TOK_EVQ, ECHO_UNCHANGED),
-  TOKEN("%%BeginExitServer", TOK_BEGIN, ECHO_OFF),
-  TOKEN("%%BeginProcSet", TOK_BPS, ECHO_OFF),
-  TOKEN("%%Creator", TOK_CRE, ECHO_UNCHANGED),
-  TOKEN("%%EOF", TOK_TEOF, ECHO_DROP),
-  TOKEN("%%EndComments", TOK_ENC, ECHO_UNCHANGED),
-  TOKEN("%%EndExitServer", TOK_END, ECHO_ON),
-  TOKEN("%%EndProcSet", TOK_EPS, ECHO_ON),
-  TOKEN("%%For", TOK_FOR, ECHO_UNCHANGED),
-#endif /* LWSRV8 */
 #ifdef ADOBE_DSC2_CONFORMANT
-#ifndef LWSRV8
   TOKEN("%%IncludeProcSet", TOK_IPS),
-#else /* LWSRV8 */
-  TOKEN("%%IncludeProcSet", TOK_IPS, ECHO_UNCHANGED),
-#endif /* LWSRV8 */
 #else  ADOBE_DSC2_CONFORMANT
-#ifndef LWSRV8
   TOKEN("%%IncludeProcSet", TOK_IPS|TOK_INVALID),
-#else /* LWSRV8 */
-  TOKEN("%%IncludeProcSet", TOK_IPS|TOK_INVALID, ECHO_UNCHANGED),
-#endif /* LWSRV8 */
 #endif ADOBE_DSC2_CONFORMANT
-#ifndef LWSRV8
 #ifdef PAGECOUNT
   TOKEN("%%Pages", TOK_PGS),
 #endif PAGECOUNT
-#else /* LWSRV8 */
-  TOKEN("%%Page:", TOK_PAGE, ECHO_UNCHANGED),
-  TOKEN("%%Pages", TOK_PGS, ECHO_UNCHANGED),
-#endif /* LWSRV8 */
 #ifdef PROCSET_PATCH
-#ifndef LWSRV8
   TOKEN("%%Patches", TOK_PATCH),
-#else /* LWSRV8 */
-  TOKEN("%%Patches", TOK_PATCH, ECHO_OFF),
-#endif /* LWSRV8 */
 #endif PROCSET_PATCH
-#ifdef LWSRV8
-  TOKEN("%%Title", TOK_TIT, ECHO_UNCHANGED),
-#endif /* LWSRV8 */
-  /* very old type of queries */
-#ifndef LWSRV8
   TOKEN("%?appledict version #", TOK_ADV),
-  TOKEN("%?fontList", TOK_FLS),
   TOKEN("%?end",TOK_ENDOLD),
-  {NULL, TOK_UNK, 0}
-#else /* LWSRV8 */
-  TOKEN("%?appledict version #", TOK_ADV, ECHO_OFF),
-  TOKEN("%?end",TOK_ENDOLD, ECHO_ON),
-  TOKEN("%?fontList", TOK_FLS, ECHO_OFF),
-#endif /* LWSRV8 */
+  TOKEN("%?fontList", TOK_FLS),
+  {NULL, TOK_UNK, 0}
 };
 
 #ifndef LWSRV8
