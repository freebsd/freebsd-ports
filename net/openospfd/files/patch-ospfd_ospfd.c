--- ospfd/ospfd.c.orig	2008-02-07 18:31:27.000000000 +0300
+++ ospfd/ospfd.c	2008-02-07 18:41:46.000000000 +0300
@@ -300,7 +300,9 @@
 
 	control_cleanup();
 	kr_shutdown();
+#if !defined(__FreeBSD__) /* XXX: FreeBSD has no carp demotion. */
 	carp_demote_shutdown();
+#endif /* defined(__FreeBSD__) */
 
 	do {
 		if ((pid = wait(NULL)) == -1 &&
@@ -398,10 +400,14 @@
 				log_warnx("IFINFO request with wrong len");
 			break;
 		case IMSG_DEMOTE:
+#if !defined(__FreeBSD__) /* XXX: FreeBSD has no carp demotion support. */
 			if (imsg.hdr.len - IMSG_HEADER_SIZE != sizeof(dmsg))
 				fatalx("invalid size of OE request");
 			memcpy(&dmsg, imsg.data, sizeof(dmsg));
 			carp_demote_set(dmsg.demote_group, dmsg.level);
+#else
+			log_debug("main_dispatch_ospfe: no carp demotion support for FreeBSD");
+#endif /* defined(__FreeBSD__) */
 			break;
 		default:
 			log_debug("main_dispatch_ospfe: error handling imsg %d",
