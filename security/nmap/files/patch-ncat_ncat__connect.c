--- ncat/ncat_connect.c
+++ ncat/ncat_connect.c
@@ -1064,12 +1064,17 @@ int ncat_connect(void)
             bye("Failed to set hostname on iod.");
         if (o.ssl)
         {
+            /* connect_handler creates stdin_nsi and calls post_connect */
             nsock_reconnect_ssl(mypool, cs.sock_nsi, connect_handler, o.conntimeout, NULL, NULL);
         }
+        else
+        {
+            /* Create IOD for nsp->stdin */
+            if ((cs.stdin_nsi = nsock_iod_new2(mypool, 0, NULL)) == NULL)
+                bye("Failed to create stdin nsiod.");
 
-        /* Create IOD for nsp->stdin */
-        if ((cs.stdin_nsi = nsock_iod_new2(mypool, 0, NULL)) == NULL)
-            bye("Failed to create stdin nsiod.");
+            post_connect(mypool, cs.sock_nsi);
+        }
     }
 
     /* connect */
