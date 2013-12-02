diff --git a/src/rx/rx_clock.h b/src/rx/rx_clock.h
index 2bdc0b8..0810432 100644
--- a/src/rx/rx_clock.h
+++ b/src/rx/rx_clock.h
@@ -92,7 +92,7 @@ extern int clock_nUpdates;
 #if defined(AFS_SGI61_ENV) || defined(AFS_HPUX_ENV) || defined(AFS_LINUX_64BIT_KERNEL)
 #define clock_GetTime(cv) osi_GetTime((osi_timeval_t *)cv)
 #else
-#if (defined(AFS_AIX51_ENV) && defined(AFS_64BIT_KERNEL)) || (defined(AFS_DARWIN100_ENV) && defined(__amd64__)) || defined(AFS_NBSD_ENV)
+#if (defined(AFS_AIX51_ENV) && defined(AFS_64BIT_KERNEL)) || (defined(AFS_DARWIN100_ENV) && defined(__amd64__)) || defined(AFS_XBSD_ENV)
 #define        clock_GetTime(cv)                               \
     BEGIN                                              \
        struct timeval tv;                              \
