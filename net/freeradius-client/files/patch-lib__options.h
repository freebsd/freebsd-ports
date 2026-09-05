--- lib/options.h.orig	2021-07-29 14:49:30 UTC
+++ lib/options.h
@@ -49,6 +49,7 @@ static OPTION config_options_default[] = {
 {"radius_retries",	OT_INT,	ST_UNDEF, NULL},
 {"radius_deadtime",	OT_INT, ST_UNDEF, NULL},
 {"bindaddr",		OT_STR, ST_UNDEF, NULL},
+{"nasaddr",		OT_STR, ST_UNDEF, NULL},
 /* local options */
 {"login_local",		OT_STR, ST_UNDEF, NULL},
 };
