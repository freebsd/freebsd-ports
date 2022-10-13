--- src/freebsd.cc.orig	2022-10-12 18:18:08 UTC
+++ src/freebsd.cc
@@ -460,6 +460,27 @@ int get_battery_perct(const char *) {
   return batcapacity;
 }
 
+void get_battery_power_draw(char *buffer, unsigned int n, const char *bat) {
+  int rate = 0;
+  double ret = 0;
+
+  /*
+   * hw.acpi.battery.rate returns battery discharge rate in mW,
+   * or -1 (according to docs, but also 0 in practice) when not discharging.
+   *
+   * ref. acpi_battery(4)
+   */
+  if (GETSYSCTL("hw.acpi.battery.rate", rate)) {
+    fprintf(stderr, "Cannot read sysctl \"hw.acpi.battery.rate\"\n");
+  }
+
+  if (rate > 0) {
+    ret = (double)rate/(double)1000;
+  }
+
+  snprintf(buffer, n, "%.1f", ret);
+}
+
 double get_battery_perct_bar(struct text_object *obj) {
   int batperct = get_battery_perct(obj->data.s);
   return batperct;
