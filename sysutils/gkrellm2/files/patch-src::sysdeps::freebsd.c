Index: src/sysdeps/freebsd.c
diff -u src/sysdeps/freebsd.c.orig src/sysdeps/freebsd.c
--- src/sysdeps/freebsd.c.orig	Wed Oct  2 05:17:59 2002
+++ src/sysdeps/freebsd.c	Tue Dec 31 15:47:32 2002
@@ -1181,6 +1181,8 @@
 /* ===================================================================== */
 /* Sensor monitor interface */
 
+#if defined(__i386__)
+
 typedef struct
 	{
 	gchar	*name;
@@ -1206,11 +1208,12 @@
 	{ "-5V",	-1.667, 0, NULL }		/* in6 -(100/60)*@		*/
 	};
 
-#if defined(__i386__)
 #include <dirent.h>
 #include <osreldate.h>
 #include <machine/cpufunc.h>
-#if __FreeBSD_version >= 300000
+#if __FreeBSD_version >= 500042
+#include <dev/smbus/smb.h>
+#elif __FreeBSD_version >= 300000
 #include <machine/smb.h>
 #endif
 
@@ -1439,6 +1442,36 @@
 			}
 		}
 	return (found_sensors | found_acpi_sensors);
+	}
+
+#else
+
+gboolean
+gkrellm_sys_sensors_get_temperature(gchar *path, gint id,
+		gint iodev, gint interface, gfloat *temp)
+
+	{
+	return FALSE;
+	}
+
+gboolean
+gkrellm_sys_sensors_get_fan(gchar *path, gint id,
+		gint iodev, gint interface, gfloat *fan)
+	{
+	return FALSE;
+	}
+
+gboolean
+gkrellm_sys_sensors_get_voltage(gchar *path, gint id,
+		gint iodev, gint interface, gfloat *volt)
+	{
+	return FALSE;
+	}
+
+gboolean
+gkrellm_sys_sensors_init(void)
+	{
+	return FALSE;
 	}
 
 #endif
