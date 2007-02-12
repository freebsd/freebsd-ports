--- src/mod_sipxauth/SIPXAuthHandler.h.orig	Sun Feb 11 18:35:54 2007
+++ src/mod_sipxauth/SIPXAuthHandler.h	Sun Feb 11 18:42:19 2007
@@ -56,7 +56,7 @@
     };
 
     /** Ctor */
-    SIPXAuthHandler (void);
+    SIPXAuthHandler (ApacheServerRec *pRequest);
 
     /** Dtor */
     ~SIPXAuthHandler(void);
