Index: patch-hald_hf-storage.c
===================================================================
--- patch-hald_hf-storage.c	(revision 351262)
+++ patch-hald_hf-storage.c	(working copy)
@@ -1,5 +1,5 @@
---- ./hald/freebsd/hf-storage.c.orig	2009-08-24 14:42:29.000000000 +0200
-+++ ./hald/freebsd/hf-storage.c	2013-06-10 16:22:36.080280935 +0200
+--- hald/freebsd/hf-storage.c.orig	2009-08-24 12:42:29.000000000 +0000
++++ hald/freebsd/hf-storage.c	2014-04-16 19:04:08.004114131 +0000
 @@ -30,6 +30,7 @@
  #include <limits.h>
  #include <inttypes.h>
@@ -8,7 +8,7 @@
  #include <sys/param.h>
  #include <sys/types.h>
  #include <sys/disklabel.h>
-@@ -174,6 +175,10 @@ hf_storage_device_probe_geom (HalDevice 
+@@ -174,6 +175,10 @@
    if (! geom_obj)
      return;
  
@@ -19,7 +19,7 @@
    node = g_node_find(hf_storage_geom_tree, G_PRE_ORDER, G_TRAVERSE_ALL,
                       GUINT_TO_POINTER(geom_obj->hash));
  
-@@ -418,10 +423,41 @@ hf_storage_parse_conftxt (const char *co
+@@ -418,10 +423,42 @@
  	  continue;
  	}
  
@@ -32,7 +32,8 @@
 +          ! strcmp(fields[1], "BSD") ||
 +	  ! strcmp(fields[1], "PART")) &&
 +          (! strncmp(fields[2], "ufsid/", strlen("ufsid/")) ||
-+	   !  strncmp(fields[2], "ufs/", strlen("ufs/"))))
++	   !  strncmp(fields[2], "ufs/", strlen("ufs/")) ||
++	   !  strncmp(fields[2], "diskid/", strlen("diskid/"))))
 +        {
 +          g_strfreev(fields);
 +	  continue;
@@ -61,7 +62,7 @@
        geom_obj->type = -1;	/* We use -1 here to denote a missing type. */
        geom_obj->hash = hash;
  
-@@ -458,6 +494,13 @@ hf_storage_parse_conftxt (const char *co
+@@ -458,6 +495,13 @@
                              {
                                g_free(geom_obj->class);
  			      geom_obj->class = g_strdup(fields[12]);
@@ -75,7 +76,7 @@
  			    }
  			}
  		    }
-@@ -589,11 +632,18 @@ hf_storage_devd_notify (const char *syst
+@@ -589,11 +633,18 @@
    char *conftxt;
    GSList *new_disks;
  
@@ -95,7 +96,7 @@
    new_disks = hf_storage_parse_conftxt(conftxt);
    g_free(conftxt);
  
-@@ -669,7 +719,7 @@ hf_storage_conftxt_timeout_cb (gpointer 
+@@ -669,7 +720,7 @@
    if (hf_is_waiting)
      return TRUE;
  
