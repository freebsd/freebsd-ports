--- spmd/shell.c.orig	Sat Jun 17 19:46:58 2006
+++ spmd/shell.c	Wed Sep 20 15:24:27 2006
@@ -1,4 +1,4 @@
-/* $Id: shell.c,v 1.105 2006/06/18 02:46:58 sinoue Exp $ */ 
+/* $Id: shell.c,v 1.108 2006/07/25 10:57:54 fukumoto Exp $ */ 
 /*
  * Copyright (C) 2003 WIDE Project.
  * All rights reserved.
@@ -653,7 +653,7 @@
 	const EVP_MD *m;
 	EVP_MD_CTX ctx;
 	unsigned char digest[EVP_MAX_MD_SIZE];
-	size_t digest_len;
+	unsigned int digest_len;
 
 	OpenSSL_add_all_digests();
 	if (!(m = EVP_get_digestbyname("sha1"))) {
@@ -782,7 +782,7 @@
 spmd_passwd_check(char *str, struct spmd_cid *cid)
 {
 	size_t ret;
-	size_t len,plen,slen;
+	size_t plen,slen;
 	char *passwd = shell_cfg_get_password();
 
 	if (!str||!cid||!passwd) {
@@ -807,13 +807,12 @@
 	plen = strlen(cid->hash);
 	slen = strlen(str);
 
-	len = slen >= plen ? plen : -1;
-	if (len < 0) {
+	if (slen < plen) {
 		ret = -1;
 		goto fin;
 	}
 
-	ret = strncmp(cid->hash, str, len); 
+	ret = strncmp(cid->hash, str, plen); 
 
 fin:
 
@@ -1456,7 +1455,7 @@
 		if (spmd_spd_update(sl1, rc1, not_urgent)<0) {
 			strlcpy(status, "550 ", sizeof(status));
 			snprintf(buf, sizeof(buf), "%sOperation Failed(sl_index=%.*s)\r\n", 
-							status, sl1->sl_index->l, sl1->sl_index->v);
+							status, (int)sl1->sl_index->l, sl1->sl_index->v);
 			goto err_fin;
 		}
 
@@ -1486,13 +1485,13 @@
 		if (spmd_spd_update(sl2, rc2, not_urgent)<0) {
 			strlcpy(status, "550 ", sizeof(status));
 			snprintf(buf, sizeof(buf), "%sOperation Failed(sl_index=%.*s)\r\n", 
-							status, sl2->sl_index->l, sl2->sl_index->v);
+							status, (int)sl2->sl_index->l, sl2->sl_index->v);
 			goto err_fin;
 		}
 
 		strlcpy(status, "250 ", sizeof(status));
 		snprintf(buf, sizeof(buf), "%sPolicy Added %.*s and %.*s\r\n", 
-			status, sl1->sl_index->l, sl1->sl_index->v, sl2->sl_index->l, sl2->sl_index->v);
+			status, (int)sl1->sl_index->l, sl1->sl_index->v, (int)sl2->sl_index->l, sl2->sl_index->v);
 		goto fin;
 	} else if (!strncasecmp(sh_argv[0], "DELETE", strlen("DELETE"))) { 
 		if (sh_argc != 2) {
