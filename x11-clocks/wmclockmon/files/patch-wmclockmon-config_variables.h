Fix -fno-common build failure.

Index: wmclockmon-config/variables.h
--- wmclockmon-config/variables.h.orig	2005-04-07 09:37:43 UTC
+++ wmclockmon-config/variables.h
@@ -7,20 +7,20 @@
 
 #include "defines.h"
 
-int    backlight;
-int    switch_authorized;
-int    h12;
-int    time_mode;
-int    use_leds;
-int    use_locale;
-int    showcal;
-int    calalrms;
-char  *style_name;
-char  *style_dir;
-char  *config_file;
-char  *light_color;
-char  *command;
-char  *msgcmd;
-Alarm *alarms;
+extern int    backlight;
+extern int    switch_authorized;
+extern int    h12;
+extern int    time_mode;
+extern int    use_leds;
+extern int    use_locale;
+extern int    showcal;
+extern int    calalrms;
+extern char  *style_name;
+extern char  *style_dir;
+extern char  *config_file;
+extern char  *light_color;
+extern char  *command;
+extern char  *msgcmd;
+extern Alarm *alarms;
 
 #endif
