--- torsmo.c.orig	Wed Oct 13 17:31:57 2004
+++ torsmo.c	Wed Oct 13 17:35:45 2004
@@ -376,7 +376,7 @@
       snprintf(buf, 255, "%.1fM", m);
   }
   else if (a >= 1024)
-    snprintf(buf, 255, "%Ldk", a/1024L);
+    snprintf(buf, 255, "%Ldk", a/1024);
   else
     snprintf(buf, 255, "%Ld", a);
 }
@@ -998,7 +998,7 @@
     }
     OBJ(acpitemp) {
       /* does anyone have decimals in acpi temperature? */
-      snprintf(p, n, "%d", (int) get_acpi_temperature(obj->data.i));
+      snprintf(p, n, "%0.1f", (float)get_acpi_temperature(obj->data.i));
     }
     OBJ(acpifan) {
       snprintf(p, n, "%s", get_acpi_fan());
@@ -2248,8 +2248,8 @@
 
   /* handle other command line arguments */
 
-  optind = 0;
-
+  optind = optreset = 1;
+  
   while (1) {
     int c = getopt(argc, argv, getopt_string);
     if(c == -1) break;
@@ -2353,8 +2353,7 @@
 
     default:
       fprintf(stderr, "torsmo: forked to background, pid is %d\n", ret);
-      exit(0);
-      break;
+      return 0;
     }
   }
 
