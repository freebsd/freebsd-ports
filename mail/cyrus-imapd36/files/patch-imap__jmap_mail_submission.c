--- imap/jmap_mail_submission.c.orig	2022-03-06 23:01:23 UTC
+++ imap/jmap_mail_submission.c
@@ -223,7 +223,7 @@ static int _emailsubmission_address_parse(json_t *addr
 
             if (!strcasecmp(key, "HOLDFOR")) {
                 char *endptr = (char *) val;
-                ulong interval = val ? strtoul(val, &endptr, 10) : ULONG_MAX;
+                unsigned long interval = val ? strtoul(val, &endptr, 10) : ULONG_MAX;
                 time_t now = time(0);
 
                 if (endptr == val || *endptr != '\0' ||
