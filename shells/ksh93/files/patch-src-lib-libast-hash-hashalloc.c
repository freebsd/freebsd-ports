--- src/lib/libast/hash/hashalloc.c.orig	2006-11-07 22:29:04 UTC
+++ src/lib/libast/hash/hashalloc.c
@@ -151,7 +151,16 @@ hashalloc(Hash_table_t* ref, ...)
 				va_copy(*vp, ap);
 				vp++;
 			}
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
 			break;
 		case 0:
 			if (vp > va)
