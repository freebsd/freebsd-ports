--- ./org/gudy/azureus2/ui/swt/test/PrintTransferTypes.java.orig	Fri Nov  3 16:46:40 2006
+++ ./org/gudy/azureus2/ui/swt/test/PrintTransferTypes.java	Thu May  3 00:25:01 2007
@@ -40,7 +40,7 @@
 
         TransferData[] data = event.dataTypes;
         for (int i = 0; i < data.length; i++) {
-          int id = data[i].type;
+          long id = data[i].type;
           String name = getNameFromId(id);
           System.out.println("Data type is " + id + " " + name);
         }
@@ -96,8 +96,8 @@
   protected int[] getTypeIds() {
     return ids;
   }
-  static String getNameFromId(int id) {
-    switch (id) {
+  static String getNameFromId(long id) {
+    switch ((int)id) {
       case 1 :
         return "CF_TEXT";
       case 8 :
@@ -144,4 +144,4 @@
     }
     return "*UNKNOWN_TYPE*";
   }
-}
\ No newline at end of file
+}
