--- xymonnet/httpresult.c.orig	2015-11-24 15:59:24 UTC
+++ xymonnet/httpresult.c
@@ -44,6 +44,7 @@ static int statuscolor(testedhost_t *h, 
 
 	switch(status) {
 	  case 200: /* OK - most common case */
+	  case 301: /* Permanent Redirect */
 	  case 302: /* Temp Redirect */
 	  case 303: /* See Other */
 	  case 307: /* Temp Redirect (HTTP 1.1) */
