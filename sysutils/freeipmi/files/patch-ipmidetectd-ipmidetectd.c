--- ipmidetectd/ipmidetectd.c.orig	2018-03-09 20:42:26 UTC
+++ ipmidetectd/ipmidetectd.c
@@ -263,12 +263,7 @@ _nodes_setup (void)
       ai_hints.ai_flags = (AI_V4MAPPED | AI_ADDRCONFIG);
 
       if ((ret = getaddrinfo (host_ptr, port_str, &ai_hints, &ai_res)))
-        {
-          if (ret == EAI_NODATA)
-            err_exit ("Invalid hostname: %s", host_ptr);
-          else
-            err_exit ("getaddrinfo %s: %s", host_ptr, gai_strerror (ret));
-        }
+        err_exit ("getaddrinfo %s: %s", host_ptr, gai_strerror (ret));
 
       /* Try all of the different answers we got, until we succeed. */
       for (ai = ai_res; ai != NULL; ai = ai->ai_next)
