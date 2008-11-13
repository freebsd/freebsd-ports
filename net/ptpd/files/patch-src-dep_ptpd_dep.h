--- dep/ptpd_dep.h.orig
+++ dep/ptpd_dep.h
@@ -22,7 +22,7 @@
 
 /* system messages */
 #define ERROR(x, ...)  fprintf(stderr, "(ptpd error) " x, ##__VA_ARGS__)
-#define PERROR(x, ...) fprintf(stderr, "(ptpd error) " x ": %m\n", ##__VA_ARGS__)
+#define PERROR(x, ...) fprintf(stderr, "(ptpd error) " x ": %s\n", ##__VA_ARGS__, strerror(errno))
 #define NOTIFY(x, ...) fprintf(stderr, "(ptpd notice) " x, ##__VA_ARGS__)
 
 /* debug messages */
