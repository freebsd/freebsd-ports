--- ../../source/common/ahuuids.c.orig	2015-05-15 19:49:17.000000000 -0400
+++ ../../source/common/ahuuids.c	2015-06-03 16:12:16.360898000 -0400
@@ -43,6 +43,7 @@
 
 #include "acpi.h"
 #include "accommon.h"
+#include "acuuid.h"
 
 #define _COMPONENT          ACPI_UTILITIES
         ACPI_MODULE_NAME    ("ahuuids")
@@ -52,44 +53,36 @@
  */
 const AH_UUID  AcpiUuids[] =
 {
-    {"PCI Host Bridge Device",
-        "33db4d5b-1ff7-401c-9657-7441c03dd766"},
-
-    {"Platform-wide Capabilities",
-        "0811b06e-4a27-44f9-8d60-3cbbc22e7b48"},
-
-    {"Dynamic Enumeration",
-        "d8c1a3a6-be9b-4c9b-91bf-c3cb81fc5daf"},
-
-    {"GPIO Controller",
-        "4f248f40-d5e2-499f-834c-27758ea1cd3f"},
-
-    {"Battery Thermal Limit",
-        "4c2067e3-887d-475c-9720-4af1d3ed602e"},
-
-    {"Thermal Extensions",
-        "14d399cd-7a27-4b18-8fb4-7cb7b9f4e500"},
-
-    {"USB Controller",
-        "ce2ee385-00e6-48cb-9f05-2edb927c4899"},
-
-    {"HID I2C Device",
-        "3cdff6f7-4267-4555-ad05-b30a3d8938de"},
-
-    {"Power Button Device",
-        "dfbcf3c5-e7a5-44e6-9c1f-29c76f6e059c"},
-
-    {"Device Labeling Interface",
-        "e5c937d0-3553-4d7a-9117-ea4d19c3434d"},
-
-    {"SATA Controller",
-        "e4db149b-fcfe-425b-a6d8-92357d78fc7f"},
-
-    {"Physical Presence Interface",
-        "3dddfaa6-361b-4eb4-a424-8d10089d1653"},
-
-    {"Device Properties for _DSD",
-        "daffd814-6eba-4d8c-8a91-bc9bbf4aa301"},
+    {"[Controllers]",               NULL},
+    {"GPIO Controller",             UUID_GPIO_CONTROLLER},
+    {"USB Controller",              UUID_USB_CONTROLLER},
+    {"SATA Controller",             UUID_SATA_CONTROLLER},
+
+    {"[Devices]",                   NULL},
+    {"PCI Host Bridge Device",      UUID_PCI_HOST_BRIDGE},
+    {"HID I2C Device",              UUID_I2C_DEVICE},
+    {"Power Button Device",         UUID_POWER_BUTTON},
+
+    {"[Interfaces]",                NULL},
+    {"Device Labeling Interface",   UUID_DEVICE_LABELING},
+    {"Physical Presence Interface", UUID_PHYSICAL_PRESENCE},
+
+    {"[Non-volatile DIMM and NFIT table]",       NULL},
+    {"Volatile Memory Region",      UUID_VOLATILE_MEMORY},
+    {"Persistent Memory Region",    UUID_PERSISTENT_MEMORY},
+    {"NVDIMM Control Region",       UUID_CONTROL_REGION},
+    {"NVDIMM Data Region",          UUID_DATA_REGION},
+    {"Volatile Virtual Disk",       UUID_VOLATILE_VIRTUAL_DISK},
+    {"Volatile Virtual CD",         UUID_VOLATILE_VIRTUAL_CD},
+    {"Persistent Virtual Disk",     UUID_PERSISTENT_VIRTUAL_DISK},
+    {"Persistent Virtual CD",       UUID_PERSISTENT_VIRTUAL_CD},
+
+    {"[Miscellaneous]",             NULL},
+    {"Platform-wide Capabilities",  UUID_PLATFORM_CAPABILITIES},
+    {"Dynamic Enumeration",         UUID_DYNAMIC_ENUMERATION},
+    {"Battery Thermal Limit",       UUID_BATTERY_THERMAL_LIMIT},
+    {"Thermal Extensions",          UUID_THERMAL_EXTENSIONS},
+    {"Device Properties for _DSD",  UUID_DEVICE_PROPERTIES},
 
     {NULL, NULL}
 };
@@ -120,6 +113,13 @@
 
     for (Info = AcpiUuids; Info->Description; Info++)
     {
+        /* Null string means desciption is a UUID class */
+
+        if (!Info->String)
+        {
+            continue;
+        }
+
         AcpiUtConvertStringToUuid (Info->String, UuidBuffer);
 
         if (!ACPI_MEMCMP (Data, UuidBuffer, UUID_BUFFER_LENGTH))
