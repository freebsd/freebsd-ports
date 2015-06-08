--- src/modules/perl/modperl_error.h.orig	2015-05-30 17:49:12 UTC
+++ src/modules/perl/modperl_error.h
@@ -37,6 +37,7 @@ char *modperl_error_strerror(pTHX_ apr_s
 
 void modperl_croak(pTHX_ apr_status_t rc, const char* func);
 
+#ifdef USE_ITHREADS
 #define MP_PUTBACK_IF_USED() STMT_START                                 \
     {                                                                   \
         modperl_interp_t *interp = modperl_thx_interp_get(aTHX);        \
@@ -44,6 +45,9 @@ void modperl_croak(pTHX_ apr_status_t rc
             modperl_interp_unselect(interp);                            \
         }                                                               \
     } STMT_END
+#else
+#define MP_PUTBACK_IF_USED() NOOP
+#endif
 
 #define MP_CROAK_PUTBACK(rc, func) STMT_START                           \
     {                                                                   \
