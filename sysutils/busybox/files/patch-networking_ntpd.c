--- networking/ntpd.c.orig	2018-12-30 15:14:20 UTC
+++ networking/ntpd.c
@@ -114,6 +114,12 @@
 # define IPTOS_DSCP_AF21 0x48
 #endif
 
+#ifdef __FreeBSD__
+#define adjtimex ntp_adjtime
+#define ADJ_OFFSET     MOD_OFFSET
+#define ADJ_STATUS     MOD_STATUS
+#define ADJ_TIMECONST  MOD_TIMECONST
+#endif
 
 /* Verbosity control (max level of -dddd options accepted).
  * max 6 is very talkative (and bloated). 3 is non-bloated,
