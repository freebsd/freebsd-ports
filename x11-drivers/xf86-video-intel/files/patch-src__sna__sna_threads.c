--- src/sna/sna_threads.c.orig	2013-02-02 00:03:44.000000000 +0000
+++ src/sna/sna_threads.c	2013-02-02 00:04:39.000000000 +0000
@@ -94,7 +94,11 @@
 		size_t len = 0;
 		char *line = NULL;
 		uint32_t processors = 0, cores = 0;
+#ifdef __GLIBC__
 		while (getline(&line, &len, file) != -1) {
+#else
+		while ((line = fgetln(file, &len)) != (char *) NULL) {
+#endif
 			int id;
 			if (sscanf(line, "physical id : %d", &id) == 1) {
 				if (id >= 32)
