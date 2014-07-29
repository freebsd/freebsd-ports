
$FreeBSD$

--- modules/registrar/reg_mod.c.orig
+++ modules/registrar/reg_mod.c
@@ -70,6 +70,7 @@
 int use_domain = 0;
 char* realm_pref    = "";   /* Realm prefix to be removed */
 str realm_prefix;
+int use_tm = 0;
 
 #define RCV_NAME "received"
 #define RCV_NAME_LEN (sizeof(RCV_NAME) - 1)
@@ -84,6 +85,9 @@
 int (*sl_reply)(struct sip_msg* _m, char* _s1, char* _s2);
 
 
+struct tm_binds tmb;
+
+
 /*
  * Exported functions
  */
@@ -115,6 +119,7 @@
 	{"use_domain",      INT_PARAM, &use_domain     },
 	{"max_contacts",    INT_PARAM, &max_contacts   },
 	{"retry_after",     INT_PARAM, &retry_after    },
+	{"use_tm",          INT_PARAM, &use_tm         },
 	{0, 0, 0}
 };
 
@@ -140,17 +145,26 @@
 static int mod_init(void)
 {
 	bind_usrloc_t bind_usrloc;
+	load_tm_f load_tm;
 
 	DBG("registrar - initializing\n");
 
-             /*
-              * We will need sl_send_reply from stateless
-	      * module for sending replies
-	      */
-        sl_reply = find_export("sl_send_reply", 2, 0);
-	if (!sl_reply) {
-		LOG(L_ERR, "registrar: This module requires sl module\n");
-		return -1;
+	if (use_tm != 0) {
+		load_tm = (load_tm_f)find_export("load_tm", NO_SCRIPT, 0);
+		if (load_tm == NULL || load_tm(&tmb) == -1) {
+			LOG(L_ERR, "Can't import tm\n");
+			return -1;
+		}
+	} else {
+               /*
+                * We will need sl_send_reply from stateless
+	        * module for sending replies
+	        */
+ 	        sl_reply = find_export("sl_send_reply", 2, 0);
+		if (!sl_reply) {
+			LOG(L_ERR, "registrar: This module requires sl module\n");
+			return -1;
+		}
 	}
 
 	realm_prefix.s = realm_pref;
