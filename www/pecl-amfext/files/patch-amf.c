--- amf.c	2008-07-18 10:28:36.000000000 +0000
+++ amf.c	2015-04-14 14:14:23.000000000 -0400
@@ -33,5 +33,5 @@
 /*  module Declarations {{{1*/
 
-static function_entry amf_functions[] = {
+static zend_function_entry amf_functions[] = {
     PHP_FE(amf_encode, NULL)
     PHP_FE(amf_decode, NULL)
@@ -827,5 +827,5 @@
 {
 #ifndef amf_DISABLE_OUTPUT
-	const int len = Z_STRLEN_P(zstr);
+	int len = Z_STRLEN_P(zstr);
 	if(len == 0)
 	{
@@ -845,5 +845,5 @@
 		buf->last_chunk->size = 1;  /*  zval chun */
 		buf->last_chunk->zv = zstr;
-		ZVAL_ADDREF(zstr);
+		Z_ADDREF_P(zstr);
 		buf->chunks++;
 		buf->left_in_part -= sizeof(amf_string_chunk);
@@ -1013,6 +1013,6 @@
 	{
 		ulong var_no = var_hash->nextClassIndex++;
-		const int isDynamic = AMF_CLASS_DYNAMIC;
-		const int isExternalizable = 0;  /*  AMF_CLASS_EXTERNALIZABL */
+		int isDynamic = AMF_CLASS_DYNAMIC;
+		int isExternalizable = 0;  /*  AMF_CLASS_EXTERNALIZABL */
 		
 		zend_hash_add(&(var_hash->classes), (char*)className, classNameLen, &var_no, sizeof(var_no), NULL);			
@@ -1037,5 +1037,5 @@
 		{
 			char txt[20];
-			sprintf(txt,"%d",keyIndex);
+			sprintf(txt, "%lu", keyIndex);
 			amf3_write_string(buf,txt,strlen(txt), AMF_STRING_AS_SAFE_TEXT,var_hash TSRMLS_CC);
 		}
@@ -1186,5 +1186,5 @@
 		int resultValueLength = 0;
 		zval** resultValue = struc;
-		int deallocResult = (*struc)->refcount;
+		Z_REFCOUNT_P(*struc);
 
 		resultType = amf_perform_serialize_callback(struc, &className,&classNameLen,&resultValue,var_hash TSRMLS_CC);
@@ -1516,16 +1516,21 @@
 	else if(value < 0x4000)
 	{
-		amf_write_byte(buf,value >> 7 & 0x7f | 0x80);
-		amf_write_byte(buf,value & 0x7f);
+		amf_write_byte(buf, (value >> 7 & 0x7f) | 0x80);
+		amf_write_byte(buf, value & 0x7f);
 	}
 	else if(value < 0x200000)
 	{
-		amf_write_byte(buf,value >> 14 & 0x7f | 0x80);
-		amf_write_byte(buf,value >> 7 & 0x7f | 0x80);
-		amf_write_byte(buf,value & 0x7f);
+		amf_write_byte(buf, (value >> 14 & 0x7f) | 0x80);
+		amf_write_byte(buf, (value >> 7 & 0x7f) | 0x80);
+		amf_write_byte(buf, value & 0x7f);
 	} 
 	else
 	{
-		char tmp[4] = { value >> 22 & 0x7f | 0x80, value >> 15 & 0x7f | 0x80, value >> 8 & 0x7f | 0x80, value & 0xff };
+		char tmp[4] = {
+			(value >> 22 & 0x7f) | 0x80,
+			(value >> 15 & 0x7f) | 0x80,
+			(value >> 8 & 0x7f) | 0x80,
+			value & 0xff
+		};
 		amf_write_string(buf,tmp,4 AMFTSRMLS_CC);
 	}
@@ -2393,5 +2398,5 @@
 			pbuf = tpbuf;
 			asSB = 1;
-			 /* ZVAL_ADDREF(*zzOutputSB) */
+			 /* Z_ADDREF_P(*zzOutputSB) */
 			 /* return_value = *zzOutputSB */
 		}
@@ -2557,5 +2562,5 @@
 		char cval[8];
 	} d;
-	const char * cp = *p;
+	const char * cp = *(const char **)p;
 	*p += 8;
 	if((var_hash->flags & AMF_BIGENDIAN) != 0)
@@ -2593,5 +2598,5 @@
 		else
 		{
-			acc = (acc | tmp & 0x7f) << 7;
+			acc = (acc | (tmp & 0x7f)) << 7;
 			tmp = *cp++;
 			if(tmp < 128)
@@ -2601,5 +2606,5 @@
 			else
 			{
-				acc = (acc | tmp & 0x7f) << 8;
+				acc = (acc | (tmp & 0x7f)) << 8;
 				tmp = *cp++;
 				acc = acc | tmp;
@@ -2622,5 +2627,5 @@
 {
 	int slength = length == 2 ? amf_read_int16(p,max,var_hash): amf_read_int(p,max,var_hash);
-	const char * src = *p;
+	const char * src = *(const char **)p;
 	*p += slength;
 	if(slength > 0 && raw == AMF_STRING_AS_TEXT && (var_hash->flags & AMF_TRANSLATE_CHARSET) != 0)
@@ -2633,5 +2638,5 @@
 		}
 	}
-	ZVAL_STRINGL(*rval, (char*)src, slength, 1)
+	ZVAL_STRINGL(*rval, src, slength, 1);
 	return SUCCESS;
 }
@@ -2654,5 +2659,5 @@
 	else if((len & AMF_INLINE_ENTITY) != 0)
 	{
-		const char * src = *p;
+		const char * src = *(const char **)p;
 		zval * newval = NULL;
 		len >>= 1;
@@ -2662,5 +2667,5 @@
 		{
 			MAKE_STD_ZVAL(newval);
-			ZVAL_STRINGL(newval,(char*)src,len,1);
+			ZVAL_STRINGL(newval, src, len, 1);
 		}
 			
@@ -2671,5 +2676,5 @@
 		else
 		{
-			newval->refcount--;
+			Z_DELREF_P(newval);
 		}
 		*rval = newval;
@@ -2825,5 +2830,5 @@
 		if(zClassname != NULL)
 		{
-			ZVAL_ADDREF(zClassname);
+			Z_ADDREF_P(zClassname);
 			add_assoc_zval(*rval, "_explicitType",zClassname);
 		}
@@ -2842,5 +2847,5 @@
 static int amf3_unserialize_var(zval **rval, const unsigned char **p, const unsigned char *max, amf_unserialize_data_t *var_hash TSRMLS_DC)
 {
-	const int type = **p;
+	int type = **p;
 	int handle;
 
@@ -3046,5 +3051,5 @@
 				amf_array_init(zClassDef,nClassMemberCount+2 TSRMLS_CC); 
 				add_next_index_long(zClassDef,(bTypedObject?1:0)|nClassMemberCount << AMF_CLASS_MEMBERCOUNT_SHIFT |iDynamicObject|iExternalizable);
-				ZVAL_ADDREF(zClassname);
+				Z_ADDREF_P(zClassname);
 				add_next_index_zval(zClassDef, zClassname); 
 		
@@ -3057,5 +3062,5 @@
 						break;
 					}
-					ZVAL_ADDREF(zMemberName);
+					Z_ADDREF_P(zMemberName);
 					add_next_index_zval(zClassDef,zMemberName);  /*  pass referenc */
 				}
@@ -3173,5 +3178,5 @@
 						if(amf3_read_string(&zKey,p,max,1,AMF_STRING_AS_TEXT,var_hash TSRMLS_CC) == FAILURE)
 						{
-							php_error_docref(NULL TSRMLS_CC, E_NOTICE, "amf cannot understand key name %X","");
+							php_error_docref(NULL TSRMLS_CC, E_NOTICE, "amf cannot understand key name");
 							break;
 						}						
@@ -3202,5 +3207,5 @@
 					if(bTypedObject != 0)
 					{
-						ZVAL_ADDREF(zClassname);
+						Z_ADDREF_P(zClassname);
 						add_assoc_zval(*rval, "_explicitType",zClassname);
 					}
@@ -3661,5 +3666,5 @@
 
 	MAKE_STD_ZVAL(tmp);
-	ZVAL_STRINGL(tmp, (char*)cp, length,1);
+	ZVAL_STRINGL(tmp, cp, length, 1);
 	rr = direction == AMF_TO_UTF8 ? amf_perform_serialize_callback_event(AMFE_TRANSLATE_CHARSET, tmp, &r, 0, var_hash TSRMLS_CC): amf_perform_unserialize_callback(AMFE_TRANSLATE_CHARSET, tmp, &r, 0, var_hash TSRMLS_CC);
 	if(rr == SUCCESS && r != 0)
