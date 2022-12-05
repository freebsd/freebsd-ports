--- wmclockmon-config/tools.c.orig	2022-12-03 20:34:55 UTC
+++ wmclockmon-config/tools.c
@@ -17,6 +17,21 @@
 #include <sys/types.h>
 #include "configfile.h"
 
+int    backlight;
+int    switch_authorized;
+int    h12;
+int    time_mode;
+int    use_leds;
+int    use_locale;
+int    showcal;
+int    calalrms;
+char  *style_name;
+char  *style_dir;
+char  *config_file;
+char  *light_color;
+char  *command;
+char  *msgcmd;
+Alarm *alarms;
 
 int fexist(const char *filename) {
     FILE *file;
