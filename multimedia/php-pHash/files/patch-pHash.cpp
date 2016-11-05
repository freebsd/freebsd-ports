--- pHash.cpp.orig	2013-04-23 18:54:02 UTC
+++ pHash.cpp
@@ -36,17 +36,23 @@ struct ph_text_hash
 
 /* {{{ phpinfo logo definitions */
 
+#if PHP_VERSION_ID < 50500
 #include "php_logos.h"
 
 
 static unsigned char pHash_logo[] = {
 #include "pHash_logos.h"
 }; 
+#endif
 /* }}} */
 
 /* {{{ Resource destructors */
 int le_ph_video_hash;
+#if PHP_VERSION_ID >= 70000
+extern "C" void ph_video_hash_dtor(zend_resource *rsrc TSRMLS_DC)
+#else
 extern "C" void ph_video_hash_dtor(zend_rsrc_list_entry *rsrc TSRMLS_DC)
+#endif
 {
 	ph_video_hash * resource = (ph_video_hash *)(rsrc->ptr);
 
@@ -58,7 +64,11 @@ extern "C" void ph_video_hash_dtor(zend_
 }
 
 int le_ph_image_hash;
+#if PHP_VERSION_ID >= 70000
+extern "C" void ph_image_hash_dtor(zend_resource *rsrc TSRMLS_DC)
+#else
 extern "C" void ph_image_hash_dtor(zend_rsrc_list_entry *rsrc TSRMLS_DC)
+#endif
 {
 	ulong64 * resource = (ulong64 *)(rsrc->ptr);
 
@@ -67,7 +77,11 @@ extern "C" void ph_image_hash_dtor(zend_
 }
 
 int le_ph_audio_hash;
+#if PHP_VERSION_ID >= 70000
+extern "C" void ph_audio_hash_dtor(zend_resource *rsrc TSRMLS_DC)
+#else
 extern "C" void ph_audio_hash_dtor(zend_rsrc_list_entry *rsrc TSRMLS_DC)
+#endif
 {
 	ph_audio_hash * resource = (ph_audio_hash *)(rsrc->ptr);
 
@@ -79,7 +93,11 @@ extern "C" void ph_audio_hash_dtor(zend_
 }
 
 int le_ph_txt_hash;
+#if PHP_VERSION_ID >= 70000
+extern "C" void ph_txt_hash_dtor(zend_resource *rsrc TSRMLS_DC)
+#else
 extern "C" void ph_txt_hash_dtor(zend_rsrc_list_entry *rsrc TSRMLS_DC)
+#endif
 {
 	ph_text_hash * resource = (ph_text_hash *)(rsrc->ptr);
 
@@ -145,7 +163,9 @@ ZEND_GET_MODULE(pHash)
 /* {{{ PHP_MINIT_FUNCTION */
 PHP_MINIT_FUNCTION(pHash)
 {
+#if PHP_VERSION_ID < 50500
 	php_register_info_logo("PHASH_LOGO_ID", "", pHash_logo, 49651);
+#endif
 	le_ph_video_hash = zend_register_list_destructors_ex(ph_video_hash_dtor, 
 						   NULL, "ph_video_hash", module_number);
 	le_ph_image_hash = zend_register_list_destructors_ex(ph_image_hash_dtor, 
@@ -165,7 +185,9 @@ PHP_MINIT_FUNCTION(pHash)
 /* {{{ PHP_MSHUTDOWN_FUNCTION */
 PHP_MSHUTDOWN_FUNCTION(pHash)
 {
+#if PHP_VERSION_ID < 50500
 	php_unregister_info_logo("PHASH_LOGO_ID");
+#endif
 
 	/* add your stuff here */
 
@@ -203,7 +225,9 @@ PHP_MINFO_FUNCTION(pHash)
 	if (SG(request_info).request_uri) {
 		php_printf("%s", (SG(request_info).request_uri));
 	}   
+#if PHP_VERSION_ID < 50500
 	php_printf("?=%s", "PHASH_LOGO_ID");
+#endif
 	php_printf("' align='right' alt='image' border='0'>\n");
 
 	php_printf("pHash\n");
@@ -225,10 +249,12 @@ PHP_MINFO_FUNCTION(pHash)
 PHP_FUNCTION(ph_dct_videohash)
 {
 	ph_video_hash * return_res;
+#if PHP_VERSION_ID < 70000
 	long return_res_id = -1;
+#endif
 
 	const char * file = NULL;
-	int file_len = 0;
+	SIZETorINT file_len = 0;
 
 
 
@@ -249,7 +275,11 @@ PHP_FUNCTION(ph_dct_videohash)
 	else
 		RETURN_FALSE;
 
+#if PHP_VERSION_ID >= 70000
+	RETURN_RES(zend_register_resource(return_res, le_ph_video_hash));
+#else
 	return_res_id = ZEND_REGISTER_RESOURCE(return_value, return_res, le_ph_video_hash);
+#endif
 }
 /* }}} ph_dct_videohash */
 
@@ -261,10 +291,12 @@ PHP_FUNCTION(ph_dct_videohash)
 PHP_FUNCTION(ph_dct_imagehash)
 {
 	ulong64 * return_res;
+#if PHP_VERSION_ID < 70000
 	long return_res_id = -1;
+#endif
 
 	const char * file = NULL;
-	int file_len = 0;
+	SIZETorINT file_len = 0;
 
 
 
@@ -282,7 +314,11 @@ PHP_FUNCTION(ph_dct_imagehash)
 	else
 		return_res = hash;
 
+#if PHP_VERSION_ID >= 70000
+	RETURN_RES(zend_register_resource(return_res, le_ph_image_hash));
+#else
 	return_res_id = ZEND_REGISTER_RESOURCE(return_value, return_res, le_ph_image_hash);
+#endif
 }
 /* }}} ph_dct_imagehash */
 
@@ -293,10 +329,12 @@ PHP_FUNCTION(ph_dct_imagehash)
 PHP_FUNCTION(ph_texthash)
 {
 	ph_text_hash * return_res;
+#if PHP_VERSION_ID < 70000
 	long return_res_id = -1;
+#endif
 
 	const char * file = NULL;
-	int file_len = 0;
+	SIZETorINT file_len = 0;
 
 
 
@@ -316,7 +354,11 @@ PHP_FUNCTION(ph_texthash)
 	else
 		RETURN_FALSE;
 
+#if PHP_VERSION_ID >= 70000
+	RETURN_RES(zend_register_resource(return_res, le_ph_txt_hash));
+#else
 	return_res_id = ZEND_REGISTER_RESOURCE(return_value, return_res, le_ph_txt_hash);
+#endif
 }
 /* }}} ph_texthash */
 
@@ -327,12 +369,14 @@ PHP_FUNCTION(ph_texthash)
 PHP_FUNCTION(ph_audiohash)
 {
 	ph_audio_hash * return_res;
+#if PHP_VERSION_ID < 70000
 	long return_res_id = -1;
+#endif
 
 	const char * file = NULL;
-	int file_len = 0;
-	long sample_rate = 5512;
-	long channels = 1;
+	SIZETorINT file_len = 0;
+	zppLONG sample_rate = 5512;
+	zppLONG channels = 1;
 
 
 
@@ -362,7 +406,11 @@ PHP_FUNCTION(ph_audiohash)
 	else
 		RETURN_FALSE;
 
+#if PHP_VERSION_ID >= 70000
+	RETURN_RES(zend_register_resource(return_res, le_ph_audio_hash));
+#else
 	return_res_id = ZEND_REGISTER_RESOURCE(return_value, return_res, le_ph_audio_hash);
+#endif
 }
 /* }}} ph_audiohash */
 
@@ -386,8 +434,17 @@ PHP_FUNCTION(ph_image_dist)
 	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rr", &h1_res, &h2_res) == FAILURE) {
 		return;
 	}
+#if PHP_VERSION_ID >= 70000
+	if ((h1 = (ulong64 *)zend_fetch_resource2(Z_RES_P(h1_res), "ph_image_hash", h1_resid, le_ph_image_hash)) == NULL) {
+		RETURN_FALSE;
+	}
+	if ((h2 = (ulong64 *)zend_fetch_resource2(Z_RES_P(h2_res), "ph_image_hash", h2_resid, le_ph_image_hash)) == NULL) {
+		RETURN_FALSE;
+	}
+#else
 	ZEND_FETCH_RESOURCE(h1, ulong64 *, &h1_res, h1_resid, "ph_image_hash", le_ph_image_hash);
 	ZEND_FETCH_RESOURCE(h2, ulong64 *, &h2_res, h2_resid, "ph_image_hash", le_ph_image_hash);
+#endif
 
 
 
@@ -415,15 +472,24 @@ PHP_FUNCTION(ph_video_dist)
 	int h2_resid = -1;
 	ph_video_hash * h2;
 
-	long thresh = 21;
+	zppLONG thresh = 21;
 
 
 
 	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rr|l", &h1_res, &h2_res, &thresh) == FAILURE) {
 		return;
 	}
+#if PHP_VERSION_ID >= 70000
+	if ((h1 = (ph_video_hash *)zend_fetch_resource2(Z_RES_P(h1_res), "ph_video_hash", h1_resid, le_ph_video_hash)) == NULL) {
+		RETURN_FALSE;
+	}
+	if ((h2 = (ph_video_hash *)zend_fetch_resource2(Z_RES_P(h2_res), "ph_video_hash", h2_resid, le_ph_video_hash)) == NULL) {
+		RETURN_FALSE;
+	}
+#else
 	ZEND_FETCH_RESOURCE(h1, ph_video_hash *, &h1_res, h1_resid, "ph_video_hash", le_ph_video_hash);
 	ZEND_FETCH_RESOURCE(h2, ph_video_hash *, &h2_res, h2_resid, "ph_video_hash", le_ph_video_hash);
+#endif
 
 
 
@@ -452,7 +518,7 @@ PHP_FUNCTION(ph_audio_dist)
 	int h2_resid = -1;
 	ph_audio_hash * h2;
 
-	long block_size = 256;
+	zppLONG block_size = 256;
 	double thresh = 0.30;
 
 
@@ -460,8 +526,17 @@ PHP_FUNCTION(ph_audio_dist)
 	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rr|ld", &h1_res, &h2_res, &block_size, &thresh) == FAILURE) {
 		return;
 	}
+#if PHP_VERSION_ID >= 70000
+	if ((h1 = (ph_audio_hash *)zend_fetch_resource2(Z_RES_P(h1_res), "ph_audio_hash", h1_resid, le_ph_audio_hash)) == NULL) {
+		RETURN_FALSE;
+	}
+	if ((h2 = (ph_audio_hash *)zend_fetch_resource2(Z_RES_P(h2_res), "ph_audio_hash", h2_resid, le_ph_audio_hash)) == NULL) {
+		RETURN_FALSE;
+	}
+#else
 	ZEND_FETCH_RESOURCE(h1, ph_audio_hash *, &h1_res, h1_resid, "ph_audio_hash", le_ph_audio_hash);
 	ZEND_FETCH_RESOURCE(h2, ph_audio_hash *, &h2_res, h2_resid, "ph_audio_hash", le_ph_audio_hash);
+#endif
 
 
 
@@ -510,8 +585,17 @@ PHP_FUNCTION(ph_compare_text_hashes)
 	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rr", &h1_res, &h2_res) == FAILURE) {
 		return;
 	}
+#if PHP_VERSION_ID >= 70000
+	if ((h1 = (ph_text_hash *)zend_fetch_resource2(Z_RES_P(h1_res), "ph_txt_hash", h1_resid, le_ph_txt_hash)) == NULL) {
+		RETURN_FALSE;
+	}
+	if ((h2 = (ph_text_hash *)zend_fetch_resource2(Z_RES_P(h2_res), "ph_txt_hash", h2_resid, le_ph_txt_hash)) == NULL) {
+		RETURN_FALSE;
+	}
+#else
 	ZEND_FETCH_RESOURCE(h1, ph_text_hash *, &h1_res, h1_resid, "ph_txt_hash", le_ph_txt_hash);
 	ZEND_FETCH_RESOURCE(h2, ph_text_hash *, &h2_res, h2_resid, "ph_txt_hash", le_ph_txt_hash);
+#endif
 
 
 
@@ -525,6 +609,14 @@ PHP_FUNCTION(ph_compare_text_hashes)
 		{
 			for(int i = 0; i < count; ++i)
 			{
+#if PHP_VERSION_ID >= 70000
+				zval array;
+				array_init(&array);
+				add_assoc_long(&array, "begin", m[i].first_index);
+				add_assoc_long(&array, "end", m[i].second_index);
+				add_assoc_long(&array, "length", m[i].length);
+				add_next_index_zval(return_value, &array);
+#else
 				zval *array;
 				MAKE_STD_ZVAL(array);
 				array_init(array);
@@ -532,6 +624,7 @@ PHP_FUNCTION(ph_compare_text_hashes)
 				add_assoc_long(array, "end", m[i].second_index);
 				add_assoc_long(array, "length", m[i].length);
 				add_next_index_zval(return_value, array);
+#endif
 			}
 			free(m);
 		}
