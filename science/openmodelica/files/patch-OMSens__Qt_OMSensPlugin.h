--- OMSens_Qt/OMSensPlugin.h.orig	2025-11-26 07:56:10 UTC
+++ OMSens_Qt/OMSensPlugin.h
@@ -24,8 +24,8 @@ class OMSensPlugin: public QObject, public Information
 public:
   virtual void setOpenModelicaHome(const QString &omhome) override;
   virtual void setTempPath(const QString &path) override;
-  virtual void setOMSensPath(const QString &path) override;
-  virtual void setPython(const QString &path) override;
+  virtual void setOMSensPath(const QString &path);
+  virtual void setPython(const QString &path);
 
   // ModelInterface interface
 public:
