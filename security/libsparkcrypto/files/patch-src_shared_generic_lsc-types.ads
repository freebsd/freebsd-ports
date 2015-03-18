--- src/shared/generic/lsc-types.ads.orig	2015-03-16 17:16:28 UTC
+++ src/shared/generic/lsc-types.ads
@@ -102,18 +102,14 @@ package LSC.Types is
 
    -- Convert 32-bit word to 32-bit byte array
    function Word32_To_Byte_Array32 (Value : Word32) return Byte_Array32_Type;
-   pragma Inline (Word32_To_Byte_Array32);
 
    -- Convert 32-bit byte array to 32-bit word
    function Byte_Array32_To_Word32 (Value : Byte_Array32_Type) return Word32;
-   pragma Inline (Byte_Array32_To_Word32);
 
    -- Convert 64-bit word to 64-bit byte array
    function Word64_To_Byte_Array64 (Value : Word64) return Byte_Array64_Type;
-   pragma Inline (Word64_To_Byte_Array64);
 
    -- Convert 64-bit byte array to 64-bit word
    function Byte_Array64_To_Word64 (Value : Byte_Array64_Type) return Word64;
-   pragma Inline (Byte_Array64_To_Word64);
 
 end LSC.Types;
