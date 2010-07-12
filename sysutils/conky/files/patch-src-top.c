--- src/top.c.orig
+++ src/top.c
@@ -880,16 +880,22 @@ int parse_top_args(const char *s, const char *arg, struct text_object *obj)
 #else /* IOSTATS */
 			NORM_ERR("must be one of: name, cpu, pid, mem, time, mem_res, mem_vsize");
 #endif /* IOSTATS */
+			free(td->s);
+			free(obj->data.opaque);
 			return 0;
 		}
 		if (n < 1 || n > 10) {
 			NORM_ERR("invalid num arg for top. Must be between 1 and 10.");
+			free(td->s);
+			free(obj->data.opaque);
 			return 0;
 		} else {
 			td->num = n - 1;
 		}
 	} else {
 		NORM_ERR("invalid argument count for top");
+		free(td->s);
+		free(obj->data.opaque);
 		return 0;
 	}
 	return 1;
