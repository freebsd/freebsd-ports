--- ./Network/HTTP/Server.hs.orig	2009-06-13 03:58:45.000000000 +0200
+++ ./Network/HTTP/Server.hs	2012-05-13 21:03:32.137467690 +0200
@@ -123,8 +123,9 @@
 
   client sock addr =
     do let name = ppSockAddr addr ""
+       let port = ppSockPort addr
        logInfo lg 0 ("Accepted connection from " ++ name)
-       conn <- socketConnection name sock    -- XXX: name?
+       conn <- socketConnection name port sock    -- XXX: name?
        setStreamHooks conn nullHooks { hook_close = 
           logInfo lg 0 ("Closing  connection to " ++ ppSockAddr addr "")
              }
