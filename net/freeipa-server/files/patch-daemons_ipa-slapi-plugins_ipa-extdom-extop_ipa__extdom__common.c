--- daemons/ipa-slapi-plugins/ipa-extdom-extop/ipa_extdom_common.c.orig	2026-07-01 20:01:47 UTC
+++ daemons/ipa-slapi-plugins/ipa-extdom-extop/ipa_extdom_common.c
@@ -1237,7 +1237,9 @@ static int handle_simple_request(struct ipa_extdom_ctx
         ret = LDAP_NO_SUCH_OBJECT;
         break;
     case ETIMEDOUT:
+#if ETIME != ETIMEDOUT
     case ETIME:
+#endif
         ret = LDAP_TIMELIMIT_EXCEEDED;
         break;
     default:
