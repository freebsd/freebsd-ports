--- C/compiler.c.orig	Fri Feb 27 01:48:29 2004
+++ C/compiler.c	Thu Sep  2 17:36:25 2004
@@ -2727,12 +2727,12 @@
   volatile int maxvnum = 512;
   int botch_why;
   volatile Term my_clause = inp_clause;
+  compiler_struct cglobs;
   /* may botch while doing a different module */
 
   /* first, initialise cglobs->cint.CompilerBotch to handle all cases of interruptions */
   Yap_ErrorMessage = NULL;
   Yap_Error_Size = 0;
-  compiler_struct cglobs;
 
   if ((botch_why = setjmp(cglobs.cint.CompilerBotch)) == 3) {
     /* out of local stack, just duplicate the stack */
