--- src/device/k3bdevicemanager.h.orig	Wed Jan 21 11:20:11 2004
+++ src/device/k3bdevicemanager.h	Fri Feb 13 21:03:38 2004
@@ -24,6 +24,10 @@
 #include <qptrlist.h>
 
 #include <kdebug.h>
+#ifdef __FreeBSD__
+#include <qdatetime.h>
+#include <qvaluelist.h>
+#endif
 
 class KProcess;
 class KConfig;
@@ -112,6 +116,29 @@
 
       class Private;
       Private* d;
+#ifdef __FreeBSD__
+      void bsd_scan_devices(bool sudo);
+      QDateTime m_lastRefresh;
+      class BSDDevice
+      {
+      public:
+          BSDDevice() : m_bus(-1), m_target(-1), m_lun(-1) {}
+          BSDDevice(const QString & name, const QString & passDevice, const QString & vendor,
+                    const QString & product, const QString & revision, int bus, int target, int lun) :
+              m_name(name), m_passDevice(passDevice), m_vendor(vendor), m_product(product),
+              m_revision(revision), m_bus(bus), m_target(target), m_lun(lun) {}
+          BSDDevice(const BSDDevice & src) :
+              m_name(src.m_name), m_passDevice(src.m_passDevice), m_vendor(src.m_vendor), m_product(src.m_product),
+              m_revision(src.m_revision), m_bus(src.m_bus), m_target(src.m_target), m_lun(src.m_lun) {}
+          const BSDDevice & operator= (const BSDDevice & src)
+          { m_name = src.m_name; m_passDevice = src.m_passDevice; m_vendor = src.m_vendor;
+            m_product = src.m_product; m_revision = src.m_revision; m_bus = src.m_bus; m_target = src.m_target;
+            m_lun = src.m_lun; return *this; }
+          QString m_name, m_passDevice, m_vendor, m_product, m_revision;
+          int m_bus, m_target, m_lun;
+      };
+      QValueList<BSDDevice> m_devices;
+#endif
     };
 }
 
