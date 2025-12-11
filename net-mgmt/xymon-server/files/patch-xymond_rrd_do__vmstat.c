--- xymond/rrd/do_vmstat.c.orig	2025-12-10 23:19:34 UTC
+++ xymond/rrd/do_vmstat.c
@@ -116,30 +116,6 @@ static vmstat_layout_t vmstat_irix_layout[] = {
 	{ -1, NULL }
 };
 
-/* This one matches FreeBSD 4.10 */
-/* LARRD 0.43c compatible */
-static vmstat_layout_t vmstat_freebsd4_layout[] = {
-	{ 0, "cpu_r" },
-	{ 1, "cpu_b" },
-	{ 2, "cpu_w" },
-	{ 3, "mem_avm" },
-	{ 4, "mem_free" },
-	{ 5, "mem_flt" },
-	{ 6, "mem_re" },
-	{ 7, "mem_pi" },
-	{ 8, "mem_po" },
-	{ 9, "mem_fr" },
-	{ 10, "sr" },
-	{ 11, "dsk_da0" },
-	{ 12, "dsk_fd0" },
-	{ 13, "cpu_int" },
-	{ 15, "cpu_csw" },
-	{ 16, "cpu_sys" },
-	{ 17, "cpu_usr" },
-	{ 18, "cpu_idl" },
-	{ -1, NULL }
-};
-
 /* FreeBSD v6 and later, possibly v5 also */
 static vmstat_layout_t vmstat_freebsd_layout[] = {
 	{ 0, "cpu_r" },
@@ -418,25 +394,7 @@ int do_vmstat_rrd(char *hostname, char *testname, char
 	  case OS_HPUX: 
 		layout = vmstat_hpux_layout; break;
 	  case OS_FREEBSD:
-		/* 
-		 * Special, because there are two layouts for FreeBSD
-		 * FreeBSD v4.x has 19 fields, later versions of FreeBSD
-		 * are the same as OpenBSD, with 18 fields.
-		 */
-		{
-			char **dsnames = NULL;
-			int dscount, i;
-
-			dscount = rrddatasets(hostname, &dsnames);
-			layout = ((dscount == 19) ? vmstat_freebsd4_layout : vmstat_freebsd_layout);
-
-			if ((dscount > 0) && dsnames) {
-				/* Free the dsnames list */
-				for (i=0; (i<dscount); i++) xfree(dsnames[i]);
-				xfree(dsnames);
-			}
-		}
-		break;
+		layout = vmstat_freebsd_layout; break;
 	  case OS_NETBSD:
 		layout = vmstat_netbsd_layout; break;
 	  case OS_OPENBSD:
