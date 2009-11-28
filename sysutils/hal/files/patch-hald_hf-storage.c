--- hald/freebsd/hf-storage.c.orig	2009-05-12 08:24:28.000000000 -0400
+++ hald/freebsd/hf-storage.c	2009-10-24 02:30:22.000000000 -0400
@@ -30,6 +30,8 @@
 #include <limits.h>
 #include <inttypes.h>
 #include <string.h>
+#include <unistd.h>
+#include <sys/param.h>
 #include <sys/types.h>
 #include <sys/disklabel.h>
 
@@ -38,6 +40,7 @@
 
 #include "hf-storage.h"
 #include "hf-block.h"
+#include "hf-devd.h"
 #include "hf-devtree.h"
 #include "hf-volume.h"
 #include "hf-util.h"
@@ -64,7 +67,7 @@ typedef struct
 static GNode *hf_storage_geom_tree = NULL;
 static GHashTable *hf_storage_geom_hash = NULL;
 
-static void hf_storage_init_geom (void);
+static void hf_storage_init_geom (gboolean force);
 static gboolean hf_storage_device_has_addon (HalDevice *device);
 
 static void
@@ -104,6 +107,8 @@ hf_storage_class_is_partitionable (const
 {
   return (! strcmp(geom_class, "MBR") ||
           ! strcmp(geom_class, "MBREXT") ||
+	  ! strcmp(geom_class, "PART") ||
+	  ! strcmp(geom_class, "JOURNAL") ||
 	  ! strcmp(geom_class, "GPT") ||
           ! strcmp(geom_class, "APPLE") || ! strcmp(geom_class, "SUN"));
 }
@@ -117,6 +122,7 @@ hf_storage_geom_has_partitions (const Ge
   if (g_node_n_children(node) > 0)
     return TRUE;
 
+  /*
   if (hf_storage_class_is_partitionable(geom_obj->class) &&
       g_node_next_sibling(node) != NULL)
     {
@@ -135,6 +141,7 @@ hf_storage_geom_has_partitions (const Ge
             return TRUE;
         }
     }
+    */
 
   return FALSE;
 }
@@ -294,7 +301,7 @@ hf_storage_device_probe (HalDevice *devi
 {
   g_return_if_fail(HAL_IS_DEVICE(device));
 
-  hf_storage_init_geom();
+  hf_storage_init_geom(TRUE);
 
   if (hf_runner_run_sync(device, 0, "hald-probe-storage",
 			 "HF_HAS_CHILDREN", HF_BOOL_TO_STRING(hf_storage_device_has_partitions(device)),
@@ -403,13 +410,49 @@ hf_storage_parse_conftxt (const char *co
           continue;
 	}
 
+      depth = atoi(fields[0]);
+      hash = g_str_hash(fields[2]);
+      if (g_hash_table_lookup(table, GUINT_TO_POINTER(hash)) != NULL)
+        {
+          g_strfreev(fields);
+	  curr_depth = depth;
+	  continue;
+	}
+
+      /* XXX This is a hack, but we need to ignore dynamic labels like
+       * ufsids which are created and destroyed based on whether or not
+       * the actual device is mounted or not.  If we don't then strange
+       * things happen in applications like nautilus.
+       */
+      if ((! strcmp(fields[1], "LABEL") ||
+          ! strcmp(fields[1], "BSD")) &&
+          ! strncmp(fields[2], "ufsid/", strlen("ufsid/")))
+        {
+          g_strfreev(fields);
+	  continue;
+	}
+
       geom_obj = g_new0(Geom_Object, 1);
 
-      depth = atoi(fields[0]);
       geom_obj->class = g_strdup(fields[1]);
       geom_obj->dev = g_strdup(fields[2]);
+      /* Allow for spaces in label names. */
+      if (! strcmp(fields[1], "LABEL"))
+        {
+          int j;
+
+	  for (j = 3; g_strv_length(fields) > (j + 2) &&
+               strcmp(fields[j + 2], "i"); j++)
+            {
+              char *tmp;
+
+	      tmp = g_strdup_printf("%s %s", geom_obj->dev, fields[j]);
+	      g_free(geom_obj->dev);
+	      geom_obj->dev = tmp;
+	    }
+	}
+
       geom_obj->type = -1;	/* We use -1 here to denote a missing type. */
-      hash = g_str_hash(geom_obj->dev);
       geom_obj->hash = hash;
 
       if (g_strv_length(fields) >= 5)
@@ -433,6 +476,30 @@ hf_storage_parse_conftxt (const char *co
               if (! strcmp (geom_obj->class, "GPT") ||
                   ! strcmp (geom_obj->class, "APPLE"))
                 geom_obj->str_type = g_strdup(fields[10]);
+	      else if (! strcmp (geom_obj->class, "PART"))
+                {
+		  geom_obj->str_type = g_strdup(fields[10]);
+                  if (g_strv_length(fields) >= 15)
+                    {
+                      if (! strcmp(fields[13], "xt"))
+                        {
+                          geom_obj->type = atoi(fields[14]);
+			  if (! strcmp(fields[11], "xs"))
+                            {
+                              g_free(geom_obj->class);
+			      geom_obj->class = g_strdup(fields[12]);
+			    }
+			}
+		    }
+		}
+	      else if (fields[10][0] == '!')
+                {
+                  char *nottype;
+
+		  nottype = fields[10];
+		  nottype++;
+                  geom_obj->type = atoi(nottype);
+		}
 	      else
                 geom_obj->type = atoi(fields[10]);
 	    }
@@ -541,17 +608,27 @@ hf_storage_device_rescan_real (HalDevice
 }
 
 static gboolean
-hf_storage_conftxt_timeout_cb (gpointer data)
+hf_storage_devd_notify (const char *system,
+		        const char *subsystem,
+			const char *type,
+			const char *data)
 {
   static GSList *disks = NULL;
   static gboolean first = TRUE;
+  gboolean handled = FALSE;
   char *conftxt;
   GSList *new_disks;
 
-  if (hf_is_waiting)
-    return TRUE;
+  if (! data || strcmp(system, "DEVFS") || strcmp(subsystem, "CDEV") ||
+      (strcmp(type, "CREATE") && strcmp(type, "DESTROY")))
+    return FALSE;
+
+  if (! strcmp(type, "DESTROY"))
+    g_usleep(G_USEC_PER_SEC/2);
 
   conftxt = hf_get_string_sysctl(NULL, "kern.geom.conftxt");
+  if (! conftxt)
+    return FALSE;
   new_disks = hf_storage_parse_conftxt(conftxt);
   g_free(conftxt);
 
@@ -572,6 +649,7 @@ hf_storage_conftxt_timeout_cb (gpointer 
 	  if (! hf_storage_find_disk(disks, disk->name))
 	    {
 	      osspec_probe();	/* catch new disk(s) */
+	      handled = TRUE;
 	      break;
 	    }
 	}
@@ -593,7 +671,10 @@ hf_storage_conftxt_timeout_cb (gpointer 
 		  device = hf_devtree_find_from_name(hald_get_gdl(), disk->name);
 		  if (device && hal_device_has_capability(device, "storage") &&
 		      ! hf_storage_device_has_addon(device))
-		    hf_storage_device_rescan_real(device);
+		    {
+		      hf_storage_device_rescan_real(device);
+		      handled = TRUE;
+		    }
 		}
 	    }
 	  else
@@ -601,7 +682,10 @@ hf_storage_conftxt_timeout_cb (gpointer 
 	      /* disk removed */
 	      device = hf_devtree_find_from_name(hald_get_gdl(), disk->name);
 	      if (device && hal_device_has_capability(device, "storage"))
-	        hf_device_remove_tree(device);
+		{
+	          hf_device_remove_tree(device);
+		  handled = TRUE;
+		}
 	    }
 	}
     }
@@ -610,17 +694,30 @@ hf_storage_conftxt_timeout_cb (gpointer 
   g_slist_free(disks);
   disks = new_disks;
 
+  return handled;
+}
+
+#if __FreeBSD_version < 700110
+static gboolean
+hf_storage_conftxt_timeout_cb (gpointer data)
+{
+  if (hf_is_waiting)
+    return TRUE;
+
+  hf_storage_devd_notify("DEVFS", "CDEV", "CREATE", "");
+
   return TRUE;
 }
+#endif
 
 static void
-hf_storage_init_geom (void)
+hf_storage_init_geom (gboolean force)
 {
   char *conftxt;
   static gboolean inited = FALSE;
   GSList *disks;
 
-  if (inited)
+  if (inited && ! force)
     return;
 
   conftxt = hf_get_string_sysctl(NULL, "kern.geom.conftxt");
@@ -636,8 +733,10 @@ hf_storage_init_geom (void)
 static void
 hf_storage_init (void)
 {
-  hf_storage_init_geom();
+  hf_storage_init_geom(FALSE);
+#if __FreeBSD_version < 700110
   g_timeout_add(3000, hf_storage_conftxt_timeout_cb, NULL);
+#endif
 }
 
 void
@@ -719,8 +818,6 @@ hf_storage_device_add (HalDevice *device
 {
   g_return_if_fail(HAL_IS_DEVICE(device));
 
-  hf_storage_init_geom();
-
   if (hf_device_preprobe(device))
     {
       hf_storage_device_probe(device, FALSE);
@@ -738,7 +835,7 @@ hf_storage_get_geoms (const char *devnam
 
   g_return_val_if_fail(devname != NULL, NULL);
 
-  hf_storage_init_geom();
+  hf_storage_init_geom(FALSE);
 
   hash = g_str_hash(devname);
   node = g_node_find(hf_storage_geom_tree, G_PRE_ORDER, G_TRAVERSE_ALL,
@@ -801,3 +898,7 @@ HFHandler hf_storage_handler = {
   .probe =		hf_storage_probe,
   .device_rescan =	hf_storage_device_rescan
 };
+
+HFDevdHandler hf_storage_devd_handler = {
+  .notify =	hf_storage_devd_notify
+};
