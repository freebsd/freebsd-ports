--- platform/FreeBSD/sm_pf.c.orig	Fri Dec  2 12:06:20 2005
+++ platform/FreeBSD/sm_pf.c	Fri Dec  2 12:06:38 2005
@@ -73,6 +73,12 @@
     fatal("pf support not available");
 }
 
+void
+gets_pf()
+{
+    fatal("pf support not available");
+}
+
 int
 get_pf(char *symon_buf, int maxlen, struct stream *st)
 {
