--- include/sm/conf.h.orig	2009-06-17 09:41:32.000000000 +1000
+++ include/sm/conf.h	2010-02-27 09:31:33.000000000 +1100
@@ -1014,6 +1014,9 @@
 #    if __FreeBSD_version >= 222000	/* 2.2.2-release and later */
 #     define HASSETUSERCONTEXT	1	/* BSDI-style login classes */
 #    endif /* __FreeBSD_version >= 222000 */
+#    if __FreeBSD_version >= 300000	/* 3.0.0-release and later */
+#     define HAVE_NANOSLEEP	1	/* has nanosleep(2) */
+#    endif /* __FreeBSD_version >= 300000 */
 #    if __FreeBSD_version >= 330000	/* 3.3.0-release and later */
 #     ifndef SMRSH_CMDDIR
 #      define SMRSH_CMDDIR	"/usr/libexec/sm.bin"
