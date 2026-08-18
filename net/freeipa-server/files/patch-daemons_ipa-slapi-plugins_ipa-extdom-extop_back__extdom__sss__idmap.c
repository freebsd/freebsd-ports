--- daemons/ipa-slapi-plugins/ipa-extdom-extop/back_extdom_sss_idmap.c.orig	2026-07-01 20:01:46 UTC
+++ daemons/ipa-slapi-plugins/ipa-extdom-extop/back_extdom_sss_idmap.c
@@ -64,8 +64,10 @@ static enum nss_status __convert_sss_nss2nss_status(in
         return NSS_STATUS_NOTFOUND;
     case ERANGE:
         return NSS_STATUS_TRYAGAIN;
+#if ETIME != ETIMEDOUT
     case ETIME:
         /* fall-through */
+#endif
     case ETIMEDOUT:
         /* fall-through */
     default:
