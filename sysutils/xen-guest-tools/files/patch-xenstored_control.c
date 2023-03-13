--- tools/xenstore/xenstored_control.c.orig	2022-04-12 12:21:23 UTC
+++ tools/xenstore/xenstored_control.c
@@ -537,7 +537,7 @@ static const char *lu_reject_reason(const void *ctx)
 			ret = talloc_asprintf(ctx, "%s\nDomain %u: %ld s",
 					      ret ? : "Domains with long running transactions:",
 					      conn->id,
-					      now - conn->ta_start_time);
+					      (long)(now - conn->ta_start_time));
 		}
 	}
 
