--- ispell.h.orig	Sat Feb 22 13:53:04 2003
+++ ispell.h	Sat Feb 22 14:11:29 2003
@@ -702,6 +702,7 @@
 INIT (int deftflag, -1);		/* Default deformatting mode, chosen */
 					/* ..from DEFORMAT_* values */
 INIT (int tflag, DEFTEXFLAG);		/* Deformatting for current file */
+INIT (int uflag, 0);			/* NZ if -u (spell compat) option */
 INIT (int prefstringchar, -1);		/* Preferred string character type */
 
 INIT (int insidehtml, 0);		/* Flag to indicate we're amid HTML */
