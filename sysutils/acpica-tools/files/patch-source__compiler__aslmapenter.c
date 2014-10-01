--- ../../source/compiler/aslmapenter.c.orig	2014-09-26 14:02:30.000000000 -0400
+++ ../../source/compiler/aslmapenter.c	2014-09-30 16:57:24.000000000 -0400
@@ -216,6 +216,7 @@
     ACPI_GPIO_INFO          *Info;
     ACPI_GPIO_INFO          *NextGpio;
     ACPI_GPIO_INFO          *PrevGpio;
+    char                    *Buffer;
 
 
     /*
@@ -223,8 +224,8 @@
      * sorted by both source device name and then the pin number. There is
      * one block per pin.
      */
-    Info = ACPI_CAST_PTR (ACPI_GPIO_INFO,
-        UtStringCacheCalloc (sizeof (ACPI_GPIO_INFO)));
+    Buffer = UtStringCacheCalloc (sizeof (ACPI_GPIO_INFO));
+    Info = ACPI_CAST_PTR (ACPI_GPIO_INFO, Buffer);
 
     NextGpio = Gbl_GpioList;
     PrevGpio = NULL;
@@ -293,14 +294,15 @@
     ACPI_SERIAL_INFO        *Info;
     ACPI_SERIAL_INFO        *NextSerial;
     ACPI_SERIAL_INFO        *PrevSerial;
+    char                    *Buffer;
 
 
     /*
      * Allocate a new info block and insert it into the global Serial list
      * sorted by both source device name and then the address.
      */
-    Info = ACPI_CAST_PTR (ACPI_SERIAL_INFO,
-        UtStringCacheCalloc (sizeof (ACPI_SERIAL_INFO)));
+    Buffer = UtStringCacheCalloc (sizeof (ACPI_SERIAL_INFO));
+    Info = ACPI_CAST_PTR (ACPI_SERIAL_INFO, Buffer);
 
     NextSerial = Gbl_SerialList;
     PrevSerial = NULL;
