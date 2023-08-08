--- src/pap.c.orig	2020-09-06 21:33:02.000000000 +0700
+++ src/pap.c	2023-02-18 22:36:56.550325000 +0700
@@ -154,7 +154,7 @@ PapInput(Link l, AuthData auth, const u_char *pkt, u_s
 	    goto error;
 
 	pass_len = pkt[1 + name_len];
-	pass_ptr = pkt + 1 + name_len + 1;
+	pass_ptr = (const char *)pkt + 1 + name_len + 1;
 
 	if (name_len + 1 + pass_len + 1 > len)
 	    goto error;
