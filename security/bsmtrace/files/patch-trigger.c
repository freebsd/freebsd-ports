--- trigger.c.orig	2014-01-14 22:51:19 UTC
+++ trigger.c
@@ -135,7 +135,7 @@ bsm_run_trigger(struct bsm_record_data *
 			if (args == NULL)
 				bsmtrace_error(1, "%s: calloc failed",
 				    __func__);
-			dprintf("executing trigger: '%s'\n", cmd);
+			d_printf("executing trigger: '%s'\n", cmd);
 			while ((ptr = strsep(&cmd, " ")) != NULL) {
 				if (*ptr == '\0')
 					continue;
