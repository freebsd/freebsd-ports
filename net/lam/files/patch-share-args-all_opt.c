--- share/args/all_opt.c.orig	Wed May 17 17:31:19 2006
+++ share/args/all_opt.c	Wed May 17 17:43:55 2006
@@ -21,6 +21,7 @@
  */
 
 #include <stdlib.h>
+#include <limits.h>
 #include <string.h>
 
 #include <all_opt.h>
@@ -34,7 +35,7 @@
 static int addinst(struct ao_opt *opt, int nparam, char **params);
 static int countparam(OPT *aod, struct ao_opt *opt, char **argv);
 static int mutexchk(struct ao_opt *opt);
-static int strtonum(char *str, int *pnum);
+static int istrtonum(char *str, int *pnum);
 static struct ao_opt *findopt(OPT *desc, char *optstr);
 
 
@@ -481,7 +482,7 @@
 /*
  * If a number, assume '#' option.
  */
-		else if (strtonum(++str, &num) == 0) {
+		else if (istrtonum(++str, &num) == 0) {
 
 			popt = findopt(aod, "#");
 			if ((popt == 0) || (mutexchk(popt))) {
@@ -650,7 +651,7 @@
 }
 
 /*
- *	strtonum
+ *	istrtonum
  *
  *	Function:	- convert string to number if possible
  *			- handles decimal/octal/hexadecimal
@@ -660,7 +661,7 @@
  *	Returns:	- 0 or LAMERROR
  */
 static int
-strtonum(char *str, int *pnum)
+istrtonum(char *str, int *pnum)
 {
 	char		*endstr;		/* end of parsed string */
 
@@ -720,7 +721,7 @@
 
 		if (strcmp(string, "--") == 0) break;
 
-		if ((strtonum(string + 1, &num) == 0) &&
+		if ((istrtonum(string + 1, &num) == 0) &&
 				(findopt(aod, "#") != 0)) break;
 
 		if (findopt(aod, string + 1)) break;
@@ -799,7 +800,7 @@
 	for (; nparam > 0; --nparam, ++params, parmbuf += size) {
 
 		if (fl_int) {
-			if (strtonum(*params, &num)) {
+			if (istrtonum(*params, &num)) {
 				errno = EUSAGE;
 				return(LAMERROR);
 			}
