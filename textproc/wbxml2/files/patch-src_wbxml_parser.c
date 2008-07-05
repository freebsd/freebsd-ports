--- src/wbxml_parser.c.orig	2006-07-11 21:47:45.000000000 +1000
+++ src/wbxml_parser.c	2008-06-15 06:59:21.000000000 +1000
@@ -153,11 +153,14 @@
 static WBXMLError parse_mb_uint32(WBXMLParser *parser, WB_ULONG *result);
 
 /* Language Specific Decoding Functions */
+static WBXMLError decode_base64_value(WBXMLBuffer **data);
+
 #if defined( WBXML_SUPPORT_SI ) || defined( WBXML_SUPPORT_EMN )
 static WBXMLError decode_datetime(WBXMLBuffer *buff);
 #endif /* WBXML_SUPPORT_SI || WBXML_SUPPORT_EMN */
 
 static WBXMLError decode_opaque_content(WBXMLParser *parser, WBXMLBuffer **data);
+static WBXMLError decode_opaque_attr_value(WBXMLParser *parser, WBXMLBuffer **data);
 
 #if defined( WBXML_SUPPORT_WV )
 static WBXMLError decode_wv_content(WBXMLParser *parser, WBXMLBuffer **data);
@@ -165,10 +168,6 @@
 static WBXMLError decode_wv_datetime(WBXMLBuffer **data);
 #endif /* WBXML_SUPPORT_WV */
 
-#if defined( WBXML_SUPPORT_DRMREL )
-static WBXMLError decode_drmrel_keyvalue(WBXMLBuffer **data);
-#endif /* WBXML_SUPPORT_DRMREL */
-
 /* Macro for error handling */
 #define CHECK_ERROR if (ret != WBXML_OK) return ret;
 
@@ -277,7 +276,7 @@
             parser->charset = WBXML_PARSER_DEFAULT_CHARSET;
       
             WBXML_WARNING((WBXML_PARSER,
-                           "No charset information found, using default : %s",
+                           "No charset information found, using default : %x",
                            WBXML_PARSER_DEFAULT_CHARSET));
         }
     }
@@ -659,12 +658,14 @@
      * Do NOT keep 'WBXML_VERSION_UNKNOWN' (0xffffffff) because only one byte will change.
      * (for example, if the version is 0x02, then parser->version will be 0xffffff02)
      */
-    parser->version = WBXML_VERSION_10;
+    WB_UTINY version = WBXML_VERSION_10;
     
-    if ((ret = parse_uint8(parser, (WB_UTINY*) &parser->version)) != WBXML_OK)
+    if ((ret = parse_uint8(parser, &version)) != WBXML_OK)
         return ret;
+    
+    parser->version = version;
 
-    WBXML_DEBUG((WBXML_PARSER, "(%d) Parsed version: '0x%X'", parser->pos - 1, (WB_TINY) parser->version));
+    WBXML_DEBUG((WBXML_PARSER, "(%d) Parsed version: 1.%d", parser->pos - 1, parser->version));
 
     return WBXML_OK;
 }
@@ -938,6 +939,8 @@
     if ((ret = parse_stag(parser, &tag, &element)) != WBXML_OK ) {
         return ret;
     }
+
+    WBXML_DEBUG((WBXML_PARSER, "<%s>", wbxml_tag_get_xml_name(element)));
   
     /* Set Current Tag */
     if (element->type == WBXML_VALUE_TOKEN) {
@@ -990,11 +993,11 @@
                                                attrs,
                                                is_empty);
     }
-      
+    
     /* Free Attributes */
     free_attrs_table(attrs);
     
-      
+    
     /* Parse *content */
     if (!is_empty) {
         /* There can be NO content */
@@ -1023,7 +1026,7 @@
             content = NULL;
         }
         
-        WBXML_DEBUG((WBXML_PARSER, "(%d) End of Element", parser->pos));
+        WBXML_DEBUG((WBXML_PARSER, "(%d) End of Element", parser->pos - 1));
         
         /* Skip END */
         parser->pos++;
@@ -1037,7 +1040,9 @@
                                              element,
                                              is_empty);
     }
-      
+    
+    WBXML_DEBUG((WBXML_PARSER, "</%s>", wbxml_tag_get_xml_name(element)));
+    
     /* Free Tag */
     wbxml_tag_destroy(element);
       
@@ -1078,7 +1083,7 @@
     WBXML_DEBUG((WBXML_PARSER, "(%d) Parsing switchPage", parser->pos));
 
     if ((WB_UTINY) parser->version < (WB_UTINY) WBXML_VERSION_12)
-        WBXML_WARNING((WBXML_PARSER, "No Switch Page mecanism possible in WBXML < %s", WBXML_VERSION_TEXT_12));
+        WBXML_WARNING((WBXML_PARSER, "No Switch Page mecanism possible in WBXML < %s (current: %d)", WBXML_VERSION_TEXT_12, (WB_UTINY) parser->version));
 
     /* Skip SWITCH_PAGE token */
     parser->pos++;
@@ -1946,7 +1951,10 @@
             WBXML_ERROR((WBXML_PARSER, "An Attribute value can't be 'opaque' in WBXML version < %s", WBXML_VERSION_TEXT_12));
         }
         
-        return parse_opaque(parser, result);
+        if ((ret = parse_opaque(parser, result)) != WBXML_OK) 
+            return ret;
+        
+        return decode_opaque_attr_value(parser, result);
     }
   
   
@@ -2209,6 +2217,40 @@
  * Language Specific Decoding Functions 
  */
 
+/**
+ * @brief Decode a BASE64 value
+ * @param data [in/out]The value to decode
+ * @return WBXML_OK if OK, another error code otherwise
+ */
+static WBXMLError decode_base64_value(WBXMLBuffer **data)
+{
+    WB_UTINY   *result = NULL;
+    WBXMLError  ret    = WBXML_OK;
+    
+    if ((data == NULL) || (*data == NULL)) {
+        return WBXML_ERROR_INTERNAL;
+    }
+    
+    if ((result = wbxml_base64_encode((const WB_UTINY *) wbxml_buffer_get_cstr(*data),
+                                      wbxml_buffer_len(*data))) == NULL)
+    {
+        return WBXML_ERROR_B64_ENC;
+    }
+    
+    /* Reset buffer */
+    wbxml_buffer_delete(*data, 0, wbxml_buffer_len(*data));
+    
+    /* Set data */
+    if (!wbxml_buffer_append_cstr(*data, result)) {
+        ret = WBXML_ERROR_NOT_ENOUGH_MEMORY;
+    }
+    
+    wbxml_free(result);
+    
+    return ret;
+}
+
+
 #if ( defined( WBXML_SUPPORT_SI ) || defined( WBXML_SUPPORT_EMN ) )
 
 /**************************************
@@ -2297,8 +2339,6 @@
  * @param parser The WBXML Parser
  * @param data The Opaque data buffer
  * @return WBXML_OK if OK, another error code otherwise
- * @note Used for:
- *      - WV 1.1 / 1.2
  */
 static WBXMLError decode_opaque_content(WBXMLParser  *parser,
                                         WBXMLBuffer **data)
@@ -2318,13 +2358,14 @@
 #if defined( WBXML_SUPPORT_DRMREL )
 
     case WBXML_LANG_DRMREL10:
+        /* ds:KeyValue */
         if ((parser->current_tag->wbxmlCodePage == 0x00) &&
             (parser->current_tag->wbxmlToken == 0x0C))
         {
             WBXMLError ret = WBXML_OK;
             
-            /* Decode <KeyValue> */
-            if ((ret = decode_drmrel_keyvalue(data)) != WBXML_OK)
+            /* Decode base64 value */ 
+            if ((ret = decode_base64_value(data)) != WBXML_OK)
                 return ret;
 
             return WBXML_OK;
@@ -2332,7 +2373,62 @@
         break;
 
 #endif /* WBXML_SUPPORT_DRMREL */    
-    
+
+#if defined( WBXML_SUPPORT_SYNCML )
+
+    case WBXML_LANG_SYNCML_SYNCML10: 
+    case WBXML_LANG_SYNCML_SYNCML11: 
+    case WBXML_LANG_SYNCML_SYNCML12: 
+        /* NextNonce */
+        if ((parser->current_tag->wbxmlCodePage == 0x01) &&
+            (parser->current_tag->wbxmlToken == 0x10)) 
+        {
+            WBXMLError ret = WBXML_OK;
+            
+            /* Decode base64 value */ 
+            if ((ret = decode_base64_value(data)) != WBXML_OK)
+                return ret;
+                
+            return WBXML_OK;
+        }
+        break;
+
+#endif /* WBXML_SUPPORT_SYNCML */    
+
+    default:
+        /* NOP */
+        break;
+    } /* switch */
+  
+    return WBXML_OK;
+}
+
+
+/**
+ * @brief Decode an Opaque Attribute Value buffer
+ * @param parser The WBXML Parser
+ * @param data The Opaque data buffer
+ * @return WBXML_OK if OK, another error code otherwise
+ */
+static WBXMLError decode_opaque_attr_value(WBXMLParser *parser, WBXMLBuffer **data)
+{
+    switch (parser->langTable->langID) 
+    {
+#if defined( WBXML_SUPPORT_OTA_SETTINGS )
+
+    case WBXML_LANG_OTA_SETTINGS:
+    {
+        WBXMLError ret = WBXML_OK;
+        
+        /* Decode base64 value */
+        if ((ret = decode_base64_value(data)) != WBXML_OK)
+            return ret; 
+
+        return WBXML_OK;
+    }
+
+#endif /* WBXML_SUPPORT_OTA_SETTINGS */ 
+
     default:
         /* NOP */
         break;
@@ -2705,49 +2801,3 @@
 }
 
 #endif /* WBXML_SUPPORT_WV */
-
-
-#if defined( WBXML_SUPPORT_DRMREL )
-
-/**************************************
- * DRMREL 1.0
- */
-
-/**
- * @brief Decode a DRMREL 'KeyValue'
- * @param data The KeyValue to decode
- * @return WBXML_OK if OK, another error code otherwise
- * @note Used for:
- *      - DRMREL 1.0
- * @note [OMA-Download-DRMREL-v1_0-20020913-C.PDF] - 7.1:
- *       "The content of the <KeyValue> element MUST be in binary format using the ‘opaque’ token."
- */
-static WBXMLError decode_drmrel_keyvalue(WBXMLBuffer **data)
-{
-    WB_UTINY   *result = NULL;
-    WBXMLError  ret    = WBXML_OK;
-  
-    if ((data == NULL) || (*data == NULL)) {
-        return WBXML_ERROR_INTERNAL;
-    }
-  
-    if ((result = wbxml_base64_encode((const WB_UTINY *) wbxml_buffer_get_cstr(*data),
-                                      wbxml_buffer_len(*data))) == NULL)
-    {
-        return WBXML_ERROR_B64_ENC;
-    }
-
-    /* Reset buffer */
-    wbxml_buffer_delete(*data, 0, wbxml_buffer_len(*data));
-
-    /* Set data */
-    if (!wbxml_buffer_append_cstr(*data, result)) {
-        ret = WBXML_ERROR_NOT_ENOUGH_MEMORY;
-    }
-
-    wbxml_free(result);
-  
-    return ret;
-}
-
-#endif /* WBXML_SUPPORT_DRMREL */
