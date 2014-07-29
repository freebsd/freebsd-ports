--- FileNom.h.orig	Thu Nov 25 08:11:06 1993
+++ FileNom.h	Tue Sep 23 20:03:16 1997
@@ -52,7 +52,9 @@
 
 #define XtNselectCallback "selectCallback"
 #define XtNselectMenu "selectMenu"
+#ifndef XtNcancelCallback
 #define XtNcancelCallback "cancelCallback"
+#endif
 #define XtNmargin "margin"
 #define XtNnumberRows "numberRows"
 #define XtNshowDotFiles "showDotFiles"
