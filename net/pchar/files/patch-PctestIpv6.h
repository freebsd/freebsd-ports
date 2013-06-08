--- PctestIpv6.h.orig	2005-02-13 05:32:18.000000000 +0900
+++ PctestIpv6.h	2013-05-06 00:36:41.683117194 +0900
@@ -82,7 +82,7 @@
     virtual char *GetPrintableAddress();
     virtual char *GetPrintableAddress(void *a);
     virtual char *GetName(void *a);
-    virtual char *GetAddressFamilyString() { return "AF_INET6"; }
+    virtual const char *GetAddressFamilyString() { return "AF_INET6"; }
     virtual int GetAddressFamily() { return (AF_INET6); }
     
   protected:
