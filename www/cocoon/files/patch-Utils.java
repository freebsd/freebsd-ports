$FreeBSD$

--- src/org/apache/cocoon/Utils.java.orig	Sun May 12 13:30:49 2002
+++ src/org/apache/cocoon/Utils.java	Sun May 12 13:30:58 2002
@@ -331,16 +331,20 @@
      */
     public static final Object getLocationResource(String location) throws MalformedURLException {
         Object resource = null;
-        
+
         if (location.indexOf("://") < 0) {
             resource = new File(location);
         } else if (location.startsWith("resource://")) {
             // FIXME (SM): this should _not_ be system resource, but rather a resource of current classloader
-            resource = ClassLoader.getSystemResource(location.substring("resource://".length()));
+//            resource = ClassLoader.getSystemResource(location.substring("resource://".length()));
+
+            // The Fix!
+            Dummy classloadrefernce = new Dummy();
+            resource = classloadrefernce.getClass().getClassLoader().getResource(location.substring("resource://".length()));
         } else {
             resource = new URL(location);
         }
-        
+
         return resource;
     }
 
@@ -362,11 +366,20 @@
             resource = new File(location);
         } else if (location.startsWith("resource://")) {
             // FIXME (SM): this should _not_ be system resource, but rather a resource of current classloader
-            resource = ClassLoader.getSystemResource(location.substring("resource://".length()));
+//            resource = ClassLoader.getSystemResource(location.substring("resource://".length()));
+
+            // The Fix!
+            Dummy classloadrefernce = new Dummy();
+            resource = classloadrefernce.getClass().getClassLoader().getResource(location.substring("resource://".length()));
         } else {
             resource = new URL(location);
         }
-        
+
         return resource;
     }
+
+}
+
+class Dummy {
+    String why = "to provide a classloader ref";
 }
