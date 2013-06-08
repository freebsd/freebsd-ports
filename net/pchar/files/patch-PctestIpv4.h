--- PctestIpv4.h.orig	2005-02-13 05:32:18.000000000 +0900
+++ PctestIpv4.h	2013-05-06 00:36:17.432762986 +0900
@@ -77,7 +77,7 @@
     virtual char *GetPrintableAddress();
     virtual char *GetPrintableAddress(void *a);
     virtual char *GetName(void *a);
-    virtual char *GetAddressFamilyString() { return "AF_INET"; };
+    virtual const char *GetAddressFamilyString() { return "AF_INET"; };
     virtual int GetAddressFamily() { return (AF_INET); };
     
   protected:
