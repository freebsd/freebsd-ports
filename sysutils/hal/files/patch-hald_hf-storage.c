--- hald/freebsd/hf-storage.c.orig	2008-05-07 19:23:57.000000000 -0400
+++ hald/freebsd/hf-storage.c	2009-02-23 16:39:09.000000000 -0500
@@ -30,6 +30,7 @@
 #include <limits.h>
 #include <inttypes.h>
 #include <string.h>
+#include <sys/param.h>
 #include <sys/types.h>
 #include <sys/disklabel.h>
 
@@ -38,6 +39,7 @@
 
 #include "hf-storage.h"
 #include "hf-block.h"
+#include "hf-devd.h"
 #include "hf-devtree.h"
 #include "hf-volume.h"
 #include "hf-util.h"
@@ -64,7 +66,7 @@ typedef struct
 static GNode *hf_storage_geom_tree = NULL;
 static GHashTable *hf_storage_geom_hash = NULL;
 
-static void hf_storage_init_geom (void);
+static void hf_storage_init_geom (gboolean force);
 static gboolean hf_storage_device_has_addon (HalDevice *device);
 
 static void
@@ -104,6 +106,8 @@ hf_storage_class_is_partitionable (const
 {
   return (! strcmp(geom_class, "MBR") ||
           ! strcmp(geom_class, "MBREXT") ||
+	  ! strcmp(geom_class, "PART") ||
+	  ! strcmp(geom_class, "JOURNAL") ||
 	  ! strcmp(geom_class, "GPT") ||
           ! strcmp(geom_class, "APPLE") || ! strcmp(geom_class, "SUN"));
 }
@@ -117,6 +121,7 @@ hf_storage_geom_has_partitions (const Ge
   if (g_node_n_children(node) > 0)
     return TRUE;
 
+  /*
   if (hf_storage_class_is_partitionable(geom_obj->class) &&
       g_node_next_sibling(node) != NULL)
     {
@@ -135,6 +140,7 @@ hf_storage_geom_has_partitions (const Ge
             return TRUE;
         }
     }
+    */
 
   return FALSE;
 }
@@ -146,6 +152,7 @@ hf_storage_geom_is_swap (const Geom_Obje
 
   return (! strcmp(geom_obj->class, "BSD") && geom_obj->type == FS_SWAP)
 	|| ((! strcmp(geom_obj->class, "MBR") ||
+	     ! strcmp(geom_obj->class, "PART") ||
              ! strcmp(geom_obj->class, "MBREXT"))
 	&& (geom_obj->type == 0x18		/* AST Windows swapfile */
 	    || geom_obj->type == 0x42		/* SFS or Linux swap */
@@ -294,7 +301,7 @@ hf_storage_device_probe (HalDevice *devi
 {
   g_return_if_fail(HAL_IS_DEVICE(device));
 
-  hf_storage_init_geom();
+  hf_storage_init_geom(TRUE);
 
   if (hf_runner_run_sync(device, 0, "hald-probe-storage",
 			 "HF_HAS_CHILDREN", HF_BOOL_TO_STRING(hf_storage_device_has_partitions(device)),
@@ -433,6 +440,29 @@ hf_storage_parse_conftxt (const char *co
               if (! strcmp (geom_obj->class, "GPT") ||
                   ! strcmp (geom_obj->class, "APPLE"))
                 geom_obj->str_type = g_strdup(fields[10]);
+	      else if (! strcmp (geom_obj->class, "PART"))
+                {
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
@@ -540,16 +570,34 @@ hf_storage_device_rescan_real (HalDevice
   hf_storage_device_probe(device, TRUE);
 }
 
+#if __FreeBSD_version < 700110
 static gboolean
 hf_storage_conftxt_timeout_cb (gpointer data)
 {
+  if (hf_is_waiting)
+    return TRUE;
+
+  hf_storage_devd_notify("DEVFS", "CDEV", "CREATE", NULL);
+
+  return TRUE;
+}
+#endif
+
+static gboolean
+hf_storage_devd_notify (const char *system,
+		        const char *subsystem,
+			const char *type,
+			const char *data)
+{
   static GSList *disks = NULL;
   static gboolean first = TRUE;
+  gboolean handled = FALSE;
   char *conftxt;
   GSList *new_disks;
 
-  if (hf_is_waiting)
-    return TRUE;
+  if (strcmp(system, "DEVFS") || strcmp(subsystem, "CDEV") ||
+      (strcmp(type, "CREATE") && strcmp(type, "DESTROY")))
+    return FALSE;
 
   conftxt = hf_get_string_sysctl(NULL, "kern.geom.conftxt");
   new_disks = hf_storage_parse_conftxt(conftxt);
@@ -572,6 +620,7 @@ hf_storage_conftxt_timeout_cb (gpointer 
 	  if (! hf_storage_find_disk(disks, disk->name))
 	    {
 	      osspec_probe();	/* catch new disk(s) */
+	      handled = TRUE;
 	      break;
 	    }
 	}
@@ -593,7 +642,10 @@ hf_storage_conftxt_timeout_cb (gpointer 
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
@@ -601,7 +653,10 @@ hf_storage_conftxt_timeout_cb (gpointer 
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
@@ -610,17 +665,17 @@ hf_storage_conftxt_timeout_cb (gpointer 
   g_slist_free(disks);
   disks = new_disks;
 
-  return TRUE;
+  return handled;
 }
 
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
@@ -636,8 +691,10 @@ hf_storage_init_geom (void)
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
@@ -720,8 +777,6 @@ hf_storage_device_add (HalDevice *device
 {
   g_return_if_fail(HAL_IS_DEVICE(device));
 
-  hf_storage_init_geom();
-
   if (hf_device_preprobe(device))
     {
       hf_storage_device_probe(device, FALSE);
@@ -739,7 +794,7 @@ hf_storage_get_geoms (const char *devnam
 
   g_return_val_if_fail(devname != NULL, NULL);
 
-  hf_storage_init_geom();
+  hf_storage_init_geom(FALSE);
 
   hash = g_str_hash(devname);
   node = g_node_find(hf_storage_geom_tree, G_PRE_ORDER, G_TRAVERSE_ALL,
@@ -802,3 +857,7 @@ HFHandler hf_storage_handler = {
   .probe =		hf_storage_probe,
   .device_rescan =	hf_storage_device_rescan
 };
+
+HFDevdHandler hf_storage_devd_handler = {
+  .notify =	hf_storage_devd_notify
+};
