Index: acconfig.h
diff -u acconfig.h.orig acconfig.h
--- acconfig.h.orig	Fri Feb 14 05:32:50 2003
+++ acconfig.h	Fri Mar 21 21:03:25 2003
@@ -263,8 +263,12 @@
 #define FNAME_DOMAINDIR "/domain/"
 #define FNAME_LOGDIR "/log/"
 #define FNAME_PTSDB "/ptclient/ptscache.db"
+#if !defined(CONFIG_FILENAME)
 #define CONFIG_FILENAME "/etc/imapd.conf"
+#endif
+#if !defined(DEFAULT_MASTER_CONFIG_FILENAME)
 #define DEFAULT_MASTER_CONFIG_FILENAME "/etc/cyrus.conf"
+#endif
 
 #ifndef HAVE_SHUTDOWN
 #define shutdown(fd, mode) 0
