--- src/lib/libast/string/tokscan.c.orig	2006-11-07 22:29:31 UTC
+++ src/lib/libast/string/tokscan.c
@@ -233,7 +233,16 @@ tokscan(register char* s, char** nxt, co
 			prv_f = f;
 			f = va_arg(ap, char*);
 			va_copy(prv_ap, ap);
+#if __clang__ && __SIZEOF_POINTER__ == 4
+			{
+				va_list		np;
+
+				np = va_listval(va_arg(ap, va_listarg));
+				va_copy(ap, np);
+			}
+#else
 			va_copy(ap, va_listval(va_arg(ap, va_listarg)));
+#endif
 			continue;
 		case 'c':
 			p_char = va_arg(ap, char*);
