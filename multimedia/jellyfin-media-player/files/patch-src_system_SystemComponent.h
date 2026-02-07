--- src/system/SystemComponent.h.orig	2025-03-18 16:40:48 UTC
+++ src/system/SystemComponent.h
@@ -65,7 +65,8 @@ class SystemComponent : public ComponentBase (public)
     platformTypeOsx,
     platformTypeWindows,
     platformTypeLinux,
-    platformTypeOpenELEC
+    platformTypeOpenELEC,
+    platformTypeFreeBSD
   };
 
   // possible values for target types
@@ -108,6 +109,7 @@ signals: (private)
   bool platformIsWindows() const { return m_platformType == platformTypeWindows; }
   bool platformIsMac() const { return m_platformType == platformTypeOsx; }
   bool platformIsLinux() const { return m_platformType == platformTypeLinux; }
+  bool platformIsFreeBSD() const { return m_platformType == platformTypeFreeBSD; }
 
   QTimer* m_mouseOutTimer;
   PlatformType m_platformType;
