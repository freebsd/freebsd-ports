
$FreeBSD$

--- parser.c.orig
+++ parser.c
@@ -65,11 +65,13 @@
 		/** note: it may be a good option to save values, and restore
 		 * them when exiting
 		 */
+		/*
 		write_proc("/proc/sys/net/ipv6/conf/all/autoconf",flag);
 		write_proc("/proc/sys/net/ipv6/conf/all/accept_ra",flag);
 		write_proc("/proc/sys/net/ipv6/conf/all/accept_ra_defrtr",flag);
 		write_proc("/proc/sys/net/ipv6/conf/all/accept_ra_pinfo",flag);
 		write_proc("/proc/sys/net/ipv6/conf/all/accept_redirects",flag);
+		*/
 	}
 
 	xmlXPathFreeObject (xmlobject);
