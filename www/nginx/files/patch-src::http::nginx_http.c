--- src/http/ngx_http.c.orig	2008-03-24 16:04:02.000000000 +0300
+++ src/http/ngx_http.c	2008-08-27 22:11:11.000000000 +0400
@@ -558,6 +558,7 @@
 
                         in_addr[a].core_srv_conf = cscfp[s];
                         in_addr[a].default_server = 1;
+                        in_addr[a].listen_conf = &lscf[l].conf;
                     }
 
                     goto found;
