--- exosip/jauth.c.orig	Mon Oct  2 21:19:14 2006
+++ exosip/jauth.c	Sun Feb 25 12:38:55 2007
@@ -285,12 +285,12 @@
     char * pszQop = NULL;
     char * pszURI = osip_strdup_without_quote(rquri);
 
-    szNonceCount = osip_strdup("00000000");
-    sprintf(szNonceCount, "%08d", nc++);
-
     HASHHEX HA1;
     HASHHEX HA2 = "";
     HASHHEX Response;
+
+    szNonceCount = osip_strdup("00000000");
+    sprintf(szNonceCount, "%08d", nc++);
 
     pszPass=passwd;
 
