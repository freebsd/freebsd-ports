diff -u -x CVS -x work -x core -x *.core -x #* -x *~ -x *.orig -x *.rej -I $Id.*$ -I $.+BSD.*$ ctype.c.orig ctype.c
--- ctype.c.orig	Fri Jun  4 02:51:01 2004
+++ ctype.c	Sat Jun 19 18:42:22 2004
@@ -9,7 +9,7 @@
 
 #include	"defs.h"
 
-char	_ctype1[] {
+char	_ctype1[]={
 /*	000	001	002	003	004	005	006	007	*/
 	_EOF,	0,	0,	0,	0,	0,	0,	0,
 
@@ -58,7 +58,7 @@
 };
 
 
-char	_ctype2[] {
+char	_ctype2[]={
 /*	000	001	002	003	004	005	006	007	*/
 	0,	0,	0,	0,	0,	0,	0,	0,
 
@@ -91,7 +91,11 @@
 	_UPC,	_UPC,	_UPC,	_UPC,	_UPC,	_UPC,	_UPC,	_UPC,
 
 /*	X	Y	Z	[	\	]	^	_	*/
+#if defined(SYSIII)
+	_UPC,	_UPC,	_UPC,	0,	0,	0,	0,	_UPC,
+#else /* V7 */
 	_UPC,	_UPC,	_UPC,	_SQB,	0,	0,	0,	_UPC,
+#endif
 
 /*	`	a	b	c	d	e	f	g	*/
 	0,	_LPC,	_LPC,	_LPC,	_LPC,	_LPC,	_LPC,	_LPC,
