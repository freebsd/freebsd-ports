$NetBSD: patch-src_soap_soap-message-xml.adb,v 1.1 2012/07/08 20:14:28 marino Exp $

--- src/soap/soap-message-xml.adb.orig	2012-07-05 03:56:08.000000000 +0000
+++ src/soap/soap-message-xml.adb
@@ -437,7 +437,8 @@ package body SOAP.Message.XML is
             Faultstring => SOAP.Parameters.Get (S.Parameters, "faultstring"));
       else
          return Message.Response.Object'
-           (S.Name_Space, S.Wrapper_Name, S.Parameters);
+           (Message.Object'(S.Name_Space, S.Wrapper_Name, S.Parameters)
+            with null record);
       end if;
 
    exception
@@ -483,7 +484,8 @@ package body SOAP.Message.XML is
             Faultstring => SOAP.Parameters.Get (S.Parameters, "faultstring"));
       else
          return Message.Response.Object'
-           (S.Name_Space, S.Wrapper_Name, S.Parameters);
+           (Message.Object'(S.Name_Space, S.Wrapper_Name, S.Parameters)
+            with null record);
       end if;
 
    exception
