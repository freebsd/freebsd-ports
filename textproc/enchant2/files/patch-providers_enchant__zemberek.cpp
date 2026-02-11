--- providers/enchant_zemberek.cpp.orig	2025-07-29 20:10:16 UTC
+++ providers/enchant_zemberek.cpp
@@ -233,7 +233,7 @@ zemberek_provider_list_dicts (EnchantProvider * me _GL
     }
 }
 
-static
+static void
 zemberek_provider_dispose (EnchantProvider * me _GL_UNUSED)
 {
 	provider = NULL;
