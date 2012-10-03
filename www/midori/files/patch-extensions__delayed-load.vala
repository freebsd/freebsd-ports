--- ./extensions/delayed-load.vala.orig	2012-09-19 21:17:43.000000000 +0000
+++ ./extensions/delayed-load.vala	2012-09-21 16:51:55.000000000 +0000
@@ -86,7 +86,7 @@
                     item.ref();
 
                     int64 delay = item.get_meta_integer ("delay");
-                    if (delay == -2) {
+                    if (delay == Midori.Delay.PENDING_UNDELAY) {
                         view.reload (true);
                     }
                 }
@@ -124,7 +124,7 @@
             if (this.timeout == 0)
                 view.reload (true);
             else {
-                unowned TabShaker shaker = tasks.get (browser);
+                unowned TabShaker shaker = tasks.lookup (browser);
                 if (shaker != null) {
                     shaker.tasks.add (view);
                     Timeout.add (this.timeout, shaker.reload_tab);
@@ -141,7 +141,7 @@
                 item.ref();
 
                 int64 delay = item.get_meta_integer ("delay");
-                if (delay == -2 && new_view.progress < 1.0) {
+                if (delay == Midori.Delay.PENDING_UNDELAY && new_view.progress < 1.0) {
                     this.schedule_reload (browser, new_view);
                 }
             }
@@ -157,12 +157,12 @@
                 item.ref();
 
                 int64 delay = item.get_meta_integer ("delay");
-                if (delay != 1) {
+                if (delay != Midori.Delay.DELAYED) {
                     unowned WebKit.WebView web_view = view.get_web_view ();
                     WebKit.LoadStatus load_status = web_view.load_status;
                     if (load_status == WebKit.LoadStatus.FINISHED) {
                         if (this.timeout != 0)
-                            this.tasks.set (browser, new TabShaker (browser));
+                            this.tasks.replace (browser, new TabShaker (browser));
 
                         if (view.progress < 1.0)
                             this.schedule_reload (browser, view);
