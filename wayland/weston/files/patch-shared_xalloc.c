--- shared/xalloc.c.orig	2016-05-19 21:36:04 UTC
+++ shared/xalloc.c
@@ -35,7 +35,7 @@ void *
 fail_on_null(void *p, size_t size, char *file, int32_t line)
 {
 	if (p == NULL) {
-		fprintf(stderr, "[%s] ", program_invocation_short_name);
+		fprintf(stderr, "[%s] ", getprogname());
 		if (file)
 			fprintf(stderr, "%s:%d: ", file, line);
 		fprintf(stderr, "out of memory");
