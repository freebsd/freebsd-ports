$FreeBSD$

--- src/comp/comp.c.orig	2012-11-18 13:25:06.000000000 -0800
+++ src/comp/comp.c	2012-11-18 13:25:12.000000000 -0800
@@ -278,7 +278,7 @@
     }
 
     /* initialize */
-    if (!conf_init(argv[0], (char *) NULL, module, &fragment)) {
+    if (!conf_init(argv[0], (char *) NULL, (char *) NULL, module, &fragment)) {
 	P_message("Initialization failed\012");	/* LF */
 	return 2;
     }
@@ -542,6 +542,14 @@
 }
 
 /*
+ * NAME:	swap->conv2()
+ * DESCRIPTION:	pretend to restore bytes from a vector of sectors in the secondary snapshot
+ */
+void sw_conv2(char *m, sector *vec, Uint size, Uint idx)
+{
+}
+
+/*
  * NAME:	swap->mapsize()
  * DESCRIPTION:	pretend to count the number of sectors required for size bytes
  */
@@ -572,12 +580,20 @@
  * NAME:	swap->dump()
  * DESCRIPTION:	pretend to create snapshot
  */
-int sw_dump(char *snapshot)
+int sw_dump(char *snapshot, bool keep)
 {
     return 0;
 }
 
 /*
+ * NAME:	swap->dump2()
+ * DESCRIPTION:	pretend to finish snapshot
+ */
+void sw_dump2(char *header, int size, bool incr)
+{
+}
+
+/*
  * NAME:	swap->restore()
  * DESCRIPTION:	pretend to restore swap file
  */
@@ -586,6 +602,14 @@
 }
 
 /*
+ * NAME:	swap->restore2()
+ * DESCRIPTION:	pretend to restore secondary snapshot
+ */
+void sw_restore2(int fd)
+{
+}
+
+/*
  * NAME:	comm->init()
  * DESCRIPTION:	pretend to initialize communications
  */
@@ -603,6 +627,14 @@
 }
 
 /*
+ * NAME:        comm->clear()
+ * DESCRIPTION: pretend to clean up connections
+ */
+void comm_clear()
+{
+}
+
+/*
  * NAME:	comm->finish()
  * DESCRIPTION:	pretend to terminate connections
  */
@@ -750,6 +782,24 @@
 }
 
 /*
+ * NAME:        comm->dump()
+ * DESCRIPTION: pretend to save users
+ */
+bool comm_dump(int fd)
+{
+    return TRUE;
+}
+
+/*
+ * NAME:        comm->restore()
+ * DESCRIPTION: pretend to restore users
+ */
+bool comm_restore(int fd)
+{
+    return TRUE;
+}
+
+/*
  * NAME:	ed->init()
  * DESCRIPTION:	pretend to initialize editor handling
  */
