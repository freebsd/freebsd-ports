No udisks2 on OpenBSD (XXX add HAVE_UDISKS2 to meson_options.txt)

XXX implement minimal support for get_os_name() on OpenBSD;
we should port cc_os_release_get_values

Index: panels/info-overview/cc-info-overview-panel.c
--- panels/info-overview/cc-info-overview-panel.c.orig
+++ panels/info-overview/cc-info-overview-panel.c
@@ -37,10 +37,16 @@
 #include <glibtop/mountlist.h>
 #include <glibtop/mem.h>
 #include <glibtop/sysinfo.h>
+#ifdef HAVE_UDISKS2
 #include <udisks/udisks.h>
+#endif
 
 #include <gdk/gdk.h>
 
+#ifdef __OpenBSD__
+#include <sys/utsname.h>
+#endif
+
 #ifdef GDK_WINDOWING_WAYLAND
 #include <gdk/gdkwayland.h>
 #endif
@@ -417,6 +423,7 @@ get_graphics_hardware_string (void)
 static char *
 get_os_name (void)
 {
+#ifndef __OpenBSD__
   g_autofree gchar *name = NULL;
   g_autofree gchar *version_id = NULL;
   g_autofree gchar *pretty_name = NULL;
@@ -450,6 +457,18 @@ get_os_name (void)
     }
 
   return result;
+#else
+  gchar *result = NULL;
+  g_autofree gchar *name_version = NULL;
+  struct utsname u;
+
+  if (uname (&u) == -1)
+    return g_strdup (_("Unknown"));
+
+  name_version = g_strdup_printf ("%s %s %s", u.sysname, u.release, u.version);
+  result = g_strdup (name_version);
+  return result;
+#endif
 }
 
 static char *
@@ -466,6 +485,7 @@ get_os_type (void)
 static void
 get_primary_disc_info (CcInfoOverviewPanel *self)
 {
+#ifdef HAVE_UDISKS2
   g_autoptr(UDisksClient) client = NULL;
   GDBusObjectManager *manager;
   g_autolist(GDBusObject) objects = NULL;
@@ -512,6 +532,9 @@ get_primary_disc_info (CcInfoOverviewPanel *self)
     {
       cc_list_row_set_secondary_label (self->disk_row,  _("Unknown"));
     }
+#else
+  cc_list_row_set_secondary_label (self->disk_row,  _("Unknown"));
+#endif
 }
 
 static void
