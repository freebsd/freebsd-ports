diff -u -x CVS -x work -x core -x *.core -x #* -x *~ -x *.orig -x *.rej -I $Id.*$ -I $.+BSD.*$ ctype.h.orig ctype.h
--- ctype.h.orig	Fri Jun  4 02:51:01 2004
+++ ctype.h	Sat Jun 19 18:42:22 2004
@@ -66,7 +66,7 @@
 #define _IDCH	(T_IDC|T_DIG)
 #define _META	(T_SPC|T_DIP|T_MET|T_EOR)
 
-char	_ctype1[];
+extern char	_ctype1[];
 
 /* nb these args are not call by value !!!! */
 #define	space(c)	(((c)&QUOTE)==0 ANDF _ctype1[c]&(T_SPC))
@@ -77,10 +77,12 @@
 #define subchar(c)	(((c)&QUOTE)==0 ANDF _ctype1[c]&(T_SUB|T_QOT))
 #define escchar(c)	(((c)&QUOTE)==0 ANDF _ctype1[c]&(T_ESC))
 
-char	_ctype2[];
+extern char	_ctype2[];
 
 #define	digit(c)	(((c)&QUOTE)==0 ANDF _ctype2[c]&(T_DIG))
+#ifndef SYSIII
 #define fngchar(c)	(((c)&QUOTE)==0 ANDF _ctype2[c]&(T_FNG))
+#endif
 #define dolchar(c)	(((c)&QUOTE)==0 ANDF _ctype2[c]&(T_AST|T_BRC|T_DIG|T_IDC|T_SHN))
 #define defchar(c)	(((c)&QUOTE)==0 ANDF _ctype2[c]&(T_DEF))
 #define setchar(c)	(((c)&QUOTE)==0 ANDF _ctype2[c]&(T_SET))
