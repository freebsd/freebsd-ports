--- udisks/udisksclient.c.orig	2019-07-22 16:24:44 UTC
+++ udisks/udisksclient.c
@@ -19,6 +19,7 @@
  */
 
 #include "config.h"
+#include <glib.h>
 #include <glib/gi18n-lib.h>
 
 #include "udisksclient.h"
@@ -26,11 +27,6 @@
 #include "udisks-generated.h"
 #include "udisksobjectinfo.h"
 
-/* For __GNUC_PREREQ usage below */
-#ifdef __GNUC__
-# include <features.h>
-#endif
-
 /**
  * SECTION:udisksclient
  * @title: UDisksClient
@@ -1983,8 +1979,8 @@ udisks_client_get_id_for_display (UDisksClient *client
                    (g_strcmp0 (id_type[n].version, "*") == 0 && strlen (version) > 0))
             {
               /* we know better than the compiler here */
-#if defined( __GNUC_PREREQ) || defined(__clang__)
-# if __GNUC_PREREQ(4,6) || __clang__
+#if defined(__GNUC__) || defined(__clang__)
+# if G_GNUC_CHECK_VERSION(4, 6) || __clang__
 #  pragma GCC diagnostic push
 #  pragma GCC diagnostic ignored "-Wformat-nonliteral"
 # endif
@@ -1994,8 +1990,8 @@ udisks_client_get_id_for_display (UDisksClient *client
               else
                 ret = g_strdup_printf (g_dpgettext2 (GETTEXT_PACKAGE, "fs-type", id_type[n].short_name), version);
               goto out;
-#if defined( __GNUC_PREREQ) || defined(__clang__)
-# if __GNUC_PREREQ(4,6) || __clang__
+#if defined(__GNUC__) || defined(__clang__)
+# if G_GNUC_CHECK_VERSION(4, 6) || __clang__
 #  pragma GCC diagnostic pop
 # endif
 #endif
