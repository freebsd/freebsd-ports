--- ./Source/WebCore/editing/Editor.h.orig	2012-08-04 16:33:45.000000000 +0200
+++ ./Source/WebCore/editing/Editor.h	2012-08-04 16:34:06.000000000 +0200
@@ -385,7 +385,7 @@
     void deviceScaleFactorChanged();
 
 private:
-    virtual void willDetachPage() OVERRIDE;
+    virtual void willDetachPage();
 
     OwnPtr<DeleteButtonController> m_deleteButtonController;
     RefPtr<CompositeEditCommand> m_lastEditCommand;
