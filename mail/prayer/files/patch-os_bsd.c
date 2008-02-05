--- ../p/prayer/os_bsd.c	2008-01-15 17:04:47.000000000 +0000
+++ prayer/os_bsd.c	2008-02-04 20:56:55.000000000 +0000
@@ -573,5 +573,7 @@
 void
 os_prctl_set_dumpable()
 {
+#if 0
     prctl(PR_SET_DUMPABLE, 1);
+#endif
 }
