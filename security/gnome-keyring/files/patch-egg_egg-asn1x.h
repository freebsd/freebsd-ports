--- egg/egg-asn1x.h.orig	2010-10-19 06:11:38.000000000 +0400
+++ egg/egg-asn1x.h	2013-11-04 08:27:50.000000000 +0400
@@ -25,6 +25,7 @@
 #define EGG_ASN1X_H_
 
 #include <glib.h>
+#include <libtasn1.h>
 
 #ifndef HAVE_EGG_ALLOCATOR
 typedef void* (*EggAllocator) (void* p, gsize);
@@ -33,15 +34,13 @@
 
 typedef gboolean (*EggAsn1xEncoder) (gpointer data, guchar *buf, gsize n_buf);
 
-struct static_struct_asn;
-
-GNode*              egg_asn1x_create                 (const struct static_struct_asn *defs,
+GNode*              egg_asn1x_create                 (const ASN1_ARRAY_TYPE *defs,
                                                       const gchar *type);
 
-GNode*              egg_asn1x_create_quark           (const struct static_struct_asn *defs,
+GNode*              egg_asn1x_create_quark           (const ASN1_ARRAY_TYPE *defs,
                                                       GQuark type);
 
-GNode*              egg_asn1x_create_and_decode      (const struct static_struct_asn *defs,
+GNode*              egg_asn1x_create_and_decode      (const ASN1_ARRAY_TYPE *defs,
                                                       const gchar *type,
                                                       gconstpointer data,
                                                       gsize n_data);
@@ -167,10 +166,10 @@
 
 void                egg_asn1x_destroy                (gpointer asn);
 
-glong               egg_asn1x_parse_time_general     (const gchar *time,
+time_t               egg_asn1x_parse_time_general     (const gchar *time,
                                                       gssize n_time);
 
-glong               egg_asn1x_parse_time_utc         (const gchar *time,
+time_t               egg_asn1x_parse_time_utc         (const gchar *time,
                                                       gssize n_time);
 
 gssize              egg_asn1x_element_length         (gconstpointer data,
