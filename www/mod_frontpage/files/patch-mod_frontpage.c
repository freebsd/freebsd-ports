--- mod_frontpage.c	Tue Feb  5 13:56:31 2002
+++ mod_frontpage.c	Tue Feb  5 18:01:27 2002
@@ -491,10 +491,6 @@
 		return log_scripterror (r, c, FORBIDDEN, APLOG_ERR|APLOG_NOERRNO,
 		    "fpEXEC stub writable by group or others");
 	}
-	if (!(r->finfo.st_mode & S_IXOTH)) {
-		return log_scripterror (r, c, FORBIDDEN, APLOG_ERR|APLOG_NOERRNO,
-		    "fpEXEC stub not executable by others");
-	}
 	if (((r->finfo.st_mode & S_ISGID))
 	&&  (r->finfo.st_gid != 0)) {
 		return log_scripterror (r, c, FORBIDDEN, APLOG_ERR|APLOG_NOERRNO,
