--- src/xmlrpc_string.c.orig	2019-03-29 03:33:33 UTC
+++ src/xmlrpc_string.c
@@ -1,4 +1,3 @@
-#include <stdio.h>
 /*=============================================================================
                               xmlrpc_string
 ===============================================================================
@@ -746,15 +745,12 @@ stringNew(xmlrpc_env *     const envP,
           enum crTreatment const crTreatment,
           xmlrpc_value **  const valPP) {
 
-    fprintf(stderr, "stringNew entered\n");
     xmlrpc_value * valP;
 
     xmlrpc_validate_utf8(envP, value, length);
 
     if (!envP->fault_occurred) {
-        fprintf(stderr, "Going to xmlrpc_createXmlrpcValue\n");
         xmlrpc_createXmlrpcValue(envP, &valP);
-        fprintf(stderr, "Back from createXmlrpcValue\n");
 
         if (!envP->fault_occurred) {
             valP->_type = XMLRPC_TYPE_STRING;
@@ -774,7 +770,6 @@ stringNew(xmlrpc_env *     const envP,
                 *valPP = valP;
         }
     }
-    fprintf(stderr, "stringNew exiting\n");
 }
 
 
