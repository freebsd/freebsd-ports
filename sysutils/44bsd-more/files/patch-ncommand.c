--- ncommand.c.orig	2011-09-08 01:02:56.000000000 +0800
+++ ncommand.c	2011-09-08 01:19:11.000000000 +0800
@@ -231,6 +231,7 @@ donextcommand:
  */
 
 static char *readvar();
+static const char *getvar(char *, int);
 
 #define NCTXTS 128
 void *getstr_ctxts[NCTXTS];  /* could easily be made dynamic... */
@@ -580,6 +581,7 @@ gettog(const char **line, int nopts, ...
  * also be set to a corresponding value.  The optnumb argument had better
  * be within the correct range (between 0 and 2 in the above example)!!
  */
+void
 settog(const char *varname, int optval, int nargs, ...)
 {
 	va_list opts;
@@ -613,7 +615,6 @@ readvar(line)
 {
 	int vlength;
 	char *vstart;
-	static char *getvar();
 
 	if (**line != '{') {
 		SETERR (E_BADVAR);
