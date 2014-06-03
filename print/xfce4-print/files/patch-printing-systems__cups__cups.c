--- ./printing-systems/cups/cups.c.orig	2009-02-24 21:34:16.000000000 +0000
+++ ./printing-systems/cups/cups.c	2014-06-03 18:56:42.000000000 +0000
@@ -23,7 +23,9 @@
 
 #include <gmodule.h>
 
+#define _IPP_PRIVATE_STRUCTURES 1
 #include <cups/ipp.h>
+#undef _IPP_PRIVATE_STRUCTURES
 #include <cups/ppd.h>
 #include <cups/cups.h>
 #include <cups/language.h>
@@ -133,8 +135,8 @@
 
   language = cupsLangDefault ();
   request = ippNew ();
-  request->request.op.operation_id = operation_id;
-  request->request.op.request_id = 1;
+  ippSetOperation(request,operation_id);
+  ippSetRequestId(request,1);
 
   ippAddString (request, IPP_TAG_OPERATION, IPP_TAG_CHARSET, "attributes-charset", NULL, "utf-8");
 
@@ -242,7 +244,7 @@
 
       if (!request)
         continue;
-      if (request->state == IPP_ERROR || request->state == IPP_IDLE) {
+      if (ippGetState(request) == IPP_ERROR || request->state == IPP_IDLE) {
         ippDelete (request);
         continue;
       }
