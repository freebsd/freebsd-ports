Fix sockaddr type mismatch warnings (Fixed upstream in dbd7282)

--- netcam.c.orig	2016-10-25 01:39:24 UTC
+++ netcam.c
@@ -948,7 +948,7 @@ static int netcam_connect(netcam_context
     }
 
     /* Now the connect call will return immediately. */
-    ret = connect(netcam->sock, &server, sizeof(server));
+    ret = connect(netcam->sock, (struct sockaddr *)&server, sizeof(server));
     back_err = errno;           /* Save the errno from connect */
 
     /* If the connect failed with anything except EINPROGRESS, error. */
