--- ./src/lib/libast/string/tokscan.c.orig	2013-12-28 22:16:20.000000000 +0100
+++ ./src/lib/libast/string/tokscan.c	2013-12-28 22:43:28.000000000 +0100
@@ -188,6 +188,7 @@
 	char**		p_string;
 	char*		prv_f = 0;
 	va_list		prv_ap;
+	va_listarg	tmpval;
 
 	va_start(ap, fmt);
 	if (!*s || *s == '\n')
@@ -233,7 +234,8 @@
 			prv_f = f;
 			f = va_arg(ap, char*);
 			va_copy(prv_ap, ap);
-			va_copy(ap, va_listval(va_arg(ap, va_listarg)));
+			tmpval = va_listval(va_arg(ap, va_listarg));
+			va_copy(ap, tmpval);
 			continue;
 		case 'c':
 			p_char = va_arg(ap, char*);
