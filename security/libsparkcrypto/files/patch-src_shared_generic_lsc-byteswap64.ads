--- src/shared/generic/lsc-byteswap64.ads.orig	2015-07-05 09:06:26 UTC
+++ src/shared/generic/lsc-byteswap64.ads
@@ -44,6 +44,5 @@ package LSC.Byteswap64 is
 
    -- Byte-swap @Value@
    function Swap (Value : Types.Word64) return Types.Word64;
-   pragma Inline (Swap);
 
 end LSC.Byteswap64;
