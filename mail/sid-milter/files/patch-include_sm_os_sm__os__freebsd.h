--- include/sm/os/sm_os_freebsd.h.orig
+++ include/sm/os/sm_os_freebsd.h
@@ -34,7 +34,11 @@
 # define SM_CONF_SHM	1
 #endif /* SM_CONF_SHM */
 #ifndef SM_CONF_SEM
+#if __FreeBSD_version < 1200059
 # define SM_CONF_SEM	1
+#else
+# define SM_CONF_SEM	2
+#endif
 #endif /* SM_CONF_SEM */
 #ifndef SM_CONF_MSG
 # define SM_CONF_MSG	1
