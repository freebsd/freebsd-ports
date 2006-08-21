--- ./otb/lamcheckpoint/lamcheckpoint.c.orig	Fri Feb 24 00:26:54 2006
+++ ./otb/lamcheckpoint/lamcheckpoint.c	Sun Jul 16 12:31:41 2006
@@ -36,7 +36,7 @@
 OPT *ad;
 int param_crlam;
 
-static int strtonum(const char *, pid_t *);
+static int istrtonum(const char *, pid_t *);
 
 /*
  * main
@@ -80,7 +80,7 @@
 
   pid_arg = ao_param(ad, "pid", 0, 0);
  
-  if (strtonum(pid_arg, &pid) != 0) {
+  if (istrtonum(pid_arg, &pid) != 0) {
     show_help("lamcheckpoint", "usage", NULL);
     lam_ssi_base_close();
     ao_free(ad);
@@ -125,7 +125,7 @@
 
 
 /*
- *	strtonum
+ *	istrtonum
  *
  *	Function:	- convert string to number if possible
  *			- handles decimal/octal/hexadecimal
@@ -135,7 +135,7 @@
  *	Returns:	- 0 or LAMERROR
  */
 static int
-strtonum(const char *str, pid_t *pnum)
+istrtonum(const char *str, pid_t *pnum)
 {
 	char		*endstr;		/* end of parsed string */
 
