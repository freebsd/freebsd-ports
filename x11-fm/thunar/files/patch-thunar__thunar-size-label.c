--- ./thunar/thunar-size-label.c.orig	2012-10-14 13:01:38.000000000 +0000
+++ ./thunar/thunar-size-label.c	2012-10-21 00:27:16.000000000 +0000
@@ -259,6 +259,51 @@
   return FALSE;
 }
 
+#if GLIB_CHECK_VERSION (2, 28, 0)
+static gchar*
+tsl_format_size_string (guint64 size)
+{
+  GString *result;
+  gchar   *grouping;
+  gchar   *thousep;
+  gint     ndigits = 0;
+
+#ifdef HAVE_LOCALECONV
+  grouping = localeconv ()->grouping;
+  thousep = localeconv ()->thousands_sep;
+#else
+  grouping = "\3\0";
+  thousep = ",";
+#endif
+
+  result = g_string_sized_new (32);
+  do
+    {
+      /* prepend the next digit to the string */
+      g_string_prepend_c (result, '0' + (size % 10));
+      ++ndigits;
+      
+      /* check if we should add the thousands separator */
+      if (ndigits == *grouping && *grouping != CHAR_MAX && size > 9)
+        {
+          g_string_prepend (result, thousep);
+          ndigits = 0;
+
+          /* if *(grouping+1) == '\0' then we have to use the
+           * *grouping character (last grouping rule) for all
+           * following cases.
+           */
+          if (*(grouping + 1) != '\0')
+            ++grouping;
+        }
+
+      size /= 10;
+    }
+  while (size > 0);
+
+  return g_string_free (result, FALSE);
+}
+#endif
 
 
 static void
@@ -266,6 +311,10 @@
 {
   gchar   *size_string;
   guint64  size;
+#if GLIB_CHECK_VERSION (2, 28, 0)
+  gchar  *size_humanized;
+  gchar  *text;
+#endif
 
   _thunar_return_if_fail (THUNAR_IS_SIZE_LABEL (size_label));
   _thunar_return_if_fail (size_label->files != NULL);
@@ -308,7 +357,25 @@
       size = thunar_file_get_size (THUNAR_FILE (size_label->files->data));
 
       /* setup the new label */
+#if GLIB_CHECK_VERSION (2, 30, 0)
       size_string = g_format_size_full (size, G_FORMAT_SIZE_LONG_FORMAT);
+#else
+      /* determine the size in bytes */
+      text = tsl_format_size_string (size);
+      size_string = g_strdup_printf (_("%s Bytes"), text);
+      g_free (text);
+
+      /* check if the file is larger that 1kB */
+      if (G_LIKELY (size > 1024ul))
+        {
+          /* prepend the humanized size */
+          size_humanized = g_format_size_for_display (size);
+          text = g_strdup_printf ("%s (%s)", size_humanized, size_string);
+          g_free (size_humanized);
+          g_free (size_string);
+          size_string = text;
+        }
+#endif
       gtk_label_set_text (GTK_LABEL (size_label->label), size_string);
       g_free (size_string);
     }
