--- rscsi/rscsi.c	Thu Mar  6 16:26:19 2003
+++ rscsi/rscsi.c	Thu Jul 31 07:51:15 2003
@@ -143,8 +143,14 @@
 	if (debug_name == NULL && argc <= 0)
 		debug_name = "/tmp/RSCSI";
 #endif
-	if (argc > 0)
+#ifdef	NONONO
+	/*
+	 * Should we allow root to shoot himself into the foot?
+	 * Allowing to write arbitrary files may be a security risk.
+	 */
+	if (argc > 0 && getuid() == 0)
 		debug_name = *argv;
+#endif
 
 	if (debug_name != NULL)
 		debug_file = fopen(debug_name, "w");
