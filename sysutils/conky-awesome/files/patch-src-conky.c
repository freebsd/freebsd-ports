--- src/conky.c.orig	Sun Dec  3 21:22:49 2006
+++ src/conky.c	Sun Dec  3 21:23:15 2006
@@ -2046,7 +2046,6 @@
 		OBJ(acpitemp, 0) obj->data.i = open_acpi_temperature(arg);
 	END OBJ(acpitempf, 0) obj->data.i = open_acpi_temperature(arg);
 	END OBJ(acpiacadapter, 0)
-#if defined(__linux__)
 	    END OBJ(freq, 0)
 	    get_cpu_count();
 	if (!arg
@@ -2079,6 +2078,7 @@
 	    obj->data.cpu_index=atoi(&arg[0]);
 	}
 	obj->a = 1;
+#if defined(__linux__)
 	END OBJ(voltage_mv, 0)
 	    get_cpu_count();
 	if (!arg
