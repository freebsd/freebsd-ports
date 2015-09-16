--- lib/rakp.c.orig	2015-08-19 12:52:44 UTC
+++ lib/rakp.c
@@ -482,7 +482,7 @@
 	return EINVAL;
     HMAC(rinfo->evp_md, p, rinfo->key_len, idata, 58+idata[57], integ_data, &ilen);
     if (memcmp(data+40, integ_data, rinfo->key_len) != 0)
-	return EKEYREJECTED;
+	return EAGAIN;
 
     /* Now generate the SIK */
     p = ipmi_rmcpp_auth_get_my_rand(info->ainfo, &plen);
