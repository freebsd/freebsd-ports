--- torsmo.c.orig	Wed Dec 22 01:14:46 2004
+++ torsmo.c	Thu Apr  7 20:51:01 2005
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
@@ -1126,7 +1126,8 @@
       human_readable(cur->swapmax*1024, p);
     }
     OBJ(swapperc) {
-      snprintf(p, 255, "%*u", pad_percents, (cur->swap*100) / cur->swapmax);
+      snprintf(p, 255, "%*u", pad_percents, 
+		cur->swapmax ? (cur->swap*100) / cur->swapmax : 0);
     }
     OBJ(swapbar) {
       new_bar(p, obj->data.pair.a, obj->data.pair.b,
@@ -2223,8 +2224,8 @@
 
   /* handle other command line arguments */
 
-  optind = 0;
-
+	optind = optreset = 1;
+  
   while (1) {
     int c = getopt(argc, argv, getopt_string);
     if(c == -1) break;
@@ -2319,8 +2320,7 @@
 
     default:
       fprintf(stderr, "torsmo: forked to background, pid is %d\n", ret);
-      exit(0);
-      break;
+    	return 0;
     }
   }
 
