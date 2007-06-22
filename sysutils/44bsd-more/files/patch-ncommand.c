--- ./ncommand.c.orig	2007-06-22 14:48:44.603814341 +0800
+++ ./ncommand.c	2007-06-22 14:48:44.631081101 +0800
@@ -231,6 +231,7 @@
  */
 
 static char *readvar();
+static const char *getvar(char *, int);
 
 #define NCTXTS 128
 void *getstr_ctxts[NCTXTS];  /* could easily be made dynamic... */
@@ -613,7 +614,6 @@
 {
 	int vlength;
 	char *vstart;
-	static char *getvar();
 
 	if (**line != '{') {
 		SETERR (E_BADVAR);
