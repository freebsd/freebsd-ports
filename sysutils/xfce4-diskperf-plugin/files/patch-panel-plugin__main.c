--- ./panel-plugin/main.c.orig	2012-06-23 05:02:16.000000000 -0300
+++ ./panel-plugin/main.c	2013-09-11 17:44:45.000000000 -0300
@@ -86,7 +86,7 @@
 typedef struct param_t {
     /* Configurable parameters */
     char            acDevice[64];
-#if  !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(__sun__)
+#if  !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(__sun__)
     dev_t           st_rdev;
 #endif
     int             fTitleDisplayed;
@@ -172,7 +172,7 @@
     struct param_t *poConf = &(p_poPlugin->oConf.oParam);
     struct monitor_t *poMonitor = &(p_poPlugin->oMonitor);
     struct perfbar_t *poPerf = poMonitor->aoPerfBar;
-#if !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(__sun__)
+#if !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(__sun__)
     struct stat     oStat;
 #endif
     uint64_t        iInterval_ns, rbytes, wbytes, iRBusy_ns, iWBusy_ns;
@@ -185,7 +185,7 @@
     rbytes = wbytes = iRBusy_ns = iWBusy_ns = -1;
     memset (&oPerf, 0, sizeof (oPerf));
     oPerf.qlen = -1;
-#if defined (__NetBSD__) || defined(__OpenBSD__) || defined(__sun__)
+#if defined(__FreeBSD__) || defined (__NetBSD__) || defined(__OpenBSD__) || defined(__sun__)
     status = DevGetPerfData (poConf->acDevice, &oPerf);
 #else
     if (poConf->st_rdev == 0)
@@ -429,7 +429,7 @@
     struct diskperf_t *poPlugin;
     struct param_t *poConf;
     struct monitor_t *poMonitor;
-#if !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(__sun__)
+#if !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(__sun__)
     struct stat     oStat;
     int             status;
 #endif
@@ -444,6 +444,9 @@
 #if defined(__NetBSD__) || defined(__OpenBSD__)
     strncpy (poConf->acDevice, "wd0", 64);
     strncpy (poConf->acTitle, "wd0", 16);
+#elif defined(__FreeBSD__)
+    strncpy (poConf->acDevice, "ada0", 64);
+    strncpy (poConf->acTitle, "ada0", 16);
 #elif defined(__sun__)
     strncpy (poConf->acDevice, "sd0", 64);
     strncpy (poConf->acTitle, "sd0", 16);
@@ -517,7 +520,7 @@
     struct param_t *poConf = &(poPlugin->oConf.oParam);
     struct monitor_t *poMonitor = &(poPlugin->oMonitor);
     Widget_t       *pw2ndBar = poPlugin->oMonitor.awProgressBar + 1;
-#if !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(__sun__)
+#if !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(__sun__)
     struct stat     oStat;
     int             status;
 #endif
@@ -534,7 +537,7 @@
     if ((value = xfce_rc_read_entry (rc, (CONF_DEVICE), NULL))) {
         memset (poConf->acDevice, 0, sizeof (poConf->acDevice));
         strncpy (poConf->acDevice, value, sizeof (poConf->acDevice) - 1);
-#if !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(__sun__)
+#if !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(__sun__)
         status = stat (poConf->acDevice, &oStat);
         poConf->st_rdev = (status == -1 ? 0 : oStat.st_rdev);
 #endif
@@ -666,7 +669,7 @@
     struct diskperf_t *poPlugin = (diskperf_t *) p_pvPlugin;
     struct param_t *poConf = &(poPlugin->oConf.oParam);
     const char     *pcDevice = gtk_entry_get_text (GTK_ENTRY (p_wTF));
-#if !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(__sun__)
+#if !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(__sun__)
     struct stat     oStat;
     int             status;
 
