--- multiFuncData.h.orig	Sat Mar 21 04:26:34 1998
+++ multiFuncData.h	Wed Mar 17 17:36:27 2004
@@ -53,7 +53,7 @@
     virtual void setFuncOptions();
     virtual void closeMultiFunc();
     virtual void deleteFunction();
-    virtual void funcChanged(const char*);
+    virtual void funcChanged(const QString&);
 
 protected:
     QComboBox* multiFuncList;
