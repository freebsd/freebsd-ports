
$FreeBSD$

--- modules/auth/common.c.orig
+++ modules/auth/common.c
@@ -95,5 +95,5 @@
 		}
 	}
 
-	return sl_reply(_m, (char*)(long)_code, _reason);
+	return (use_tm != 0) ? tmb.t_reply(_m, _code, _reason) : sl_reply(_m, (char*)(long)_code, _reason);
 }
