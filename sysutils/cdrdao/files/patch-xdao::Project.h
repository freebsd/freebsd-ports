--- xdao/Project.h.orig	12 Feb 2004 01:13:32 -0000	1.11
+++ xdao/Project.h	4 Jun 2004 21:52:40 -0000	1.11.2.1
@@ -51,14 +51,12 @@
   virtual void createToolbar() = 0;
   virtual void createStatusbar();
   void updateWindowTitle();
-  void saveProject();
   void saveAsProject();
   Gtk::FileSelection *saveFileSelector_;
   void saveFileSelectorOKCB();
   void saveFileSelectorCancelCB();
 
   virtual bool on_delete_event(GdkEventAny *event);
-  virtual void recordToc2CD() = 0;
   virtual void projectInfo() = 0;
 
 public:
@@ -67,7 +65,9 @@
   void readToc(char *name);
   void statusMessage(const char *fmt, ...);
   void tocBlockedMsg(const char *);
-  virtual bool closeProject() = 0;
+  virtual bool closeProject() = 0; 
+  virtual void saveProject();
+  virtual void recordToc2CD() = 0;
   int projectNumber();
   TocEdit *tocEdit();
   gint getViewNumber();
