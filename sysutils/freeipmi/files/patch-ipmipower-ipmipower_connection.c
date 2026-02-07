--- ipmipower/ipmipower_connection.c.orig	2018-02-02 22:03:33 UTC
+++ ipmipower/ipmipower_connection.c
@@ -297,8 +297,7 @@ _connection_setup (struct ipmipower_conn
 
   if ((ret = getaddrinfo (ic->hostname, port_str, &ai_hints, &ai_res)))
     {
-      if (ret == EAI_NODATA
-	  || ret == EAI_NONAME)
+      if (ret == EAI_NONAME)
         ipmipower_output (IPMIPOWER_MSG_TYPE_HOSTNAME_INVALID, ic->hostname, NULL);
       else
         {
