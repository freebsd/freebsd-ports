--- imap/jmap_mail_submission.c.orig	2023-03-01 02:54:30 UTC
+++ imap/jmap_mail_submission.c
@@ -229,7 +229,7 @@ static int _emailsubmission_address_parse(json_t *addr
             if (holduntil) {
                 if (!strcasecmp(key, "HOLDFOR")) {
                     char *endptr = (char *) val;
-                    ulong interval = val ? strtoul(val, &endptr, 10) : ULONG_MAX;
+                    unsigned long interval = val ? strtoul(val, &endptr, 10) : ULONG_MAX;
                     time_t now = time(0);
 
                     if (endptr == val || *endptr != '\0' ||
