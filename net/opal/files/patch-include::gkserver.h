--- include/gkserver.h	2004/08/28 17:16:13	1.1
+++ include/gkserver.h	2004/08/28 17:16:24
@@ -404,7 +404,6 @@
     H225_RegistrationConfirm & rcf;
     H225_RegistrationReject  & rrj;
 
-  protected:
     virtual Response OnHandlePDU();
 };
 
