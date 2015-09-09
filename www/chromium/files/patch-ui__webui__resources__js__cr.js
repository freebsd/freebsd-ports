--- ui/webui/resources/js/cr.js.orig	2015-09-05 09:28:39.153643000 -0400
+++ ui/webui/resources/js/cr.js	2015-09-05 09:29:44.511113000 -0400
@@ -431,5 +431,10 @@
     get isLinux() {
       return /Linux/.test(navigator.userAgent);
     },
+    
+    /** Whether this is on *BSD. */
+    get isBSD() {
+      return /BSD/.test(navigator.userAgent);
+    },
   };
 }();
