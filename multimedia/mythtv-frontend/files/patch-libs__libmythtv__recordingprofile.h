--- ./libs/libmythtv/recordingprofile.h.orig	2009-10-22 03:30:12.000000000 +0400
+++ ./libs/libmythtv/recordingprofile.h	2010-12-01 23:01:20.247699483 +0300
@@ -84,7 +84,7 @@
 
   public:
     // initializers
-    RecordingProfile(QString profName = NULL);
+    RecordingProfile(QString profName = QString());
     virtual void loadByID(int id);
     virtual bool loadByType(const QString &name, const QString &cardtype);
     virtual bool loadByGroup(const QString &name, const QString &group);
