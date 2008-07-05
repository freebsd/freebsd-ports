--- src/wbxml_encoder.c.orig	2006-07-11 21:47:45.000000000 +1000
+++ src/wbxml_encoder.c	2008-06-15 08:45:31.000000000 +1000
@@ -136,6 +136,7 @@
     const WBXMLTagEntry *current_tag;       /**< Current Tag (See The Warning For This Field !) */
     const WBXMLTreeNode *current_text_parent; /**< Text parent of current Node (See The Warning For This Field !) */
     const WBXMLAttrEntry *current_attr;     /**< Current Attribute */
+    WBXMLTreeNode *current_node;
     WB_UTINY tagCodePage;                   /**< Current Tag Code Page */
     WB_UTINY attrCodePage;                  /**< Current Attribute Code Page */
     WB_BOOL ignore_empty_text;              /**< Do we ignore empty text nodes (ie: ignorable whitespaces)? */
@@ -153,6 +154,7 @@
     WB_BOOL use_strtbl;                     /**< Do we use String Table when generating WBXML output ? (default: YES) */
 #endif /* WBXML_ENCODER_USE_STRTBL */
     WB_BOOL xml_encode_header;              /**< Do we generate XML Header ? */
+    WB_BOOL produce_anonymous;
     WBXMLVersion wbxml_version;             /**< WBXML Version to use (when generating WBXML output) */
     WBXMLCharsetMIBEnum output_charset;     /**< Output charset encoding */
     WB_BOOL flow_mode;                      /**< Is Flow Mode encoding activated ? */
@@ -269,6 +271,7 @@
 static WBXMLError wbxml_encode_entity(WBXMLEncoder *encoder, WB_ULONG value);
 #endif /* 0 */
 static WBXMLError wbxml_encode_opaque(WBXMLEncoder *encoder, WBXMLBuffer *buff);
+static WBXMLError wbxml_encode_opaque_data(WBXMLEncoder *encoder, WB_UTINY *data, WB_ULONG data_len);
 #if defined( WBXML_ENCODER_USE_STRTBL )
 static WBXMLError wbxml_encode_tableref(WBXMLEncoder *encoder, WB_ULONG offset);
 #endif /* WBXML_ENCODER_USE_STRTBL */
@@ -292,7 +295,9 @@
 #if defined( WBXML_SUPPORT_DRMREL )
 static WBXMLError wbxml_encode_drmrel_content(WBXMLEncoder *encoder, WB_UTINY *buffer);
 #endif /* WBXML_SUPPORT_DRMREL */
-
+#if defined( WBXML_SUPPORT_OTA_SETTINGS )
+static WBXMLError wbxml_encode_ota_nokia_icon(WBXMLEncoder *encoder, WB_UTINY *buffer);
+#endif
 #if defined( WBXML_ENCODER_USE_STRTBL )
 /* WBXML String Table Functions */
 static WBXMLStringTableElement *wbxml_strtbl_element_create(WBXMLBuffer *string, WB_BOOL is_stat);
@@ -383,6 +388,7 @@
     encoder->current_tag = NULL;
     encoder->current_text_parent = NULL;
     encoder->current_attr = NULL;
+    encoder->current_node = NULL;
 
     encoder->tagCodePage = 0;
     encoder->attrCodePage = 0;
@@ -400,6 +406,7 @@
     encoder->cdata = NULL;
 
     encoder->xml_encode_header = TRUE;
+    encoder->produce_anonymous = FALSE;
 
     /* Default Version: WBXML 1.3 */
     encoder->wbxml_version = WBXML_VERSION_13;
@@ -450,6 +457,7 @@
     
     encoder->current_tag = NULL;
     encoder->current_attr = NULL;
+    encoder->current_node = NULL;
     
     encoder->tagCodePage = 0;
     encoder->attrCodePage = 0;
@@ -507,7 +515,13 @@
     encoder->use_strtbl = use_strtbl;
 #endif /* WBXML_ENCODER_USE_STRTBL */
 }
-
+WBXML_DECLARE(void) wbxml_encoder_set_produce_anonymous(WBXMLEncoder *encoder, WB_BOOL set_anonymous)
+{
+    if (encoder == NULL)
+        return;
+    
+    encoder->produce_anonymous = set_anonymous;
+}
 
 WBXML_DECLARE(void) wbxml_encoder_set_wbxml_version(WBXMLEncoder *encoder, WBXMLVersion version)
 {
@@ -637,6 +651,9 @@
 
 WBXML_DECLARE(WBXMLError) wbxml_encoder_encode_node(WBXMLEncoder *encoder, WBXMLTreeNode *node)
 {
+    if (encoder->flow_mode == FALSE) {
+        WBXML_WARNING((WBXML_ENCODER, "You should NOT call wbxml_encoder_encode_node() if you are not in Flow Mode encoding ! (use wbxml_encoder_set_flow_mode(encoder, TRUE))"));
+    }
     return wbxml_encoder_encode_node_with_elt_end(encoder, node, TRUE);
 }
 
@@ -649,10 +666,6 @@
     if ((encoder == NULL) || (node == NULL))
         return WBXML_ERROR_BAD_PARAMETER;
     
-    if (encoder->flow_mode == FALSE) {
-        WBXML_WARNING((WBXML_ENCODER, "You should NOT call wbxml_encoder_encode_node() if you are not in Flow Mode encoding ! (use wbxml_encoder_set_flow_mode(encoder, TRUE))"));
-    }
-    
     /* Check that language table has been set */
     if (encoder->lang == NULL)
         return WBXML_ERROR_BAD_PARAMETER;
@@ -965,6 +978,7 @@
 static WBXMLError parse_node(WBXMLEncoder *encoder, WBXMLTreeNode *node, WB_BOOL enc_end)
 {
     WBXMLError ret = WBXML_OK;
+    encoder->current_node = node;
 
     /* Parse this node */
     switch (node->type) {
@@ -1078,6 +1092,7 @@
 
     /* Reset Current Tag */
     encoder->current_tag = NULL;
+    encoder->current_node = NULL;
 
     /* Parse next node */
     if (node->next != NULL)
@@ -1464,7 +1479,7 @@
 
     /* Encode Public ID */
     /* If WBXML Public Id is '0x01' (unknown), or we forced it, add the XML Public ID in the String Table */
-    if (encoder->textual_publicid || (public_id == WBXML_PUBLIC_ID_UNKNOWN))
+    if ((encoder->textual_publicid || (public_id == WBXML_PUBLIC_ID_UNKNOWN)) && !encoder->produce_anonymous)
     {
         if (encoder->lang->publicID->xmlPublicID != NULL)
         {
@@ -1500,7 +1515,7 @@
             else {
 #endif /* WBXML_ENCODER_USE_STRTBL */
                 /* Length of String Table is length of XML Public ID */
-                strstbl_len = wbxml_buffer_len(pid);
+                strstbl_len = wbxml_buffer_len(pid) + 1;
 
                 /* There is only the XML Public ID in String Table */
                 public_id_index = 0;
@@ -1548,7 +1563,8 @@
             /* The append includes terminating NULL char */
             if (!wbxml_buffer_append(header, pid))
                 return WBXML_ERROR_ENCODER_APPEND_DATA;
-            
+            if (!wbxml_buffer_append_char(header, WBXML_STR_END))
+                return WBXML_ERROR_ENCODER_APPEND_DATA;
             /* Clean up */
             wbxml_buffer_destroy(pid);
         }
@@ -1870,7 +1886,7 @@
      *  Encoder Language Specific Attribute Values
      */
 
-    if (ctx == WBXML_VALUE_ELEMENT_CTX_ATTR) {
+    if ((ctx == WBXML_VALUE_ELEMENT_CTX_ATTR) && (encoder->current_attr != NULL)) {
         switch (encoder->lang->langID) {
 #if defined( WBXML_SUPPORT_SI )
         case WBXML_LANG_SI10:
@@ -1892,7 +1908,16 @@
             }
             break;
 #endif /* WBXML_SUPPORT_EMN */
-
+#if defined( WBXML_SUPPORT_OTA_SETTINGS )
+        case WBXML_LANG_OTA_SETTINGS:
+            if ((encoder->current_attr->wbxmlCodePage == 0x00) &&
+                (encoder->current_attr->wbxmlToken == 0x11))
+            {
+                if ((ret = wbxml_encode_ota_nokia_icon(encoder, buffer)) != WBXML_NOT_ENCODED)
+                    return ret;
+            }
+            break;
+#endif /* WBXML_SUPPORT_OTA_SETTINGS */
         default:
             break;
         }
@@ -1936,7 +1961,8 @@
 #if defined( WBXML_SUPPORT_SYNCML )
         /* If this is a SyncML document ? */
         if ((encoder->lang->langID == WBXML_LANG_SYNCML_SYNCML10) ||
-            (encoder->lang->langID == WBXML_LANG_SYNCML_SYNCML11))
+            (encoder->lang->langID == WBXML_LANG_SYNCML_SYNCML11) ||
+            (encoder->lang->langID == WBXML_LANG_SYNCML_SYNCML12))
         {
             /** @todo We must check too if we are in a <Type> */
 
@@ -2219,6 +2245,11 @@
  * @param list The Value Element list
  * @return WBXML_OK if encoding is OK, an error code otherwise
  */
+static WBXMLError wbxml_encode_opaque(WBXMLEncoder *encoder, WBXMLBuffer *buff)
+{
+    return wbxml_encode_opaque_data(encoder, wbxml_buffer_get_cstr(buff), wbxml_buffer_len(buff));
+}
+
 static WBXMLError wbxml_encode_value_element_list(WBXMLEncoder *encoder, WBXMLList *list)
 {
     WBXMLValueElement *elt = NULL;
@@ -2438,18 +2469,18 @@
  * @note  opaque = OPAQUE length *byte
  *        length = mb_u_int32
  */
-static WBXMLError wbxml_encode_opaque(WBXMLEncoder *encoder, WBXMLBuffer *buff)
+static WBXMLError wbxml_encode_opaque_data(WBXMLEncoder *encoder, WB_UTINY *data, WB_ULONG data_len)
 {
     /* Add WBXML_OPAQUE */
     if (!wbxml_buffer_append_char(encoder->output, WBXML_OPAQUE))
         return WBXML_ERROR_ENCODER_APPEND_DATA;
 
     /* Add Length */
-    if (!wbxml_buffer_append_mb_uint_32(encoder->output, wbxml_buffer_len(buff)))
+    if (!wbxml_buffer_append_mb_uint_32(encoder->output, data_len))
         return WBXML_ERROR_ENCODER_APPEND_DATA;
 
     /* Add Buffer */
-    if (!wbxml_buffer_append(encoder->output, buff))
+    if (!wbxml_buffer_append_data(encoder->output, data, data_len))
         return WBXML_ERROR_ENCODER_APPEND_DATA;
 
     return WBXML_OK;
@@ -3146,8 +3177,54 @@
 }
 
 #endif /* WBXML_SUPPORT_DRMREL */
+#if defined( WBXML_SUPPORT_OTA_SETTINGS )
+static WBXMLError wbxml_encode_ota_nokia_icon(WBXMLEncoder *encoder, WB_UTINY *buffer)
+{
+    WBXMLError ret = WBXML_NOT_ENCODED;
+
+    /* Is a VALUE attribute ? */
+    if ((encoder->current_tag != NULL) &&
+        (encoder->current_attr->wbxmlCodePage == 0x00) &&
+        (encoder->current_attr->wbxmlToken == 0x11) &&
+        (encoder->current_node && encoder->current_node->attrs))
+    {
+        WBXMLList *attrs = encoder->current_node->attrs;
+        WB_ULONG index = 0;
+        WB_ULONG nb_attrs = wbxml_list_len(attrs);
+        WB_BOOL found = FALSE;
+        
+        /* Search for a NAME="ICON" attribute */
+        while (!found && (index < nb_attrs)) {
+            WBXMLAttribute *attr = (WBXMLAttribute*)wbxml_list_get(attrs, index);
+        
+            if ((WBXML_STRCMP("NAME", wbxml_attribute_get_xml_name(attr)) == 0) &&
+                (WBXML_STRCMP("ICON", wbxml_attribute_get_xml_value(attr)) == 0))
+            {
+                WB_UTINY *data = NULL;
+                WB_LONG data_len = 0;
 
+                /* Decode Base64 */
+                if ((data_len = wbxml_base64_decode(buffer, &data)) < 0)
+                    return WBXML_NOT_ENCODED;
+
+                /* Encode opaque */
+                if ((ret = wbxml_encode_opaque_data(encoder, data, data_len)) != WBXML_OK)
+                    return ret;
+
+                /* Free Data */
+                wbxml_free(data);
+
+                found = TRUE;
+            }
+
+            index++;
+        }
+    }
+
+    return ret;
+}
 
+#endif /* WBXML_SUPPORT_OTA_SETTINGS */
 #if defined( WBXML_ENCODER_USE_STRTBL )
 
 /****************************
@@ -4019,7 +4096,8 @@
 #if defined( WBXML_SUPPORT_SYNCML )
         /* Change text in <Type> from "application/vnd.syncml-devinf+wbxml" to "application/vnd.syncml-devinf+xml" */
         if (((encoder->lang->langID == WBXML_LANG_SYNCML_SYNCML10) ||
-             (encoder->lang->langID == WBXML_LANG_SYNCML_SYNCML11)) &&
+             (encoder->lang->langID == WBXML_LANG_SYNCML_SYNCML11) ||
+             (encoder->lang->langID == WBXML_LANG_SYNCML_SYNCML12)) &&
             (encoder->current_tag != NULL) &&
             (encoder->current_tag->wbxmlCodePage == 0x01 ) &&
             (encoder->current_tag->wbxmlToken == 0x13 ) &&
