--- src/renderer/scripting/KReportGroupTracker.h.orig	2020-06-04 20:15:12 UTC
+++ src/renderer/scripting/KReportGroupTracker.h
@@ -12,7 +12,7 @@ class KREPORT_EXPORT KReportGroupTracker : public QObj
 
 protected:
     KReportGroupTracker() {}
-    ~KReportGroupTracker() override{}
+    ~KReportGroupTracker() override;
 
 public:
     Q_SLOT virtual void setGroupData(const QMap<QString, QVariant> &groupData) = 0;
