--- ./amf.c.orig	2010-04-12 16:48:28.000000000 -0400
+++ ./amf.c	2010-04-12 16:51:32.000000000 -0400
@@ -1185,7 +1185,7 @@
 		int resultType = AMFC_TYPEDOBJECT;
 		int resultValueLength = 0;
 		zval** resultValue = struc;
-		int deallocResult = (*struc)->refcount;
+		int deallocResult = Z_REFCOUNT_P((*struc));
 
 		resultType = amf_perform_serialize_callback(struc, &className,&classNameLen,&resultValue,var_hash TSRMLS_CC);
 		
@@ -2670,7 +2670,7 @@
 		}
 		else
 		{
-			newval->refcount--;
+			Z_DELREF_P(newval);
 		}
 		*rval = newval;
 	}
