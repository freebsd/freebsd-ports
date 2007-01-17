--- programs/mythtv-setup/backendsettings.cpp~	Sat Aug 26 13:34:08 2006
+++ programs/mythtv-setup/backendsettings.cpp	Mon Jan 15 14:07:17 2007
@@ -386,7 +386,7 @@
 {
     GlobalLineEdit *gc = new GlobalLineEdit("ServerHaltCommand");
     gc->setLabel(QObject::tr("Server halt command"));
-    gc->setValue("sudo /sbin/halt -p");
+    gc->setValue("/sbin/shutdown -p now");
     gc->setHelpText(QObject::tr("The command used to halt the backends."));
     return gc;
 };
