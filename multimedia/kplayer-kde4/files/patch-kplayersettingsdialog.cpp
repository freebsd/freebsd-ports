--- kplayer/kplayersettingsdialog.cpp.orig	Sat Oct 16 02:16:39 2004
+++ kplayer/kplayersettingsdialog.cpp	Sat Oct 16 02:17:35 2004
@@ -271,7 +271,7 @@
     config -> deleteEntry ("Settings Dialog Page");
   else
     config -> writeEntry ("Settings Dialog Page", name);
-  setHelp (name.isEmpty() ? "settings" : "settings-" + name);
+  setHelp (name.isEmpty() ? QString::fromLatin1("settings") : "settings-" + name);
 }
 
 void KPlayerSettingsDialog::slotOk (void)
@@ -435,7 +435,7 @@
   KPlayerSettings* settings = kPlayerSettings();
   c_driver_fallback -> setChecked (index > 0 && settings -> audioDriverFallbackDefault());
   c_driver_fallback -> setEnabled (index > 0);
-  c_device -> setText (index > 0 ? settings -> audioDeviceDefault() : "");
+  c_device -> setText (index > 0 ? settings -> audioDeviceDefault() : QString::fromLatin1(""));
   c_device -> setEnabled (index > 0);
 }
 
@@ -792,7 +792,7 @@
   KPlayerSettings* settings = kPlayerSettings();
   c_driver_fallback -> setChecked (index > 0 && settings -> videoDriverFallbackDefault());
   c_driver_fallback -> setEnabled (index > 0);
-  c_device -> setText (index > 0 ? settings -> videoDeviceDefault() : "");
+  c_device -> setText (index > 0 ? settings -> videoDeviceDefault() : QString::fromLatin1(""));
   c_device -> setEnabled (index > 0);
 }
 
