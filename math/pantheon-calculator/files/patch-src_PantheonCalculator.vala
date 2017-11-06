--- src/PantheonCalculator.vala.orig	2017-01-19 21:18:25 UTC
+++ src/PantheonCalculator.vala
@@ -59,6 +59,7 @@ namespace PantheonCalculator {
 
         public override void activate () {
             window = new PantheonCalculator.MainWindow ();
+            window.icon_name = "accessories-calculator";
             this.add_window (window);
         }
     }
