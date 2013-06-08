--- Pctest.h.orig	2005-02-13 05:32:18.000000000 +0900
+++ Pctest.h	2013-05-06 00:39:43.413338781 +0900
@@ -86,7 +86,7 @@
     virtual char *GetPrintableAddress() = 0;
     virtual char *GetPrintableAddress(void *a) = 0;
     virtual char *GetName(void *a) = 0;
-    virtual char *GetAddressFamilyString() = 0;
+    virtual const char *GetAddressFamilyString() = 0;
     virtual int GetAddressFamily() = 0;
 
     // Get input and output sockets needed
