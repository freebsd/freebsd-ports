--- src/fdevent_freebsd_kqueue.c.orig	Tue Aug 30 09:50:58 2005
+++ src/fdevent_freebsd_kqueue.c	Tue Aug 30 09:51:16 2005
@@ -108,6 +108,7 @@
 			fprintf(stderr, "%s.%d: kqueue failed polling: %s\n",
 				__FILE__, __LINE__, strerror(errno));
 			break;
+		}
 	}
 
 	return ret;
