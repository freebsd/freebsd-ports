--- bakery/FileSelection/FileSelection.h.orig	Wed Dec  4 12:58:55 2002
+++ bakery/FileSelection/FileSelection.h	Wed Dec  4 12:59:02 2002
@@ -43,7 +43,7 @@
  : public Gtk::FileSelection
 {
 public: 
-	FileSelection(const Gtk::nstring& title = 0);
+	FileSelection(const Gtk::nstring&);
 	virtual ~FileSelection();
 
 	virtual bool run(); //returns false if nothing was selected.
