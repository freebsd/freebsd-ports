unicode_value (uint16) can not possibly exceed 0xFFFF. Remove
the statement, that triggers a compiler warning.

--- shared_libs/iconv/iconv.c	Tue Mar 30 11:38:44 2004
+++ shared_libs/iconv/iconv.c	Thu Jul  7 16:49:57 2005
@@ -1000,7 +1000,4 @@
 	/* Add unicode value */
 
-	if (ch->p->a.g1->unicode_value > 0xFFFF)
-	    return;
-	
 	/* NOTE:  str->p->a.words is not NUL terminated        */
 	str->p->a.words = safe_realloc(str->p->a.words,
