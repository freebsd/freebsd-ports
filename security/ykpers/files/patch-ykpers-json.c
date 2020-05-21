--- ykpers-json.c.orig	2014-04-28 09:53:50 UTC
+++ ykpers-json.c
@@ -40,7 +40,7 @@
 #define yk_json_object_object_get(obj, key, value) json_object_object_get_ex(obj, key, &value)
 #else
 typedef int json_bool;
-#define yk_json_object_object_get(obj, key, value) (value = json_object_object_get(obj, key)) == NULL ? (json_bool)FALSE : (json_bool)TRUE
+#define yk_json_object_object_get(obj, key, value) (value = json_object_object_get(obj, key)) == NULL ? 0 : 1
 #endif
 
 static void set_json_value(struct map_st *p, int mode, json_object *options, YKP_CONFIG *cfg) {
@@ -50,7 +50,7 @@ static void set_json_value(struct map_st *p, int mode,
 	if(p->mode && (mode & p->mode) == mode) {
 		json_object *joption;
 		json_bool ret = yk_json_object_object_get(options, p->json_text, joption);
-		if(ret == TRUE && json_object_get_type(joption) == json_type_boolean) {
+		if(ret == 1 && json_object_get_type(joption) == json_type_boolean) {
 			int value = json_object_get_boolean(joption);
 			if(value == 1) {
 				p->setter(cfg, true);
@@ -227,20 +227,20 @@ int _ykp_json_import_cfg(YKP_CONFIG *cfg, const char *
 			ykp_errno = YKP_EINVAL;
 			goto out;
 		}
-		if(yk_json_object_object_get(jobj, "yubiProdConfig", yprod_json) == FALSE) {
+		if(yk_json_object_object_get(jobj, "yubiProdConfig", yprod_json) == 0) {
 			ykp_errno = YKP_EINVAL;
 			goto out;
 		}
-		if(yk_json_object_object_get(yprod_json, "mode", jmode) == FALSE) {
+		if(yk_json_object_object_get(yprod_json, "mode", jmode) == 0) {
 			ykp_errno = YKP_EINVAL;
 			goto out;
 		}
-		if(yk_json_object_object_get(yprod_json, "options", options) == FALSE) {
+		if(yk_json_object_object_get(yprod_json, "options", options) == 0) {
 			ykp_errno = YKP_EINVAL;
 			goto out;
 		}
 
-		if(yk_json_object_object_get(yprod_json, "targetConfig", jtarget) == TRUE) {
+		if(yk_json_object_object_get(yprod_json, "targetConfig", jtarget) == 1) {
 			int target_config = json_object_get_int(jtarget);
 			int command;
 			if(target_config == 1) {
@@ -272,20 +272,20 @@ int _ykp_json_import_cfg(YKP_CONFIG *cfg, const char *
 		if(mode == MODE_OATH_HOTP) {
 			json_object *jdigits, *jrandom;
 			ykp_set_tktflag_OATH_HOTP(cfg, true);
-			if(yk_json_object_object_get(options, "oathDigits", jdigits) == TRUE) {
+			if(yk_json_object_object_get(options, "oathDigits", jdigits) == 1) {
 				int digits = json_object_get_int(jdigits);
 				if(digits == 8) {
 					ykp_set_cfgflag_OATH_HOTP8(cfg, true);
 				}
 			}
-			if(yk_json_object_object_get(options, "randomSeed", jrandom) == TRUE) {
+			if(yk_json_object_object_get(options, "randomSeed", jrandom) == 1) {
 				int random = json_object_get_boolean(jrandom);
 				int seed = 0;
 				if(random == 1) {
 					/* XXX: add random seed.. */
 				} else {
 					json_object *jseed;
-					if(yk_json_object_object_get(options, "fixedSeedvalue", jseed) == TRUE) {
+					if(yk_json_object_object_get(options, "fixedSeedvalue", jseed) == 1) {
 						seed = json_object_get_int(jseed);
 					}
 				}
