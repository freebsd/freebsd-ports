--- libatalk/adouble/ad_open.c.orig	2022-05-01 19:20:45 UTC
+++ libatalk/adouble/ad_open.c
@@ -1637,6 +1637,10 @@ void *ad_entry(const struct adouble *ad, int eid)
 	size_t len = ad_getentrylen(ad, eid);
 	bool valid;
 
+	if (bufsize == 0) {
+		bufsize = sizeof(ad->ad_data) - (off + len);
+	}
+
 	valid = ad_entry_check_size(eid, bufsize, off, len);
 	if (!valid) {
 		return NULL;
