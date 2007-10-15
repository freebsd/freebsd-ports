--- mod_clamav.c.bak	Fri Oct 12 10:03:41 2007
+++ mod_clamav.c	Fri Oct 12 10:02:09 2007
@@ -102,6 +102,22 @@
     unsigned long	reloads;	/* number of database reloads (local) */
 } clamav_stats;
 
+const char *cl_perror(int clerror) /* deprecated */ 
+{ 
+	return cl_strerror(clerror); 
+} 
+ 
+void cl_freetrie(struct cl_node *root) /* for backward compatibility */ 
+{ 
+	cl_free(root); 
+} 
+ 
+int cl_buildtrie(struct cl_node *root) /* for backward compatibility */ 
+{ 
+	return cl_build(root); 
+} 
+ 
+
 static void	clamav_virus_record(clamav_stats *stats, const char *uri,
 		    const char *req, const char *virus, off_t size) {
     /* find the index of the entry we are about to create */
