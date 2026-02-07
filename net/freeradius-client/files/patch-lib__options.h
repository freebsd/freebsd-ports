--- lib/options.h.orig	2015-01-19 16:18:26 UTC
+++ lib/options.h
@@ -50,6 +50,7 @@ static OPTION config_options_default[] = {
 {"radius_retries",	OT_INT,	ST_UNDEF, NULL},
 {"radius_deadtime",	OT_INT, ST_UNDEF, NULL},
 {"bindaddr",		OT_STR, ST_UNDEF, NULL},
+{"nasaddr",		OT_STR, ST_UNDEF, NULL},
 /* local options */
 {"login_local",		OT_STR, ST_UNDEF, NULL},
 };
