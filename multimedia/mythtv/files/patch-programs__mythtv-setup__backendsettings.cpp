--- ./programs/mythtv-setup/backendsettings.cpp.orig	2008-02-05 12:52:11.000000000 -0500
+++ ./programs/mythtv-setup/backendsettings.cpp	2009-02-23 09:59:26.000000000 -0500
@@ -425,7 +425,7 @@
 {
     GlobalLineEdit *gc = new GlobalLineEdit("ServerHaltCommand");
     gc->setLabel(QObject::tr("Server halt command"));
-    gc->setValue("sudo /sbin/halt -p");
+    gc->setValue("/sbin/shutdown -p now");
     gc->setHelpText(QObject::tr("The command used to halt the backends."));
     return gc;
 };
