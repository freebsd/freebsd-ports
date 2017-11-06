--- sysdep/bsd/setkey.h	2017-05-15 14:04:47.215628000 +0300
+++ sysdep/bsd/setkey.h	2017-05-15 14:05:36.850028000 +0300
@@ -158,12 +158,14 @@ sk_set_md5_in_sasp_db(sock *s, ip_addr local, ip_addr 
     if (len > TCP_KEYLEN_MAX)
       ERR_MSG("The password for TCP MD5 Signature is too long");
 
-    if (setkey_md5(&src, &dst, passwd, SADB_ADD) < 0)
+    if (setkey_md5(&src, &dst, passwd, SADB_ADD) < 0 ||
+	setkey_md5(&dst, &src, passwd, SADB_ADD) < 0)
       ERR_MSG("Cannot add TCP-MD5 password into the IPsec SA/SP database");
   }
   else
   {
-    if (setkey_md5(&src, &dst, NULL, SADB_DELETE) < 0)
+    if (setkey_md5(&src, &dst, NULL, SADB_DELETE) < 0 ||
+	setkey_md5(&dst, &src, NULL, SADB_DELETE) < 0)
       ERR_MSG("Cannot delete TCP-MD5 password from the IPsec SA/SP database");
   }
   return 0;
