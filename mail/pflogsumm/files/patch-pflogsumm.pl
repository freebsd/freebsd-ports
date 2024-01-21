--- pflogsumm.pl.orig	2024-01-21 13:07:50 UTC
+++ pflogsumm.pl
@@ -1536,7 +1536,7 @@ sub gimme_domain {
     # split domain/ipaddr into separates
     # newer versions of Postfix have them "dom.ain[i.p.add.ress]"
     # older versions of Postfix have them "dom.ain/i.p.add.ress"
-    unless((($domain, $ipAddr) = /^([^\[]+)\[((?:\d{1,3}\.){3}\d{1,3})\]/) == 2 ||
+    unless((($domain, $ipAddr) = /^([^\[]+)\[((?:\d{1,3}\.){3}\d{1,3}|[0-9a-f:]+)\]/o) == 2 ||
            (($domain, $ipAddr) = /^([^\/]+)\/([0-9a-f.:]+)/i) == 2) {
 	# more exhaustive method
         ($domain, $ipAddr) = /^([^\[\(\/]+)[\[\(\/]([^\]\)]+)[\]\)]?:?\s*$/;
