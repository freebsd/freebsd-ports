--- sadmin/proc_iomem_count.c.orig	2020-07-12 09:44:16 UTC
+++ sadmin/proc_iomem_count.c
@@ -17,7 +17,7 @@
 
 static int main2(int argc, const char **argv)
 {
-	const char *file = "/proc/iomem";
+	const char *file = "/compat/linux/proc/iomem";
 	uint64_t start, end;
 	hxmc_t *ln = NULL;
 	char *e;
@@ -28,7 +28,7 @@ static int main2(int argc, const char **argv)
 
 	fp = fopen(file, "r");
 	if (fp == NULL) {
-		fprintf(stderr, "fopen: /proc/iomem: %s\n", strerror(errno));
+		fprintf(stderr, "fopen: /compat/linux/proc/iomem: %s\n", strerror(errno));
 		return EXIT_FAILURE;
 	}
 
