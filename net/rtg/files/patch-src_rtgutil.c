--- src/rtgutil.c.orig	2018-04-02 23:03:54 UTC
+++ src/rtgutil.c
@@ -37,6 +37,7 @@ int read_rtg_config(char *file, config_t
               else if (!strcasecmp(p1, "DB_Database")) strncpy(set->dbdb, p2, sizeof(set->dbdb));
               else if (!strcasecmp(p1, "DB_User")) strncpy(set->dbuser, p2, sizeof(set->dbuser));
               else if (!strcasecmp(p1, "DB_Pass")) strncpy(set->dbpass, p2, sizeof(set->dbpass));
+              else if (!strcasecmp(p1, "Update_desc")) ; // no-op
 
 /* Long longs not ANSI C.  If OS doesn't support atoll() use default. */
               else if (!strcasecmp(p1, "OutOfRange")) 
