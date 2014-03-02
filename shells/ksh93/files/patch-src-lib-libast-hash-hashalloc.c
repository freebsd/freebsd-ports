--- src/lib/libast/hash/hashalloc.c.orig	2013-12-28 22:09:43.000000000 +0100
+++ src/lib/libast/hash/hashalloc.c	2013-12-28 22:43:14.000000000 +0100
@@ -49,6 +49,7 @@
 	va_list*		vp = va;
 	Hash_region_f		region = 0;
 	void*			handle;
+	va_listarg		tmpval;
 
 	va_start(ap, ref);
 
@@ -151,7 +152,8 @@
 				va_copy(*vp, ap);
 				vp++;
 			}
-			va_copy(ap, va_listval(va_arg(ap, va_listarg)));
+			tmpval = va_listval(va_arg(ap, va_listarg));
+			va_copy(ap, tmpval);
 			break;
 		case 0:
 			if (vp > va)
