--- src/gui.h.orig	Thu Feb 24 14:11:10 2005
+++ src/gui.h	Thu Feb 24 14:11:12 2005
@@ -140,7 +140,6 @@ public:
 class ParamDialog : public Gtk::Dialog
 {
 protected:
-	void ok_click ();
 
 	virtual int delete_event_impl (GdkEventAny *ev);
 	virtual void get_data () = 0;
@@ -148,6 +147,7 @@ protected:
 public:
 	bool cancelled;
 
+	void ok_click ();
 	ParamDialog (const String &title = "Prefab Parameter");
 };
 
