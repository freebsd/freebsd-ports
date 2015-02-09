--- ./chrome/browser/ui/gtk/tabs/dragged_tab_controller_gtk.h.orig	2014-04-30 22:42:07.000000000 +0200
+++ ./chrome/browser/ui/gtk/tabs/dragged_tab_controller_gtk.h	2014-05-04 20:49:17.000000000 +0200
@@ -92,7 +92,7 @@
                               const gfx::Rect& initial_pos,
                               bool user_gesture,
                               bool* was_blocked) OVERRIDE;
-  virtual void LoadingStateChanged(content::WebContents* source) OVERRIDE;
+  virtual void LoadingStateChanged(content::WebContents* source) /*OVERRIDE*/;
   virtual content::JavaScriptDialogManager*
       GetJavaScriptDialogManager() OVERRIDE;
   virtual void RequestMediaAccessPermission(
