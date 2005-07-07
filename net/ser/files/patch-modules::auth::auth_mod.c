
$FreeBSD$

--- modules/auth/auth_mod.c.orig
+++ modules/auth/auth_mod.c
@@ -84,6 +84,9 @@
 int (*sl_reply)(struct sip_msg* _msg, char* _str1, char* _str2);
 
 
+struct tm_binds tmb;
+
+
 /*
  * Module parameter variables
  */
@@ -93,6 +96,7 @@
 str secret;
 char* sec_rand = 0;
 
+int use_tm = 0;
 
 /*
  * Default Remote-Party-ID prefix
@@ -140,6 +144,7 @@
 	{"rpid_prefix",  STR_PARAM, &rpid_prefix_param },
 	{"rpid_suffix",  STR_PARAM, &rpid_suffix_param },
 	{"realm_prefix", STR_PARAM, &realm_prefix_param},
+	{"use_tm",       INT_PARAM, &use_tm            },
 	{0, 0, 0}
 };
 
@@ -190,13 +195,23 @@
 
 static int mod_init(void)
 {
+	load_tm_f load_tm;
+
 	DBG("auth module - initializing\n");
-	
-	sl_reply = find_export("sl_send_reply", 2, 0);
 
-	if (!sl_reply) {
-		LOG(L_ERR, "auth:mod_init(): This module requires sl module\n");
-		return -2;
+	if (use_tm != 0) {
+		load_tm = (load_tm_f)find_export("load_tm", NO_SCRIPT, 0);
+		if (load_tm == NULL || load_tm(&tmb) == -1) {
+			LOG(L_ERR, "Can't import tm\n");
+			return -1;
+		}
+	} else {
+		sl_reply = find_export("sl_send_reply", 2, 0);
+
+		if (!sl_reply) {
+			LOG(L_ERR, "auth:mod_init(): This module requires sl module\n");
+			return -2;
+		}
 	}
 
 	     /* If the parameter was not used */
