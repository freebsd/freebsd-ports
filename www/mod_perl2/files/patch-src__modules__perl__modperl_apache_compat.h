--- ./src/modules/perl/modperl_apache_compat.h.orig	2008-05-08 12:59:16.000000000 -0400
+++ ./src/modules/perl/modperl_apache_compat.h	2008-05-08 12:59:30.000000000 -0400
@@ -22,6 +22,7 @@
 #if !APR_HAS_THREADS
 typedef unsigned long apr_os_thread_t;
 typedef void * apr_thread_mutex_t;
+typedef void * apr_thread_rwlock_t;
 #endif
 
 /* back compat adjustements for older Apache versions
