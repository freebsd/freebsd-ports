--- ./xbmc/linux/LinuxTimezone.cpp.orig	2011-12-23 04:12:21.000000000 +0100
+++ ./xbmc/linux/LinuxTimezone.cpp	2012-01-02 10:14:38.000000000 +0100
@@ -27,6 +27,9 @@
 #ifdef __APPLE__
 #include "OSXGNUReplacements.h"
 #endif
+#ifdef __FreeBSD__
+#include "FreeBSDGNUReplacements.h"
+#endif
 
 #include "Util.h"
 
@@ -36,6 +39,7 @@
 {
    char* line = NULL;
    size_t linelen = 0;
+   int nameonfourthfield = 0;
    CStdString s;
    vector<CStdString> tokens;
 
@@ -91,6 +95,11 @@
 
    // Load countries
    fp = fopen("/usr/share/zoneinfo/iso3166.tab", "r");
+   if (!fp)
+   {
+      fp = fopen("/usr/share/misc/iso3166", "r");
+      nameonfourthfield = 1;
+   }
    if (fp)
    {
       CStdString countryCode;
@@ -111,6 +120,16 @@
          int i = 2;
          while (s[i] == ' ' || s[i] == '\t') i++;
 
+         if (nameonfourthfield)
+         {
+            // skip three letter
+            while (s[i] != ' ' && s[i] != '\t') i++;
+            while (s[i] == ' ' || s[i] == '\t') i++;
+            // skip number
+            while (s[i] != ' ' && s[i] != '\t') i++;
+            while (s[i] == ' ' || s[i] == '\t') i++;
+         }
+
          countryCode = s.Left(2);
          countryName = s.Mid(i);
 
