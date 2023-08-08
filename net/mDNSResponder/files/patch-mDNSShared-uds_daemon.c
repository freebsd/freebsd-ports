--- mDNSShared/uds_daemon.c.orig	2023-01-24 00:43:17 UTC
+++ mDNSShared/uds_daemon.c
@@ -2913,7 +2913,7 @@ exit:
 mDNSlocal mStatus add_domain_to_browser(request_state *info, const domainname *d)
 {
     browser_t *b, *p;
-    __block mStatus err;
+    mStatus err;
 
     for (p = info->u.browser.browsers; p; p = p->next)
     {
