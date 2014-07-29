
$FreeBSD$

--- modules/auth/auth_mod.h.orig
+++ modules/auth/auth_mod.h
@@ -36,7 +36,7 @@
 
 #include "../../str.h"
 #include "../../parser/msg_parser.h"    /* struct sip_msg */
-
+#include "../tm/tm_load.h"
 
 /*
  * Module parameters variables
@@ -46,9 +46,11 @@
 extern str rpid_prefix;       /* Remote-Party-ID prefix */
 extern str rpid_suffix;       /* Remote-Party-ID suffix */
 extern str realm_prefix;      /* strip off auto-generated realm */
-
+extern int use_tm;
 
 /* Stateless reply function pointer */
 extern int (*sl_reply)(struct sip_msg* _m, char* _str1, char* _str2);
+
+extern struct tm_binds tmb;
 
 #endif /* AUTH_MOD_H */
