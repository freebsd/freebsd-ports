--- tmpl_lib.c.orig	2009-09-18 16:40:45.000000000 +0200
+++ tmpl_lib.c	2009-09-18 16:41:09.000000000 +0200
@@ -214,7 +214,7 @@
 	buf_alloc = TMPL_MAX_TAG_LEN+4;
 	buf = (uchar*)emalloc(buf_alloc);
 	/* Searching algorythm will require larger buffer */
-	ZV(tmpl->original) = (char*)erealloc(ZV(tmpl->original), 
+	Z_STRVAL_P(tmpl->original) = (char*)erealloc(ZV(tmpl->original), 
 		ZL(tmpl->original) + MAX(
 			ZL(tmpl->tag_left), MAX(
 				ZL(tmpl->tag_right), MAX(
@@ -697,7 +697,7 @@
 					/* Make a recursive call */
 					if(buf_alloc <= (unsigned)(ZL(path)+1+ZL(tag->name)+1)) {
 						while(buf_alloc <= (unsigned)(ZL(path)+1+ZL(tag->name)+1)) buf_alloc <<= 1;
-						ZV(new_path) = (char*)erealloc(ZV(new_path), buf_alloc);
+						Z_STRVAL_P(new_path) = (char*)erealloc(ZV(new_path), buf_alloc);
 					}
 					sprintf(ZV(new_path), (1 == ZL(path) && '/' == ZV(path)[0]) ? "%s%s" : "%s/%s", ZV(path), ZV(tag->name));
 					ZL(new_path) = ZL(path) + ZL(tag->name) + ((1 == ZL(path) && '/' == ZV(path)[0]) ? 0 : 1);
@@ -877,7 +877,7 @@
 			} else p = key;
 			ZVAL_STRINGL(new_value, p, (TMPL_LONG == mod) ? key_len-1 : key_len-1-(p-key), 1);
 			if((TMPL_TAG | TMPL_CONTEXT) == mask && TMPL_CONTEXT == tag->typ) {
-				ZV(new_value) = (char*)erealloc(ZV(new_value), ZL(new_value)+2);
+				Z_STRVAL_P(new_value) = (char*)erealloc(ZV(new_value), ZL(new_value)+2);
 				memcpy(ZV(new_value)+ZL(new_value), "/", 2);
 				ZL(new_value) += 1;
 			}
