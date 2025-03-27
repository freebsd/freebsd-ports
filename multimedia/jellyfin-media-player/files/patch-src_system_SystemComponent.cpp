--- src/system/SystemComponent.cpp.orig	2025-03-26 21:47:29 UTC
+++ src/system/SystemComponent.cpp
@@ -33,6 +33,7 @@ QMap<SystemComponent::PlatformType, QString> g_platfor
   { SystemComponent::platformTypeWindows, "windows" },
   { SystemComponent::platformTypeLinux, "linux" },
   { SystemComponent::platformTypeOpenELEC, "openelec" },
+  { SystemComponent::platformTypeFreeBSD, "freebsd" },
   { SystemComponent::platformTypeUnknown, "unknown" },
 };
 
@@ -61,6 +62,8 @@ SystemComponent::SystemComponent(QObject* parent) : Co
   m_platformType = platformTypeOpenELEC;
 #elif defined(Q_OS_LINUX)
   m_platformType = platformTypeLinux;
+#elif defined(Q_OS_FREEBSD)
+  m_platformType = platformTypeFreeBSD;
 #endif
 
 // define target type
