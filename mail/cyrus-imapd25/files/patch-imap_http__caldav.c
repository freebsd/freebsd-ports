--- imap/http_caldav.c.orig	2018-04-08 22:00:44 UTC
+++ imap/http_caldav.c
@@ -2023,7 +2023,7 @@ static struct icaltimetype icaltime_from_rfc3339_strin
 	goto fail;
     }
 
-    tt.is_utc = 1;
+    icaltime_set_utc(&tt, 1);
     return tt;
 
   fail:
