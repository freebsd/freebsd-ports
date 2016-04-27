--- opentoken-production-parser-lalr-parser_lists.adb.orig	2015-05-10 19:22:40 UTC
+++ opentoken-production-parser-lalr-parser_lists.adb
@@ -484,7 +484,8 @@ package body OpenToken.Production.Parser
    is
       pragma Unreferenced (Container);
    begin
-      return (Element => Position.Item'Access);
+      --  WORKAROUND: gcc 6 reports an error for 'Access here; this passes all tests
+      return (Element => Position.Item'Unrestricted_Access);
    end Constant_Reference;
 
    type List_Access_Constant is access constant List;
