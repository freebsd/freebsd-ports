--- xbmc/utils/CPUInfo.cpp.orig	2016-04-24 UTC
+++ xbmc/utils/CPUInfo.cpp
@@ -584,6 +584,14 @@ bool CCPUInfo::getTemperature(CTemperatu
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
@@ -937,6 +945,9 @@ bool CCPUInfo::HasNeon()
 #elif defined(TARGET_DARWIN_IOS)
   has_neon = 1;
 
+#elif defined(__FreeBSD__) && defined(__ARM_NEON__)
+  has_neon = 1;
+
 #elif defined(TARGET_LINUX) && defined(__ARM_NEON__)
   if (has_neon == -1)
   {
