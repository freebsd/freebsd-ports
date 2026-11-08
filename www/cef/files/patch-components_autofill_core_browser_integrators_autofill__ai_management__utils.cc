--- components/autofill/core/browser/integrators/autofill_ai/management_utils.cc.orig	2026-08-31 10:59:09 UTC
+++ components/autofill/core/browser/integrators/autofill_ai/management_utils.cc
@@ -35,7 +35,7 @@ EntityTypeResources GetResourcesForType(EntityTypeName
           .section_title_id = IDS_AUTOFILL_AI_DRIVERS_LICENSES_TITLE,
           .add_entity_id = IDS_AUTOFILL_AI_ADD_DRIVERS_LICENSE_ENTITY,
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           .add_entity_branded_id = IDS_AUTOFILL_AI_SAVE_DRIVERS_LICENSE_ENTITY_DIALOG_TITLE_BRANDED,
 #endif
           .edit_entity_id = IDS_AUTOFILL_AI_EDIT_DRIVERS_LICENSE_ENTITY,
@@ -46,7 +46,7 @@ EntityTypeResources GetResourcesForType(EntityTypeName
           .section_title_id = IDS_AUTOFILL_AI_KNOWN_TRAVELER_NUMBER_TITLE,
           .add_entity_id = IDS_AUTOFILL_AI_ADD_KNOWN_TRAVELER_NUMBER_ENTITY,
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           .add_entity_branded_id =
               IDS_AUTOFILL_AI_SAVE_KNOWN_TRAVELER_NUMBER_ENTITY_DIALOG_TITLE_BRANDED,
 #endif
@@ -59,7 +59,7 @@ EntityTypeResources GetResourcesForType(EntityTypeName
           .section_title_id = IDS_AUTOFILL_AI_NATIONAL_IDS_SHORT_TITLE,
           .add_entity_id = IDS_AUTOFILL_AI_ADD_NATIONAL_ID_CARD_ENTITY,
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           .add_entity_branded_id =
               IDS_AUTOFILL_AI_SAVE_ID_CARD_ENTITY_DIALOG_TITLE_BRANDED,
 #endif
@@ -71,7 +71,7 @@ EntityTypeResources GetResourcesForType(EntityTypeName
           .section_title_id = IDS_AUTOFILL_AI_PASSPORTS_TITLE,
           .add_entity_id = IDS_AUTOFILL_AI_ADD_PASSPORT_ENTITY,
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           .add_entity_branded_id =
               IDS_AUTOFILL_AI_SAVE_PASSPORT_ENTITY_DIALOG_TITLE_BRANDED,
 #endif
@@ -83,7 +83,7 @@ EntityTypeResources GetResourcesForType(EntityTypeName
           .section_title_id = IDS_AUTOFILL_AI_REDRESS_NUMBER_TITLE,
           .add_entity_id = IDS_AUTOFILL_AI_ADD_REDRESS_NUMBER_ENTITY,
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           .add_entity_branded_id =
               IDS_AUTOFILL_AI_SAVE_REDRESS_NUMBER_ENTITY_DIALOG_TITLE_BRANDED,
 #endif
@@ -95,7 +95,7 @@ EntityTypeResources GetResourcesForType(EntityTypeName
           .section_title_id = IDS_AUTOFILL_AI_VEHICLES_TITLE,
           .add_entity_id = IDS_AUTOFILL_AI_ADD_VEHICLE_ENTITY,
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           .add_entity_branded_id =
               IDS_AUTOFILL_AI_SAVE_VEHICLE_ENTITY_DIALOG_TITLE_BRANDED,
 #endif
