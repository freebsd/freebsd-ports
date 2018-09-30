--- imap/http_dav.h.orig	2018-04-10 19:29:50 UTC
+++ imap/http_dav.h
@@ -628,4 +628,7 @@ int proppatch_todb(xmlNodePtr prop, unsigned set, stru
 int proppatch_restype(xmlNodePtr prop, unsigned set, struct proppatch_ctx *pctx,
 		      struct propstat propstat[], void *rock);
 
+/* from upstream imap/ical_support.h need to put it somewhere ... */
+extern void icaltime_set_utc(struct icaltimetype *t, int set);
+
 #endif /* HTTP_DAV_H */
