--- src/extended/aws-services-web_block-context.ads.orig	2015-06-22 10:52:10 UTC
+++ src/extended/aws-services-web_block-context.ads
@@ -95,7 +95,7 @@ private
    use Ada;
    use GNAT;
 
-   pragma Suppress (Tampering_Check);
+   --  pragma Suppress (Tampering_Check);
    --  Suppress Tampering_Check until O608-005 fixed.
 
    package KV is new Containers.Indefinite_Hashed_Maps
