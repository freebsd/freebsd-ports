--- src/ctapi/ctapi.c	2006-04-25 23:58:06.000000000 +0200
+++ src/ctapi/ctapi.c	2013-07-05 10:08:41.000000000 +0200
@@ -562,7 +562,11 @@
 	ct->next = cardTerminals;
 	cardTerminals = ct;
 	ct->cwd = &ct->mf;
-	ct_reader_info(pn, &info);
+	if (ct_reader_info(pn, &info) < 0) { 
+		free(ct);
+		ct_error("ct_reader_info failed\n");
+		return ERR_INVALID;
+	}
 	ct->mf.id = 0x3f00;
 	ct->mf.gen = dir;
 	ct->mf.dir[0] = &ct->mf;
