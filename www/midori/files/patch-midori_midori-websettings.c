--- midori/midori-websettings.c.orig	2012-03-08 23:34:45.000000000 +0100
+++ midori/midori-websettings.c	2012-03-23 15:48:54.000000000 +0100
@@ -27,6 +27,11 @@
     #include <sys/utsname.h>
 #endif
 
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
+
 struct _MidoriWebSettings
 {
     WebKitWebSettings parent_instance;
@@ -347,16 +352,26 @@
 static gboolean
 midori_web_settings_low_memory_profile ()
 {
-    gchar* contents;
-    const gchar* total;
-    if (!g_file_get_contents ("/proc/meminfo", &contents, NULL, NULL))
-        return FALSE;
-    if (contents && (total = strstr (contents, "MemTotal:")) && *total)
-    {
-        const gchar* value = katze_skip_whitespace (total + 9);
-        gdouble mem_total = g_ascii_strtoll (value, NULL, 0);
-        return mem_total / 1024.0 < 352 + 1;
-    }
+    #ifdef __FreeBSD__
+        size_t size;
+        int mem_total;
+        size = sizeof mem_total;
+
+        sysctlbyname("hw.realmem", &mem_total, &size, NULL, 0);
+
+	return mem_total / 1048576 < 352;
+    #else
+    	gchar* contents;
+    	const gchar* total;
+    	if (!g_file_get_contents ("/proc/meminfo", &contents, NULL, NULL))
+        	return FALSE;
+    	if (contents && (total = strstr (contents, "MemTotal:")) && *total)
+    	{
+        	const gchar* value = katze_skip_whitespace (total + 9);
+        	gdouble mem_total = g_ascii_strtoll (value, NULL, 0);
+        	return mem_total / 1024.0 < 352 + 1;
+    	}
+    #endif
     return FALSE;
 }
