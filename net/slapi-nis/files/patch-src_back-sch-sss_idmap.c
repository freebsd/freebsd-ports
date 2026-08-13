--- src/back-sch-sss_idmap.c.orig	2026-08-07 11:56:09.226628000 +0200
+++ src/back-sch-sss_idmap.c	2026-08-07 11:56:09.233987000 +0200
@@ -47,8 +47,10 @@
         return NSS_STATUS_SUCCESS;
     case ENOENT:
         return NSS_STATUS_NOTFOUND;
+#ifdef ETIME
     case ETIME:
         /* fall-through */
+#endif
     case ERANGE:
         return NSS_STATUS_TRYAGAIN;
     case ETIMEDOUT:
