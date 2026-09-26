--- components/autofill/core/browser/integrators/autofill_ai/management_util.cc.orig	2026-09-25 15:26:43 UTC
+++ components/autofill/core/browser/integrators/autofill_ai/management_util.cc
@@ -49,7 +49,7 @@ EntityTypeResources GetResourcesForType(EntityTypeName
           .section_title_id = IDS_AUTOFILL_AI_DRIVERS_LICENSES_TITLE,
           .add_entity_id = IDS_AUTOFILL_AI_ADD_DRIVERS_LICENSE_ENTITY,
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           .add_entity_branded_id = ResolveStringIdsForWalletPass2026Experiment(
               IDS_AUTOFILL_AI_ADD_DRIVERS_LICENSE_ENTITY_BRANDED,
               IDS_AUTOFILL_AI_ADD_DRIVERS_LICENSE_ENTITY_VARIANT_1_BRANDED,
@@ -63,7 +63,7 @@ EntityTypeResources GetResourcesForType(EntityTypeName
           .section_title_id = IDS_AUTOFILL_AI_KNOWN_TRAVELER_NUMBER_TITLE,
           .add_entity_id = IDS_AUTOFILL_AI_ADD_KNOWN_TRAVELER_NUMBER_ENTITY,
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           .add_entity_branded_id = ResolveStringIdsForWalletPass2026Experiment(
               IDS_AUTOFILL_AI_ADD_KNOWN_TRAVELER_NUMBER_ENTITY_BRANDED,
               IDS_AUTOFILL_AI_ADD_KNOWN_TRAVELER_NUMBER_ENTITY_VARIANT_1_BRANDED,
@@ -78,7 +78,7 @@ EntityTypeResources GetResourcesForType(EntityTypeName
           .section_title_id = IDS_AUTOFILL_AI_NATIONAL_IDS_SHORT_TITLE,
           .add_entity_id = IDS_AUTOFILL_AI_ADD_NATIONAL_ID_CARD_ENTITY,
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           .add_entity_branded_id = ResolveStringIdsForWalletPass2026Experiment(
               IDS_AUTOFILL_AI_ADD_ID_CARD_ENTITY_BRANDED,
               IDS_AUTOFILL_AI_ADD_ID_CARD_ENTITY_VARIANT_1_BRANDED,
@@ -92,7 +92,7 @@ EntityTypeResources GetResourcesForType(EntityTypeName
           .section_title_id = IDS_AUTOFILL_AI_PASSPORTS_TITLE,
           .add_entity_id = IDS_AUTOFILL_AI_ADD_PASSPORT_ENTITY,
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           .add_entity_branded_id = ResolveStringIdsForWalletPass2026Experiment(
               IDS_AUTOFILL_AI_ADD_PASSPORT_ENTITY_BRANDED,
               IDS_AUTOFILL_AI_ADD_PASSPORT_ENTITY_VARIANT_1_BRANDED,
@@ -106,7 +106,7 @@ EntityTypeResources GetResourcesForType(EntityTypeName
           .section_title_id = IDS_AUTOFILL_AI_REDRESS_NUMBER_TITLE,
           .add_entity_id = IDS_AUTOFILL_AI_ADD_REDRESS_NUMBER_ENTITY,
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           .add_entity_branded_id = ResolveStringIdsForWalletPass2026Experiment(
               IDS_AUTOFILL_AI_ADD_REDRESS_NUMBER_ENTITY_BRANDED,
               IDS_AUTOFILL_AI_ADD_REDRESS_NUMBER_ENTITY_VARIANT_1_BRANDED,
@@ -120,7 +120,7 @@ EntityTypeResources GetResourcesForType(EntityTypeName
           .section_title_id = IDS_AUTOFILL_AI_VEHICLES_TITLE,
           .add_entity_id = IDS_AUTOFILL_AI_ADD_VEHICLE_ENTITY,
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           .add_entity_branded_id = ResolveStringIdsForWalletPass2026Experiment(
               IDS_AUTOFILL_AI_ADD_VEHICLE_ENTITY_BRANDED,
               IDS_AUTOFILL_AI_ADD_VEHICLE_ENTITY_VARIANT_1_BRANDED,
