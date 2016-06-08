--- ./chrome/browser/ui/gtk/web_dialog_gtk.h.orig	2014-04-30 22:42:07.000000000 +0200
+++ ./chrome/browser/ui/gtk/web_dialog_gtk.h	2014-05-04 20:50:58.000000000 +0200
@@ -62,7 +62,7 @@
                               const gfx::Rect& initial_pos,
                               bool user_gesture,
                               bool* was_blocked) OVERRIDE;
-  virtual void LoadingStateChanged(content::WebContents* source) OVERRIDE;
+  virtual void LoadingStateChanged(content::WebContents* source) /*OVERRIDE*/;
 
  private:
   CHROMEGTK_CALLBACK_1(WebDialogGtk, void, OnResponse, int);
