+++ common/freqship.org	Wed Aug  9 19:16:00 2000
--- common/freqship.h	Sun Nov 20 13:38:11 2005
@@ -1,10 +1,10 @@
-#define UPSFILE   "/etc/freqship/UPSFILE"
-#define STATFILE  "/etc/freqship/STATUS"
-#define PMSGEFILE "/etc/freqship/PMSGERR"
-#define PMSGOFILE "/etc/freqship/PMSGOK"
-#define DELAYFILE "/etc/freqship/DELAY"
-#define UPSSTAT   "/etc/freqship/UPSSTAT"
-#define DAEMON    "/sbin/freqshpd"
+#define UPSFILE   PREFIX "/etc/freqship/UPSFILE"
+#define STATFILE  PREFIX "/etc/freqship/STATUS"
+#define PMSGEFILE PREFIX "/etc/freqship/PMSGERR"
+#define PMSGOFILE PREFIX "/etc/freqship/PMSGOK"
+#define DELAYFILE PREFIX "/etc/freqship/DELAY"
+#define UPSSTAT   PREFIX "/etc/freqship/UPSSTAT"
+#define DAEMON    PREFIX "/sbin/freqshpd"
 
 /*  UPS States '99-10-15 BCC */
 #define S_NOCHANGE -1  /*  don't know  */
