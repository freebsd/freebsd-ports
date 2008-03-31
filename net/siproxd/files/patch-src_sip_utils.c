--- src/sip_utils.c.orig	2008-01-19 17:07:14.000000000 +0100
+++ src/sip_utils.c	2008-03-31 10:58:24.000000000 +0200
@@ -773,13 +773,13 @@
       if (strncmp(param->gvalue, magic_cookie,
                   strlen(magic_cookie))==0) {
          /* calculate MD5 hash */
-         MD5_CTX Md5Ctx;
+         osip_MD5_CTX Md5Ctx;
          HASH HA1;
 
-         MD5Init(&Md5Ctx);
-         MD5Update(&Md5Ctx, param->gvalue,
+         osip_MD5Init(&Md5Ctx);
+         osip_MD5Update(&Md5Ctx, param->gvalue,
                    strlen(param->gvalue));
-         MD5Final(HA1, &Md5Ctx);
+         osip_MD5Final(HA1, &Md5Ctx);
          CvtHex(HA1, hashstring);
 
          DEBUGC(DBCLASS_BABBLE, "existing branch -> branch hash [%s]",
@@ -799,53 +799,53 @@
     */
    if (hashstring[0] == '\0') {
       /* calculate MD5 hash */
-      MD5_CTX Md5Ctx;
+      osip_MD5_CTX Md5Ctx;
       HASH HA1;
       char *tmp;
 
-      MD5Init(&Md5Ctx);
+      osip_MD5Init(&Md5Ctx);
 
       /* topmost via */
       osip_via_to_str(via, &tmp);
       if (tmp) {
-         MD5Update(&Md5Ctx, tmp, strlen(tmp));
+         osip_MD5Update(&Md5Ctx, tmp, strlen(tmp));
          osip_free(tmp);
       }
      
       /* Tag in To header */
       osip_to_get_tag(sip_msg->to, &param);
       if (param && param->gvalue) {
-         MD5Update(&Md5Ctx, param->gvalue, strlen(param->gvalue));
+         osip_MD5Update(&Md5Ctx, param->gvalue, strlen(param->gvalue));
       }
 
       /* Tag in From header */
       osip_from_get_tag(sip_msg->from, &param);
       if (param && param->gvalue) {
-         MD5Update(&Md5Ctx, param->gvalue, strlen(param->gvalue));
+         osip_MD5Update(&Md5Ctx, param->gvalue, strlen(param->gvalue));
       }
 
       /* Call-ID */
       call_id = osip_message_get_call_id(sip_msg);
       osip_call_id_to_str(call_id, &tmp);
       if (tmp) {
-         MD5Update(&Md5Ctx, tmp, strlen(tmp));
+         osip_MD5Update(&Md5Ctx, tmp, strlen(tmp));
          osip_free(tmp);
       }
 
       /* CSeq number (but not method) */
       tmp = osip_cseq_get_number(sip_msg->cseq);
       if (tmp) {
-         MD5Update(&Md5Ctx, tmp, strlen(tmp));
+         osip_MD5Update(&Md5Ctx, tmp, strlen(tmp));
       }
  
       /* Request URI */
       osip_uri_to_str(sip_msg->req_uri, &tmp);
       if (tmp) {
-         MD5Update(&Md5Ctx, tmp, strlen(tmp));
+         osip_MD5Update(&Md5Ctx, tmp, strlen(tmp));
          osip_free(tmp);
       }
 
-      MD5Final(HA1, &Md5Ctx);
+      osip_MD5Final(HA1, &Md5Ctx);
       CvtHex(HA1, hashstring);
 
       DEBUGC(DBCLASS_BABBLE, "non-existing branch -> branch hash [%s]",
