--- src/core/device/k3bdevice.h.orig	Thu Oct 23 10:37:05 2003
+++ src/core/device/k3bdevice.h	Fri Nov  7 12:35:44 2003
@@ -21,6 +21,10 @@
 #include <k3bdiskinfo.h>
 #include <k3bcdtext.h>
 #include <k3bmsf.h>
+#ifdef __FreeBSD__
+#include "k3btoc.h"
+#include <qdatetime.h>
+#endif
 
 
 namespace K3bCdDevice
@@ -43,10 +47,10 @@
                          CDROM = 4,
                          DVD = 8,
                          DVDRAM = 16,
-                         DVDR = 32,
-                         DVDRW = 64,
-                         DVDPR = 128,
-                         DVDPRW = 256 };
+                         DVDR = 32, // "minus"
+                         DVDRW = 64, // "minus"
+                         DVDPR = 128, // "plus"
+                         DVDPRW = 256 }; // "plus"
     enum DiskStatus { EMPTY = 0,
                       APPENDABLE = 1,
                       COMPLETE = 2,
@@ -420,6 +424,21 @@
   private:
     class Private;
     Private* d;
+#ifdef __FreeBSD__
+    // allow K3bDeviceManager::initializeScsiDevice to set the device types
+    void addDeviceType(CdDevice::DeviceType type);
+
+    // allow K3bDeviceManager::initializeScsiDevice to guess the profiles, if none where found so far
+    void guessProfiles();
+
+    Toc m_toc;
+    int m_driveReady, m_rewritableCd;
+    K3b::Msf m_discSize, m_remainingSize;
+    void refreshDeviceData();
+    QDateTime m_lastRefresh;
+    int m_deviceStatus;
+    QString m_passDevice;
+#endif
     friend class DeviceManager;
   };
 
