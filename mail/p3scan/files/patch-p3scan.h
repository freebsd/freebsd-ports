--- p3scan.h.orig	Mon May  1 00:33:38 2006
+++ p3scan.h	Mon May  1 00:36:01 2006
@@ -110,21 +110,21 @@
 #define VIRUS_SCANNER_VIRUSCODE  1
 #define PID_FILE                 "/var/run/p3scan/p3scan.pid"
 #define SYSLOG_NAME              "p3scan"
-#define CONFIGFILE               "/etc/p3scan/p3scan.conf"
-#define VIRUS_TEMPLATE           "/etc/p3scan/p3scan.mail"
+#define CONFIGFILE               "/usr/local/etc/p3scan/p3scan.conf"
+#define VIRUS_TEMPLATE           "/usr/local/etc/p3scan/p3scan.mail"
 #define DEBUG                    0
 #define QUIET                    0
 #define OVERWRITE                NULL
 #define CHECKSPAM                0
-#define SPAMCHECK                "/usr/bin/spamc"
+#define SPAMCHECK                "/usr/local/bin/spamc"
 #define MINSPACE                 10000
 #define DELIT                    0
 #define SUBJECT                  "[Virus] found in a mail to you:"
 #define NOTIFY                   "Per instruction, the message has been deleted."
 #define SMTPRSET                 "Virus detected! P3scan rejected message!"
-#define XMAIL                    "/bin/mail"
-#define FOOTER                   "/etc/p3scan/p3scan.footer"
-#define EXTRA                    "/etc/p3scan/p3scan.extra"
+#define XMAIL                    "/usr/bin/mail"
+#define FOOTER                   "/usr/local/etc/p3scan/p3scan.footer"
+#define EXTRA                    "/usr/local/etc/p3scan/p3scan.extra"
 #define EMERGCON                 "root@localhost postmaster@localhost"
 /* Defaut maximum mail size for scanning. ZERO for no limit! */
 #define MAX_SIZE_SCAN            0
