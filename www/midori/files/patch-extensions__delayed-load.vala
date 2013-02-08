--- ./extensions/delayed-load.vala.orig	2013-02-05 23:28:05.000000000 +0000
+++ ./extensions/delayed-load.vala	2013-02-07 06:05:11.000000000 +0000
@@ -123,7 +123,11 @@
             if (this.timeout == 0)
                 view.reload (true);
             else {
+#if !HAVE_GLIB_2_30
+                unowned TabShaker shaker = tasks.lookup (browser);
+#else
                 unowned TabShaker shaker = tasks.get (browser);
+#endif
                 if (shaker != null) {
                     shaker.tasks.add (view);
                     Midori.Timeout.add (this.timeout, shaker.reload_tab);
@@ -160,7 +164,11 @@
                     WebKit.LoadStatus load_status = view.web_view.load_status;
                     if (load_status == WebKit.LoadStatus.FINISHED) {
                         if (this.timeout != 0)
+#if !HAVE_GLIB_2_30
+                            this.tasks.replace (browser, new TabShaker (browser));
+#else
                             this.tasks.set (browser, new TabShaker (browser));
+#endif
 
                         if (view.progress < 1.0)
                             this.schedule_reload (browser, view);
