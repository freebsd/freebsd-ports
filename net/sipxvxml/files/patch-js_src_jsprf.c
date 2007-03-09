--- js/src/jsprf.c.orig	Thu Mar  8 08:30:24 2007
+++ js/src/jsprf.c	Thu Mar  8 08:39:24 2007
@@ -644,7 +644,7 @@
 	    continue;
 	}
 
-	VARARGS_ASSIGN(nas[cn].ap, ap);
+	va_copy(nas[cn].ap, ap);
 
 	switch( nas[cn].type ){
 	case TYPE_INT16:
