--- src/lib/libast/hash/hashalloc.c.orig	2021-04-21 15:44:15 UTC
+++ src/lib/libast/hash/hashalloc.c
@@ -49,6 +49,7 @@ hashalloc(Hash_table_t* ref, ...)
 	va_list*		vp = va;
 	Hash_region_f		region = 0;
 	void*			handle;
+	va_listarg		tmpval;
 
 	va_start(ap, ref);
 
@@ -159,7 +160,8 @@ hashalloc(Hash_table_t* ref, ...)
 				va_copy(ap, np);
 			}
 #else
-			va_copy(ap, va_listval(va_arg(ap, va_listarg)));
+			tmpval = va_listval(va_arg(ap, va_listarg));
+			va_copy(ap, tmpval);
 #endif
 			break;
 		case 0:
