--- src/lib/libast/string/tokscan.c.orig	2021-04-21 15:45:06 UTC
+++ src/lib/libast/string/tokscan.c
@@ -197,6 +197,7 @@ tokscan(register char* s, char** nxt, const char* fmt,
 	char**		p_string;
 	char*		prv_f = 0;
 	va_list		prv_ap;
+	va_listarg	tmpval;
 
 	va_start(ap, fmt);
 	if (!*s || *s == '\n')
@@ -250,7 +251,8 @@ tokscan(register char* s, char** nxt, const char* fmt,
 				va_copy(ap, np);
 			}
 #else
-			va_copy(ap, va_listval(va_arg(ap, va_listarg)));
+			tmpval = va_listval(va_arg(ap, va_listarg));
+			va_copy(ap, tmpval);
 #endif
 			continue;
 		case 'c':
