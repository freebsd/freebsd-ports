--- source/compiler/aslrestype2s.c.orig	2022-10-20 21:12:58 UTC
+++ source/compiler/aslrestype2s.c
@@ -1550,7 +1550,6 @@ RsDoPinFunctionDescriptor (
     UINT16                  PinListLength;
     UINT16                  DescriptorSize;
     UINT32                  CurrentByteOffset;
-    UINT32                  PinCount = 0;
     UINT32                  i;
 
     InitializerOp = Info->DescriptorTypeOp->Asl.Child;
@@ -1668,15 +1667,10 @@ RsDoPinFunctionDescriptor (
         default:
             /*
              * PINs come through here, repeatedly. Each PIN must be a WORD.
-             * NOTE: there is no "length" field for this, so from ACPI spec:
-             *  The number of pins in the table can be calculated from:
-             *  PinCount = (Resource Source Name Offset - Pin Table Offset) / 2
-             *  (implies resource source must immediately follow the pin list.)
              *  Name: _PIN
              */
             *PinList = (UINT16) InitializerOp->Asl.Value.Integer;
             PinList++;
-            PinCount++;
 
             /* Case 8: First pin number in list */
 
@@ -1736,7 +1730,6 @@ RsDoPinConfigDescriptor (
     UINT16                  PinListLength;
     UINT16                  DescriptorSize;
     UINT32                  CurrentByteOffset;
-    UINT32                  PinCount = 0;
     UINT32                  i;
 
     InitializerOp = Info->DescriptorTypeOp->Asl.Child;
@@ -1868,15 +1861,10 @@ RsDoPinConfigDescriptor (
         default:
             /*
              * PINs come through here, repeatedly. Each PIN must be a WORD.
-             * NOTE: there is no "length" field for this, so from ACPI spec:
-             *  The number of pins in the table can be calculated from:
-             *  PinCount = (Resource Source Name Offset - Pin Table Offset) / 2
-             *  (implies resource source must immediately follow the pin list.)
              *  Name: _PIN
              */
             *PinList = (UINT16) InitializerOp->Asl.Value.Integer;
             PinList++;
-            PinCount++;
 
             /* Case 8: First pin number in list */
 
@@ -1936,7 +1924,6 @@ RsDoPinGroupDescriptor (
     UINT16                  PinListLength;
     UINT16                  DescriptorSize;
     UINT32                  CurrentByteOffset;
-    UINT32                  PinCount = 0;
     UINT32                  i;
 
     InitializerOp = Info->DescriptorTypeOp->Asl.Child;
@@ -2022,15 +2009,10 @@ RsDoPinGroupDescriptor (
         default:
             /*
              * PINs come through here, repeatedly. Each PIN must be a WORD.
-             * NOTE: there is no "length" field for this, so from ACPI spec:
-             *  The number of pins in the table can be calculated from:
-             *  PinCount = (Resource Source Name Offset - Pin Table Offset) / 2
-             *  (implies resource source must immediately follow the pin list.)
              *  Name: _PIN
              */
             *PinList = (UINT16) InitializerOp->Asl.Value.Integer;
             PinList++;
-            PinCount++;
 
             /* Case 3: First pin number in list */
 
