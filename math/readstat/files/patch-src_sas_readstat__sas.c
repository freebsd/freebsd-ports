--- src/sas/readstat_sas.c.orig	2023-05-02 13:35:12 UTC
+++ src/sas/readstat_sas.c
@@ -120,7 +120,7 @@ static readstat_charset_entry_t _charset_table[] = { 
     { .code = 248,   .name = "SHIFT_JISX0213" },
 };
 
-static time_t sas_epoch() {
+static time_t sas_epoch(void) {
     return - 3653 * 86400; // seconds between 01-01-1960 and 01-01-1970
 }
 
