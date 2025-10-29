--- src/varlist.h.orig	2025-07-05 13:39:28 UTC
+++ src/varlist.h
@@ -154,7 +154,7 @@ varflag(VAR_ssl_verbose,"ssl_verbose",	TRUE,		NULL)
 varflag(VAR_ssl_continue,"ssl_continue",TRUE,		NULL)
 varint (VAR_ssl_depth,	"ssl_depth",	10,		NULL)
 varflag(VAR_ssl_verbose,"ssl_verbose",	TRUE,		NULL)
-varflag(VAR_ssl_insecure,"ssl_insecure",TRUE,       NULL)
+varflag(VAR_ssl_insecure,"ssl_insecure",FALSE,          NULL)
 varstr (VAR_stat_attr,	"status_attr",	NULL,		ch_status_attr)
 varstr (VAR_stat_fields,"status_fields",NULL,		ch_status_fields)
 varpos (VAR_stat_height,"status_height",1,		ch_status_height)
