--- torsmo.c.orig	Wed Dec 22 01:14:46 2004
+++ torsmo.c	Wed Dec 22 21:49:27 2004
@@ -272,7 +272,7 @@
       snprintf(buf, 255, "%.1fM", m);
   }
   else if (a >= 1024)
-    snprintf(buf, 255, "%Ldk", a/1024L);
+    snprintf(buf, 255, "%Ldk", a/1024);
   else
     snprintf(buf, 255, "%Ld", a);
 }
@@ -883,7 +883,7 @@
     }
     OBJ(acpitemp) {
       /* does anyone have decimals in acpi temperature? */
-      snprintf(p, n, "%d", (int) get_acpi_temperature(obj->data.i));
+      snprintf(p, n, "%0.1f", (float)get_acpi_temperature(obj->data.i));
     }
     OBJ(freq) {
       snprintf(p, n, "%s", get_freq());
@@ -2223,8 +2223,8 @@
 
   /* handle other command line arguments */
 
-  optind = 0;
-
+	optind = optreset = 1;
+  
   while (1) {
     int c = getopt(argc, argv, getopt_string);
     if(c == -1) break;
@@ -2319,8 +2319,7 @@
 
     default:
       fprintf(stderr, "torsmo: forked to background, pid is %d\n", ret);
-      exit(0);
-      break;
+    	return 0;
     }
   }
 
