--- share/args/all_opt.c.orig	Sun Sep 26 17:35:02 2004
+++ share/args/all_opt.c	Sun Jul 16 12:07:07 2006
@@ -19,6 +19,7 @@
  */
 
 #include <stdlib.h>
+#include <limits.h>
 #include <string.h>
 
 #include <all_opt.h>
@@ -33,7 +34,7 @@
 static int addinst(struct ao_opt *opt, int nparam, char **params);
 static int countparam(OPT *aod, struct ao_opt *opt, char **argv);
 static int mutexchk(struct ao_opt *opt);
-static int strtonum(const char *str, int *pnum);
+static int istrtonum(const char *str, int *pnum);
 static struct ao_opt *findopt(OPT *desc, const char *optstr);
 
 
@@ -652,7 +653,7 @@
 /*
  * If a number, assume '#' option.
  */
-		else if (strtonum(++str, &num) == 0) {
+		else if (istrtonum(++str, &num) == 0) {
 
 			popt = findopt(aod, "#");
 			if ((popt == 0) || (mutexchk(popt))) {
@@ -884,7 +885,7 @@
 
 
 /*
- *	strtonum
+ *	istrtonum
  *
  *	Function:	- convert string to number if possible
  *			- handles decimal/octal/hexadecimal
@@ -894,7 +895,7 @@
  *	Returns:	- 0 or LAMERROR
  */
 static int
-strtonum(const char *str, int *pnum)
+istrtonum(const char *str, int *pnum)
 {
 	char		*endstr;		/* end of parsed string */
 
@@ -956,7 +957,7 @@
 
 		if (strcmp(string, "--") == 0) break;
 
-		if ((strtonum(string + 1, &num) == 0) &&
+		if ((istrtonum(string + 1, &num) == 0) &&
 				(findopt(aod, "#") != 0)) break;
 
 		if (findopt(aod, string + 1)) break;
@@ -1036,7 +1037,7 @@
 	for (; nparam > 0; --nparam, ++params, parmbuf += size) {
 
 		if (fl_int) {
-			if (strtonum(*params, &num)) {
+			if (istrtonum(*params, &num)) {
 				errno = EUSAGE;
 				return(LAMERROR);
 			}
