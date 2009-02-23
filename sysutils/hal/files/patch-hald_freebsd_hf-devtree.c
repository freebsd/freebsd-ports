--- hald/freebsd/hf-devtree.c.orig	2008-05-07 19:24:03.000000000 -0400
+++ hald/freebsd/hf-devtree.c	2009-02-16 18:48:41.000000000 -0500
@@ -86,7 +86,11 @@ hf_devtree_cpu_can_throttle (int cpu)
   gboolean can = FALSE;
   char *levels;
 
+#ifdef notyet
   levels = hf_get_string_sysctl(NULL, "dev.cpu.%i.freq_levels", cpu);
+#else
+  levels = hf_get_string_sysctl(NULL, "dev.cpu.0.freq_levels");
+#endif
   if (levels)
     {
       char **toks;
@@ -109,7 +113,11 @@ hf_devtree_cpu_get_maxfreq (int cpu)
   char *levels;
   int freq = -1;
 
+#ifdef notyet
   levels = hf_get_string_sysctl(NULL, "dev.cpu.%i.freq_levels", cpu);
+#else
+  levels = hf_get_string_sysctl(NULL, "dev.cpu.0.freq_levels");
+#endif
   if (levels)
     {
       sscanf(levels, "%i/", &freq);
@@ -379,7 +387,8 @@ static Handler handlers[] = {
   { "pcm",		NULL					},
   { "psm",		hf_devtree_psm_set_properties		},
   { "sio",		NULL					},
-  { "speaker",		NULL					}
+  { "speaker",		NULL					},
+  { "usbus",		NULL					}
 };
 
 static void
@@ -426,7 +435,13 @@ hf_devtree_probe (void)
 	  HalDevice *device;
 
 	  device = hf_devtree_device_new(parent, info->handler, info->unit);
-	  hf_device_preprobe_and_add(device);
+	  if (hf_device_preprobe(device))
+            {
+              if (hal_device_has_capability(device, "input.mouse"))
+                hf_runner_run_sync(device, 0, "hald-probe-mouse", NULL);
+
+	      hf_device_add(device);
+	    }
 	}
 
       devices = g_slist_delete_link(devices, root);
@@ -434,6 +449,17 @@ hf_devtree_probe (void)
     }
 }
 
+static gboolean
+hf_devtree_rescan (HalDevice *device)
+{
+  if (hal_device_has_capability(device, "input.mouse"))
+    {
+      hf_runner_run_sync(device, 0, "hald-probe-mouse", NULL);
+      return TRUE;
+    }
+  return FALSE;
+}
+
 HalDevice *
 hf_devtree_find_from_name (HalDeviceStore *store, const char *name)
 {
@@ -597,5 +623,6 @@ hf_devtree_is_driver (const char *name, 
 }
 
 HFHandler hf_devtree_handler = {
-  .probe = hf_devtree_probe
+  .probe = hf_devtree_probe,
+  .device_rescan = hf_devtree_rescan
 };
