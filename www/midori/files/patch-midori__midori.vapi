--- ./midori/midori.vapi.orig	2012-09-19 21:17:43.000000000 +0000
+++ ./midori/midori.vapi	2012-09-21 14:15:47.000000000 +0000
@@ -124,6 +124,7 @@
         public string key { get; set; }
 
         public signal void activate (Midori.App app);
+        public signal bool is_prepared ();
         public signal void deactivate ();
         public signal void open_preferences ();
     }
@@ -190,6 +191,13 @@
         OPEN_IN_VIEWER
     }
 
+    [CCode (cheader_filename = "midori/midori-view.h", cprefix = "MIDORI_DELAY_")]
+    public enum Delay {
+        UNDELAYED,
+        DELAYED,
+        PENDING_UNDELAY,
+    }
+
     public class WebSettings : WebKit.WebSettings {
         public WebSettings ();
         [NoAccessorMethod]
