--- src/bsdapm.cc.orig	2018-12-16 17:16:51 UTC
+++ src/bsdapm.cc
@@ -61,7 +61,7 @@ static int apm_getinfo(int fd, apm_info_t aip) {
   return 0;
 }
 
-void print_apm_adapter(struct text_object *obj, char *p, int p_max_size) {
+void print_apm_adapter(struct text_object *obj, char *p, unsigned int p_max_size) {
   int fd;
   const char *out;
 #ifdef __OpenBSD__
@@ -109,7 +109,7 @@ void print_apm_adapter(struct text_object *obj, char *
   snprintf(p, p_max_size, "%s", out);
 }
 
-void print_apm_battery_life(struct text_object *obj, char *p, int p_max_size) {
+void print_apm_battery_life(struct text_object *obj, char *p, unsigned int p_max_size) {
   int fd;
   u_int batt_life;
   const char *out;
@@ -150,7 +150,7 @@ void print_apm_battery_life(struct text_object *obj, c
   snprintf(p, p_max_size, "%s", out);
 }
 
-void print_apm_battery_time(struct text_object *obj, char *p, int p_max_size) {
+void print_apm_battery_time(struct text_object *obj, char *p, unsigned int p_max_size) {
   int fd;
   int batt_time;
 #ifdef __OpenBSD__
