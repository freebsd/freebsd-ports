--- src/qscan.h.orig	Thu Apr  8 14:31:31 2004
+++ src/qscan.h	Thu Apr  8 14:32:18 2004
@@ -178,8 +178,8 @@
 #define QSCAN_TIMEOUT 3000
 #define RIPMIME_DESTDIR_BASE "/var/qmail/qscan"
 #define RIPMIME_ARGS "-i", "-", "-d"
-#define SWEEP_ARGS "-all", "-rec", "-ss", "-zip", "-arj", "-rar", "-cab", "-tnef"
-#define SWEEP_VIRUS_PREFIX ">>> "
+#define SWEEP_ARGS "--disable-summary", "--stdout"
+#define SWEEP_VIRUS_PREFIX " FOUND"
 #define SWEEP_TIMEOUT 250
 #define SWEEP_NICE 15
 #define MSG_BUFSIZE 8192
