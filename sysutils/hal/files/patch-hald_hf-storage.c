--- hald/freebsd/hf-storage.c.orig	2009-08-24 08:42:29.000000000 -0400
+++ hald/freebsd/hf-storage.c	2010-02-26 08:29:38.000000000 -0500
@@ -30,6 +30,7 @@
 #include <limits.h>
 #include <inttypes.h>
 #include <string.h>
+#include <unistd.h>
 #include <sys/param.h>
 #include <sys/types.h>
 #include <sys/disklabel.h>
@@ -418,10 +419,41 @@ hf_storage_parse_conftxt (const char *co
 	  continue;
 	}
 
+      /* XXX This is a hack, but we need to ignore dynamic labels like
+       * ufsids which are created and destroyed based on whether or not
+       * the actual device is mounted or not.  If we don't then strange
+       * things happen in applications like nautilus.
+       */
+      if ((! strcmp(fields[1], "LABEL") ||
+          ! strcmp(fields[1], "BSD") ||
+	  ! strcmp(fields[1], "PART")) &&
+          ! (strncmp(fields[2], "ufsid/", strlen("ufsid/")) ||
+	  !  strncmp(fields[2], "ufs/", strlen("ufs/"))))
+        {
+          g_strfreev(fields);
+	  continue;
+	}
+
       geom_obj = g_new0(Geom_Object, 1);
 
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
       geom_obj->hash = hash;
 
@@ -589,11 +621,16 @@ hf_storage_devd_notify (const char *syst
   char *conftxt;
   GSList *new_disks;
 
-  if (strcmp(system, "DEVFS") || strcmp(subsystem, "CDEV") ||
+  if (! data || strcmp(system, "DEVFS") || strcmp(subsystem, "CDEV") ||
       (strcmp(type, "CREATE") && strcmp(type, "DESTROY")))
     return FALSE;
 
+  if (! strcmp(type, "DESTROY"))
+    g_usleep(G_USEC_PER_SEC/2);
+
   conftxt = hf_get_string_sysctl(NULL, "kern.geom.conftxt");
+  if (! conftxt)
+    return FALSE;
   new_disks = hf_storage_parse_conftxt(conftxt);
   g_free(conftxt);
 
@@ -669,7 +706,7 @@ hf_storage_conftxt_timeout_cb (gpointer 
   if (hf_is_waiting)
     return TRUE;
 
-  hf_storage_devd_notify("DEVFS", "CDEV", "CREATE", NULL);
+  hf_storage_devd_notify("DEVFS", "CDEV", "CREATE", "");
 
   return TRUE;
 }
