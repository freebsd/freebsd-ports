--- sieve/sievelex.c.orig	Mon Sep 12 10:59:53 2005
+++ sieve/sievelex.c	Wed Sep 14 20:12:03 2005
@@ -24,6 +24,8 @@
 static char const rcsid[] UNUSED =
 "$Id: sievelex.c,v 1.10 2005/09/12 08:59:53 lwa Exp $";
 
+#include <sys/types.h>
+
 #define WITH_SIEVE_REGEX
 
 #ifdef WITH_SIEVE_REGEX
@@ -1727,8 +1729,9 @@
 
 LOCAL int sieve_handle_test_list(struct sieve_state *state, int doit, int type) {
   struct token Pt;
+  int value;
   sieve_lex(state, &Pt, 0);
-  int value = (type == SIEVE_ALLOF);
+  value = (type == SIEVE_ALLOF);
   if (Pt.op == '(') {
     do {
       int test = sieve_test(state, doit);
