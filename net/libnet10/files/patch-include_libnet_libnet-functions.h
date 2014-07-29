--- include/libnet/libnet-functions.h.orig	Fri Jun  7 00:31:29 2002
+++ include/libnet/libnet-functions.h	Fri Jun  7 00:31:41 2002
@@ -74,7 +74,7 @@
     int,                /* severity */
     char *,             /* error message */
     ...                 /* varargs */
-    );
+    ) __printflike(2, 3);
 
 
 /*
