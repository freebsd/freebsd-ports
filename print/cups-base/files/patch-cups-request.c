--- cups/request.c
+++ cups/request.c
@@ -1004,6 +1004,25 @@
       httpClose(cg->http);
       cg->http = NULL;
     }
+    else
+    {
+     /*
+      * Same server, see if the connection is still established...
+      */
+
+      char ch;				/* Connection check byte */
+
+      if (recv(cg->http->fd, &ch, 1, MSG_PEEK | MSG_DONTWAIT) < 0 &&
+          errno != EWOULDBLOCK)
+      {
+       /*
+        * Nope, close the connection...
+        */
+
+	httpClose(cg->http);
+	cg->http = NULL;
+      }
+    }
   }
 
  /*
