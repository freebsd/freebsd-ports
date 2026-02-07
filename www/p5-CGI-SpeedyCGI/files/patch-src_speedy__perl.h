--- src/speedy_perl.h.orig	2003-10-07 04:03:48 UTC
+++ src/speedy_perl.h
@@ -21,4 +21,4 @@ void speedy_perl_init(void);
 void speedy_perl_run(slotnum_t _gslotnum, slotnum_t _bslotnum);
 int speedy_perl_fork(void);
 
-PerlInterpreter  *my_perl;
+extern PerlInterpreter  *my_perl;
