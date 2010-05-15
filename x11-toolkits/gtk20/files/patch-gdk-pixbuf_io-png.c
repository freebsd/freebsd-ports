--- gdk-pixbuf/io-png.c.orig	2010-05-02 05:14:27.000000000 +0200
+++ gdk-pixbuf/io-png.c	2010-05-15 17:30:35.000000000 +0200
@@ -261,7 +261,11 @@ gdk_pixbuf__png_image_load (FILE *f, GEr
         gchar *icc_profile_base64;
         const gchar *icc_profile_title;
         const gchar *icc_profile;
+#if defined(INT_MAX) && (INT_MAX > 0x7ffffffeL)
+        guint icc_profile_size;
+#else
         gulong icc_profile_size;
+#endif
         guint32 retval;
         gint compression_type;
 
@@ -607,7 +611,11 @@ png_info_callback   (png_structp png_rea
         gchar *icc_profile_base64;
         const gchar *icc_profile_title;
         const gchar *icc_profile;
+#if defined(INT_MAX) && (INT_MAX > 0x7ffffffeL)
+        guint icc_profile_size;
+#else
         gulong icc_profile_size;
+#endif
         guint32 retval;
         gint compression_type;
 
