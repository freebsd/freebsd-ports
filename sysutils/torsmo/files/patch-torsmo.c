--- torsmo.c.orig	Thu Aug  5 19:39:06 2004
+++ torsmo.c	Thu Aug  5 19:39:20 2004
@@ -998,7 +998,7 @@
     }
     OBJ(acpitemp) {
       /* does anyone have decimals in acpi temperature? */
-      snprintf(p, n, "%d", (int) get_acpi_temperature(obj->data.i));
+      snprintf(p, n, "%0.1f", (int) get_acpi_temperature(obj->data.i));
     }
     OBJ(acpifan) {
       snprintf(p, n, "%s", get_acpi_fan());
