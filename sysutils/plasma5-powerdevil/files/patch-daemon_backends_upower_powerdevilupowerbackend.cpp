--- daemon/backends/upower/powerdevilupowerbackend.cpp.orig	2017-12-10 06:14:30 UTC
+++ daemon/backends/upower/powerdevilupowerbackend.cpp
@@ -41,7 +41,7 @@
 #include "ddcutilbrightness.h"
 #include "upowersuspendjob.h"
 #include "login1suspendjob.h"
-#include "udevqt.h"
+//#include "udevqt.h"
 
 #define HELPER_ID "org.kde.powerdevil.backlighthelper"
 
@@ -200,8 +200,10 @@ void PowerDevilUPowerBackend::init()
 
                                     m_isLedBrightnessControl = m_syspath.contains(QLatin1String("/leds/"));
                                     if (!m_isLedBrightnessControl) {
+                                    /*
                                         UdevQt::Client *client =  new UdevQt::Client(QStringList("backlight"), this);
                                         connect(client, SIGNAL(deviceChanged(UdevQt::Device)), SLOT(onDeviceChanged(UdevQt::Device)));
+                                        */
                                     }
 
                                     Q_EMIT brightnessSupportQueried(m_brightnessMax > 0);
@@ -358,6 +360,7 @@ void PowerDevilUPowerBackend::initWithBr
 
 void PowerDevilUPowerBackend::onDeviceChanged(const UdevQt::Device &device)
 {
+    /*
     qCDebug(POWERDEVIL) << "Udev device changed" << m_syspath << device.sysfsPath();
     if (device.sysfsPath() != m_syspath) {
         return;
@@ -373,6 +376,7 @@ void PowerDevilUPowerBackend::onDeviceCh
         m_cachedBrightnessMap[Screen] = newBrightness;
         onBrightnessChanged(Screen, newBrightness, maxBrightness);
     }
+    */
 }
 
 int PowerDevilUPowerBackend::brightnessKeyPressed(PowerDevil::BrightnessLogic::BrightnessKeyType type, BrightnessControlType controlType)
