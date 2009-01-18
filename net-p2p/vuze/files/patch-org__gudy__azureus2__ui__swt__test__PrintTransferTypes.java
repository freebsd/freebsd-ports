--- org/gudy/azureus2/ui/swt/test/PrintTransferTypes.java.orig	2009-01-18 01:23:44.000000000 -0500
+++ org/gudy/azureus2/ui/swt/test/PrintTransferTypes.java	2009-01-18 01:24:54.000000000 -0500
@@ -40,7 +40,7 @@
 
         TransferData[] data = event.dataTypes;
         for (int i = 0; i < data.length; i++) {
-          int id = data[i].type;
+          int id = (int)data[i].type;
           String name = getNameFromId(id);
           System.out.println("Data type is " + id + " " + name);
         }
@@ -50,7 +50,7 @@
       }
       public void drop(DropTargetEvent event) {
         System.out.println("URL dropped: " + event.data);
-        System.out.println("Data type is " + event.currentDataType.type + " " + getNameFromId(event.currentDataType.type));
+        System.out.println("Data type is " + event.currentDataType.type + " " + getNameFromId((int)event.currentDataType.type));
       }
     });
 
