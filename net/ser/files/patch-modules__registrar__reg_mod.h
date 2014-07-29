
$FreeBSD$

--- modules/registrar/reg_mod.h.orig
+++ modules/registrar/reg_mod.h
@@ -35,6 +35,7 @@
 #include "../../qvalue.h"
 #include "../../usr_avp.h"
 #include "../usrloc/usrloc.h"
+#include "../tm/tm_load.h"
 
 extern int default_expires;
 extern qvalue_t default_q;
@@ -48,6 +49,7 @@
 extern int use_domain;
 extern str realm_prefix;
 extern float def_q;
+extern int use_tm;
 
 extern str rcv_param;
 extern int rcv_avp_no;
@@ -57,5 +59,7 @@
 usrloc_api_t ul;  /* Structure containing pointers to usrloc functions */
 
 extern int (*sl_reply)(struct sip_msg* _m, char* _s1, char* _s2);
+
+extern struct tm_binds tmb;
 
 #endif /* REG_MOD_H */
