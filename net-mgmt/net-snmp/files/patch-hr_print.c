--- agent/mibgroup/host/hr_print.c.orig	Wed Oct  3 00:02:07 2001
+++ agent/mibgroup/host/hr_print.c	Wed Feb 13 01:02:53 2002
@@ -30,7 +30,9 @@
 int printer_detail_status(int);
 int printer_errors(int);
 int header_hrprint (struct variable *,oid *, size_t *, int, size_t *, WriteMethod **);
+#ifdef HAVE_LPSTAT
 FILE * run_lpstat(void);
+#endif
 
 
 	/*********************
