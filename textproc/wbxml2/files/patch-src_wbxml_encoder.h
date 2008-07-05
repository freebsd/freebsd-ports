--- src/wbxml_encoder.h.orig	2008-06-15 07:38:14.000000000 +1000
+++ src/wbxml_encoder.h	2008-06-15 07:39:40.000000000 +1000
@@ -116,6 +116,7 @@
  * @note This function has no effect if WBXML_ENCODER_USE_STRTBL compilation flag is not set
  */
 WBXML_DECLARE(void) wbxml_encoder_set_use_strtbl(WBXMLEncoder *encoder, WB_BOOL use_strtbl);
+WBXML_DECLARE(void) wbxml_encoder_set_produce_anonymous(WBXMLEncoder *encoder, WB_BOOL set_anonymous);
 
 /**
  * @brief Set the WBXML Version of the output document, when generating WBXML [Default: 'WBXML_VERSION_TOKEN_13' (1.3)]
