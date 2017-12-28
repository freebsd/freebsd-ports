--- xbmc/utils/CPUInfo.cpp.orig	2017-11-14 16:55:01 UTC
+++ xbmc/utils/CPUInfo.cpp
@@ -604,6 +604,14 @@ bool CCPUInfo::getTemperature(CTemperature& temperatur
 #if defined(TARGET_DARWIN_OSX)
   value = SMCGetTemperature(SMC_KEY_CPU_TEMP);
   scale = 'c';
+#elif defined(TARGET_RASPBERRY_PI)
+  size_t len;
+  len = sizeof(value);
+  if (sysctlbyname("dev.cpu.0.temperature", &value, &len, NULL, 0) != 0)
+     return false;
+  /* temperature is in kelvin * 10 */
+  value = (value - 2732) / 10;
+  scale = 'c';
 #else
   int         ret   = 0;
   FILE        *p    = NULL;
@@ -955,6 +963,9 @@ bool CCPUInfo::HasNeon()
     has_neon = (CAndroidFeatures::HasNeon()) ? 1 : 0;
 
 #elif defined(TARGET_DARWIN_IOS)
+  has_neon = 1;
+
+#elif defined(__FreeBSD__) && defined(__ARM_NEON__)
   has_neon = 1;
 
 #elif defined(TARGET_LINUX) && defined(__ARM_NEON__)
