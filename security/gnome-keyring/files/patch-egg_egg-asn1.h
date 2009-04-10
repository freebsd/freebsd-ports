--- egg/egg-asn1.h.orig	2009-02-25 16:40:49.000000000 -0500
+++ egg/egg-asn1.h	2009-02-25 16:41:21.000000000 -0500
@@ -75,9 +75,9 @@ gchar*             egg_asn1_read_dn     
 gchar*             egg_asn1_read_dn_part                  (ASN1_TYPE asn, const gchar *part, const gchar *match);
 
 
-glong              egg_asn1_time_parse_utc                (const gchar* value);
+time_t              egg_asn1_time_parse_utc                (const gchar* value);
 
-glong              egg_asn1_time_parse_general            (const gchar* value);
+time_t              egg_asn1_time_parse_general            (const gchar* value);
 
 
 typedef void       (*EggAsn1DnCallback)                   (guint index, GQuark oid, const guchar *value,
