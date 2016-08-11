--- geoip.c.orig	2014-05-01 17:44:31 UTC
+++ geoip.c
@@ -129,11 +129,19 @@ static PHP_INI_MH(OnUpdateDirectory)
 {
 	if (stage == PHP_INI_STAGE_RUNTIME || stage == PHP_INI_STAGE_HTACCESS) {
 		GEOIP_G(set_runtime_custom_directory) = 1;
+#if PHP_MAJOR_VERSION >= 7
+		geoip_change_custom_directory(new_value->val);
+#else
 		geoip_change_custom_directory(new_value);
+#endif
 		return SUCCESS;
 	}
-	
+
+#if PHP_MAJOR_VERSION >= 7
+	return OnUpdateString(entry, new_value, mh_arg1, mh_arg2, mh_arg3, stage TSRMLS_CC);
+#else	
 	return OnUpdateString(entry, new_value, new_value_length, mh_arg1, mh_arg2, mh_arg3, stage TSRMLS_CC);
+#endif
 }
 /* }}} */
 #endif
@@ -250,7 +258,7 @@ PHP_MINFO_FUNCTION(geoip)
 /* {{{ proto boolean geoip_db_avail( [ int database ] ) */
 PHP_FUNCTION(geoip_db_avail)
 {
-	long edition;
+	zend_long edition;
 
 	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &edition) == FAILURE) {
 		return;
@@ -269,7 +277,7 @@ PHP_FUNCTION(geoip_db_avail)
 /* {{{ proto string geoip_db_filename( [ int database ] ) */
 PHP_FUNCTION(geoip_db_filename)
 {
-	long edition;
+	zend_long edition;
 
 	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &edition) == FAILURE) {
 		return;
@@ -282,7 +290,11 @@ PHP_FUNCTION(geoip_db_filename)
 	}
 	
 	if (NULL != GeoIPDBFileName[edition])
-		RETURN_STRING(GeoIPDBFileName[edition], 1);	
+#if PHP_MAJOR_VERSION >= 7
+		RETURN_STRING(GeoIPDBFileName[edition]);
+#else
+		RETURN_STRING(GeoIPDBFileName[edition], 1);
+#endif
 }
 /* }}} */
 
@@ -297,16 +309,31 @@ PHP_FUNCTION(geoip_db_get_all_info)
 	{
 		if (NULL != GeoIPDBDescription[i])
 		{
+#if PHP_MAJOR_VERSION >= 7
+			zval real_row;
+			zval *row = &real_row;
+
+			array_init(row);
+#else
 			zval *row;
 			ALLOC_INIT_ZVAL(row);
 			array_init(row);
+#endif
 
 			add_assoc_bool(row, "available", GeoIP_db_avail(i));
 			if (GeoIPDBDescription[i]) {
+#if PHP_MAJOR_VERSION >= 7
+				add_assoc_string(row, "description", (char *)GeoIPDBDescription[i]);
+#else
 				add_assoc_string(row, "description", (char *)GeoIPDBDescription[i], 1);
+#endif
 			}
 			if (GeoIPDBFileName[i]) {
+#if PHP_MAJOR_VERSION >= 7
+				add_assoc_string(row, "filename", GeoIPDBFileName[i]);
+#else
 				add_assoc_string(row, "filename", GeoIPDBFileName[i], 1);
+#endif
 			}
 
 			add_index_zval(return_value, i, row);
@@ -321,7 +348,7 @@ PHP_FUNCTION(geoip_database_info)
 {
 	GeoIP * gi;
 	char * db_info;
-	long edition = GEOIP_COUNTRY_EDITION;
+	zend_long edition = GEOIP_COUNTRY_EDITION;
 	
 	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|l", &edition) == FAILURE) {
 		return;
@@ -346,12 +373,45 @@ PHP_FUNCTION(geoip_database_info)
 	db_info = GeoIP_database_info(gi);
 	GeoIP_delete(gi);
 
+#if PHP_MAJOR_VERSION >= 7
+	RETVAL_STRING(db_info);
+#else
 	RETVAL_STRING(db_info, 1);
+#endif
 	free(db_info);
 }
 /* }}} */
 
 /* {{{ */
+#if PHP_MAJOR_VERSION >= 7
+#define GEOIPDEF(php_func, c_func, db_type) \
+	PHP_FUNCTION(php_func) \
+	{ \
+		GeoIP * gi; \
+		char * hostname = NULL; \
+		const char * return_code; \
+		size_t arglen; \
+		\
+		if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &hostname, &arglen) == FAILURE) { \
+			return; \
+		} \
+		\
+		if (GeoIP_db_avail(db_type)) { \
+			gi = GeoIP_open_type(db_type, GEOIP_STANDARD); \
+		} else { \
+			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Required database not available at %s.", GeoIPDBFileName[db_type]); \
+			return; \
+		} \
+		\
+		return_code = c_func(gi, hostname); \
+		GeoIP_delete(gi); \
+		if (return_code == NULL) { \
+			RETURN_FALSE; \
+		} \
+		RETURN_STRING((char*)return_code); \
+		\
+	}
+#else
 #define GEOIPDEF(php_func, c_func, db_type) \
 	PHP_FUNCTION(php_func) \
 	{ \
@@ -379,6 +439,7 @@ PHP_FUNCTION(geoip_database_info)
 		RETURN_STRING((char*)return_code, 1); \
 		\
 	}
+#endif
 #include "geoip.def"
 #undef GEOIPDEF
 /* }}} */
@@ -390,7 +451,11 @@ PHP_FUNCTION(geoip_continent_code_by_nam
 	GeoIP * gi;
 	char * hostname = NULL;
 	int id;
+#if PHP_MAJOR_VERSION >= 7
+	size_t arglen;
+#else
 	int arglen;
+#endif
 
 	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &hostname, &arglen) == FAILURE) {
 		return;
@@ -408,7 +473,11 @@ PHP_FUNCTION(geoip_continent_code_by_nam
 	if (id == 0) {
 		RETURN_FALSE;
 	}
+#if PHP_MAJOR_VERSION >= 7
+	RETURN_STRING((char *)GeoIP_country_continent[id]);
+#else
 	RETURN_STRING((char *)GeoIP_country_continent[id], 1);
+#endif
 }
 /* }}} */
 
@@ -419,7 +488,11 @@ PHP_FUNCTION(geoip_org_by_name)
 	GeoIP * gi;
 	char * hostname = NULL;
 	char * org;
+#if PHP_MAJOR_VERSION >= 7
+	size_t arglen;
+#else
 	int arglen;
+#endif
 
 	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &hostname, &arglen) == FAILURE) {
 		return;
@@ -437,7 +510,11 @@ PHP_FUNCTION(geoip_org_by_name)
 	if (org == NULL) {
 		RETURN_FALSE;
 	}
+#if PHP_MAJOR_VERSION >= 7
+	RETVAL_STRING(org);
+#else
 	RETVAL_STRING(org, 1);
+#endif
 	free(org);
 }
 /* }}} */
@@ -449,7 +526,11 @@ PHP_FUNCTION(geoip_asnum_by_name)
 	GeoIP * gi;
 	char * hostname = NULL;
 	char * org;
+#if PHP_MAJOR_VERSION >= 7
+	size_t arglen;
+#else
 	int arglen;
+#endif
 
 	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &hostname, &arglen) == FAILURE) {
 		return;
@@ -467,7 +548,11 @@ PHP_FUNCTION(geoip_asnum_by_name)
 	if (org == NULL) {
 		RETURN_FALSE;
 	}
+#if PHP_MAJOR_VERSION >= 7
+	RETVAL_STRING(org);
+#else
 	RETVAL_STRING(org, 1);
+#endif
 	free(org);
 }
 /* }}} */
@@ -479,7 +564,11 @@ PHP_FUNCTION(geoip_domain_by_name)
 	GeoIP * gi;
 	char * hostname = NULL;
 	char * org;
+#if PHP_MAJOR_VERSION >= 7
+	size_t arglen;
+#else
 	int arglen;
+#endif
 
 	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &hostname, &arglen) == FAILURE) {
 		return;
@@ -497,7 +586,11 @@ PHP_FUNCTION(geoip_domain_by_name)
 	if (org == NULL) {
 		RETURN_FALSE;
 	}
+#if PHP_MAJOR_VERSION >= 7
+	RETVAL_STRING(org);
+#else
 	RETVAL_STRING(org, 1);
+#endif
 	free(org);
 }
 /* }}} */
@@ -510,7 +603,11 @@ PHP_FUNCTION(geoip_netspeedcell_by_name)
 	GeoIP * gi;
 	char * hostname = NULL;
 	char * org;
+#if PHP_MAJOR_VERSION >= 7
+	size_t arglen;
+#else
 	int arglen;
+#endif
 
 	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &hostname, &arglen) == FAILURE) {
 		return;
@@ -528,7 +625,11 @@ PHP_FUNCTION(geoip_netspeedcell_by_name)
 	if (org == NULL) {
 		RETURN_FALSE;
 	}
+#if PHP_MAJOR_VERSION >= 7
+	RETVAL_STRING(org);
+#else
 	RETVAL_STRING(org, 1);
+#endif
 	free(org);
 }
 /* }}} */
@@ -540,7 +641,11 @@ PHP_FUNCTION(geoip_record_by_name)
 {
 	GeoIP * gi;
 	char * hostname = NULL;
+#if PHP_MAJOR_VERSION >= 7
+	size_t arglen;
+#else
 	int arglen;
+#endif
 	GeoIPRecord * gir;
 
 	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &hostname, &arglen) == FAILURE) {
@@ -566,15 +671,27 @@ PHP_FUNCTION(geoip_record_by_name)
 	}
 	
 	array_init(return_value);
-#if LIBGEOIP_VERSION >= 1004003
+#if PHP_MAJOR_VERSION >= 7
+# if LIBGEOIP_VERSION >= 1004003
+	add_assoc_string(return_value, "continent_code", (gir->continent_code == NULL) ? "" : gir->continent_code);
+# endif
+	add_assoc_string(return_value, "country_code", (gir->country_code == NULL) ? "" : gir->country_code);
+	add_assoc_string(return_value, "country_code3", (gir->country_code3 == NULL) ? "" : gir->country_code3);
+	add_assoc_string(return_value, "country_name", (gir->country_name == NULL) ? "" : gir->country_name);
+	add_assoc_string(return_value, "region", (gir->region == NULL) ? "" : gir->region);
+	add_assoc_string(return_value, "city", (gir->city == NULL) ? "" : gir->city);
+	add_assoc_string(return_value, "postal_code", (gir->postal_code == NULL) ? "" : gir->postal_code);
+#else
+# if LIBGEOIP_VERSION >= 1004003
 	add_assoc_string(return_value, "continent_code", (gir->continent_code == NULL) ? "" : gir->continent_code, 1);
-#endif
+# endif
 	add_assoc_string(return_value, "country_code", (gir->country_code == NULL) ? "" : gir->country_code, 1);
 	add_assoc_string(return_value, "country_code3", (gir->country_code3 == NULL) ? "" : gir->country_code3, 1);
 	add_assoc_string(return_value, "country_name", (gir->country_name == NULL) ? "" : gir->country_name, 1);
 	add_assoc_string(return_value, "region", (gir->region == NULL) ? "" : gir->region, 1);
 	add_assoc_string(return_value, "city", (gir->city == NULL) ? "" : gir->city, 1);
 	add_assoc_string(return_value, "postal_code", (gir->postal_code == NULL) ? "" : gir->postal_code, 1);
+#endif
 	add_assoc_double(return_value, "latitude", gir->latitude);
 	add_assoc_double(return_value, "longitude", gir->longitude);
 #if LIBGEOIP_VERSION >= 1004005
@@ -594,7 +711,11 @@ PHP_FUNCTION(geoip_id_by_name)
 {
 	GeoIP * gi;
 	char * hostname = NULL;
+#if PHP_MAJOR_VERSION >= 7
+	size_t arglen;
+#else
 	int arglen;
+#endif
 	int netspeed;
 
 	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &hostname, &arglen) == FAILURE) {
@@ -620,7 +741,11 @@ PHP_FUNCTION(geoip_region_by_name)
 {
 	GeoIP * gi;
 	char * hostname = NULL;
+#if PHP_MAJOR_VERSION >= 7
+	size_t arglen;
+#else
 	int arglen;
+#endif
 	GeoIPRegion * region;
 
 	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &hostname, &arglen) == FAILURE) {
@@ -646,8 +771,13 @@ PHP_FUNCTION(geoip_region_by_name)
 	}
 
 	array_init(return_value);
+#if PHP_MAJOR_VERSION >= 7
+	add_assoc_string(return_value, "country_code", region->country_code);
+	add_assoc_string(return_value, "region", region->region);
+#else
 	add_assoc_string(return_value, "country_code", region->country_code, 1);
 	add_assoc_string(return_value, "region", region->region, 1);
+#endif
 	
 	GeoIPRegion_delete(region);
 }
@@ -660,7 +790,11 @@ PHP_FUNCTION(geoip_isp_by_name)
 	GeoIP * gi;
 	char * hostname = NULL;
 	char * isp;
+#if PHP_MAJOR_VERSION >= 7
+	size_t arglen;
+#else
 	int arglen;
+#endif
 
 	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &hostname, &arglen) == FAILURE) {
 		return;
@@ -678,7 +812,11 @@ PHP_FUNCTION(geoip_isp_by_name)
 	if (isp == NULL) {
 		RETURN_FALSE;
 	}
+#if PHP_MAJOR_VERSION >= 7
+	RETVAL_STRING(isp);
+#else
 	RETVAL_STRING(isp, 1);
+#endif
 	free(isp);
 }
 
@@ -690,7 +828,11 @@ PHP_FUNCTION(geoip_region_name_by_code)
 	char * country_code = NULL;
 	char * region_code = NULL;
 	const char * region_name;
+#if PHP_MAJOR_VERSION >= 7
+	size_t countrylen, regionlen;
+#else
 	int countrylen, regionlen;
+#endif
 
 	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss", &country_code, &countrylen, &region_code, &regionlen) == FAILURE) {
 		return;
@@ -705,7 +847,11 @@ PHP_FUNCTION(geoip_region_name_by_code)
 	if (region_name == NULL) {
 		RETURN_FALSE;
 	}
+#if PHP_MAJOR_VERSION >= 7
+	RETURN_STRING((char*)region_name);
+#else
 	RETURN_STRING((char*)region_name, 1);
+#endif
 }
 /* }}} */
 #endif
@@ -718,7 +864,11 @@ PHP_FUNCTION(geoip_time_zone_by_country_
 	char * country = NULL;
 	char * region = NULL;
 	const char * timezone;
+#if PHP_MAJOR_VERSION >= 7
+	size_t countrylen, arg2len;
+#else
 	int countrylen, arg2len;
+#endif
 
 	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|s", &country, &countrylen, &region, &arg2len) == FAILURE) {
 		return;
@@ -733,7 +883,11 @@ PHP_FUNCTION(geoip_time_zone_by_country_
 	if (timezone == NULL) {
 		RETURN_FALSE;
 	}
+#if PHP_MAJOR_VERSION >= 7
+	RETURN_STRING((char*)timezone);
+#else
 	RETURN_STRING((char*)timezone, 1);
+#endif
 }
 /* }}} */
 #endif
@@ -744,7 +898,11 @@ PHP_FUNCTION(geoip_time_zone_by_country_
 PHP_FUNCTION(geoip_setup_custom_directory)
 {
 	char * dir = NULL;
+#if PHP_MAJOR_VERSION >= 7
+	size_t dirlen;
+#else
 	int dirlen;
+#endif
 
 	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &dir, &dirlen) == FAILURE) {
 		return;
