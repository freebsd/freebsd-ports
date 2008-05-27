--- src/jrdesktop/main.java.orig	2008-05-27 13:52:51.000000000 +0200
+++ src/jrdesktop/main.java	2008-05-27 14:00:39.000000000 +0200
@@ -1,5 +1,7 @@
 package jrdesktop;
 
+import java.io.File;
+
 import java.net.URL;
 import java.util.jar.Attributes;
 import java.util.jar.Manifest;
@@ -27,6 +29,8 @@
     public static final URL NORMAL_SCREEN_ICON = main.class.getResource("images/view_nofullscreen.png");
     public static final URL DEFAULT_SCREEN_ICON = main.class.getResource("images/default_screen.png");
     public static final URL CUSTOM_SCREEN_ICON = main.class.getResource("images/custom_screen.png");
+
+    public static String CONFIG_DIR;
     
     public static String CONFIG_FILE;
     public static String SERVER_CONFIG_FILE;
@@ -37,14 +41,21 @@
         
     public static void main (String args[]) {          
         if (System.getSecurityManager() == null)
-	    System.setSecurityManager(new SecurityMng());       
+	    System.setSecurityManager(new SecurityMng());
+
+        CONFIG_DIR = System.getProperty("user.home") + File.separatorChar + ".jrdesktop";
+
+        File configDir = new File(CONFIG_DIR);
+
+        if(!configDir.exists())
+            configDir.mkdir();
 
-        CONFIG_FILE = FileUtility.getCurrentDirectory() + "config";
-        SERVER_CONFIG_FILE = FileUtility.getCurrentDirectory() + "server.config";
-        VIEWER_CONFIG_FILE = FileUtility.getCurrentDirectory() + "viewer.config";    
+        CONFIG_FILE =  CONFIG_DIR + File.separatorChar + "config";
+        SERVER_CONFIG_FILE = CONFIG_DIR + File.separatorChar + "server.config";
+        VIEWER_CONFIG_FILE = CONFIG_DIR + File.separatorChar + "viewer.config";    
     
-        KEY_STORE = FileUtility.getCurrentDirectory() + "keystore";   
-        TRUST_STORE = FileUtility.getCurrentDirectory() + "truststore";
+        KEY_STORE = CONFIG_DIR + File.separatorChar + "keystore";   
+        TRUST_STORE = CONFIG_DIR + File.separatorChar + "truststore";
     
         System.getProperties().remove("java.rmi.server.hostname");        
                           
