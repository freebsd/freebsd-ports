--- snmpd/config.c.orig	Thu Sep 22 08:43:58 2005
+++ snmpd/config.c	Thu Sep 22 08:44:54 2005
@@ -820,7 +820,7 @@
 	while (token == '.') {
 		if (gettoken() == TOK_NUM) {
 			if (numval > ASN_MAXID)
-				report("subid too large %#"PRIx64, numval);
+				report("subid too large %#"QUADXFMT, numval);
 			if (oid->len == ASN_MAXOIDLEN)
 				report("index too long");
 			oid->subs[oid->len++] = numval;
@@ -863,7 +863,7 @@
 	if (token != TOK_NUM)
 		report("bad INTEGER syntax");
 	if (numval > 0x7fffffff)
-		report("INTEGER too large %"PRIu64, numval);
+		report("INTEGER too large %"QUADFMT, numval);
 
 	value->v.integer = numval;
 	gettoken();
