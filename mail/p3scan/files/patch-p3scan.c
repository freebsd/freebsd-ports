--- p3scan.c.orig	Wed Jan 21 01:26:48 2004
+++ p3scan.c	Wed Feb 18 12:52:37 2004
@@ -30,34 +30,39 @@
  *
  */
 
-#include <stdio.h>
-#include <stdlib.h>
-#include <string.h>
-#include <arpa/inet.h>
-#include <netinet/in.h>
-#include <netinet/ip.h>
-#include <sys/socket.h>
 #include <sys/types.h>
+#include <sys/socket.h>
+#include <sys/wait.h>
+#include <sys/time.h>
+#include <sys/param.h>
+#include <sys/signal.h>
 #include <sys/stat.h>
+#include <netinet/in.h>
+#include <netinet/in_systm.h>
+#include <netinet/ip.h>
+#include <arpa/inet.h>
 #include <fcntl.h>
 #include <unistd.h>
 #include <stdarg.h>
-#include <sys/signal.h>
-#include <sys/wait.h>
 #include <pwd.h>
 #include <time.h>
-#include <sys/time.h>
 #include <syslog.h>
-#include <sys/param.h>
 #include <ctype.h>
-#include <linux/netfilter_ipv4.h>
-#include <malloc.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <getopt.h>
 #include <netdb.h>
 #include <libgen.h>
 #include <errno.h>
 #include <dirent.h>
+#ifdef __FreeBSD__
+#include <sys/ucred.h>
+#include <sys/mount.h>
+#else
+#include <linux/netfilter_ipv4.h>
 #include <sys/statvfs.h>
+#endif
 
 #include "p3scan.h"
 #include "getline.h"
@@ -81,8 +86,8 @@
 #define VIRUS_SCANNER_VIRUSCODE  1
 #define PID_FILE                 "/var/run/p3scan/p3scan.pid"
 #define SYSLOG_NAME              "p3scan"
-#define CONFIGFILE               "/etc/p3scan/p3scan.conf"
-#define VIRUS_TEMPLATE           "/etc/p3scan/p3scan.mail"
+#define CONFIGFILE               "/usr/local/etc/p3scan/p3scan.conf"
+#define VIRUS_TEMPLATE           "/usr/local/etc/p3scan/p3scan.mail"
 #define DEBUG                    0
 #define QUIET                    0
 #define OVERWRITE                0
@@ -340,11 +345,22 @@
 #define MOVEIT "/bin/mv"
    FILE * scanner;
    static char  line[4096*16];
-   struct statvfs fs;
    int kbfree;
    struct linebuf *filebuf;
    int res, htmlfd, html, toggle;
 
+#ifdef __FreeBSD__
+/*
+    struct statfs fsstats[10];
+    if ((ret=getfsstat(fsstats,sizeof(fsstats)/sizeof(fsid_t),MNT_WAIT))!=0) {
+      do_log(LOG_EMERG, "Unable to get available space!");
+      return SCANNER_RET_CRIT; // Should never reach here, but keep it clean. :)
+    }
+*/
+#warning I should do something with this information - getfsstat
+#else
+   struct statvfs fs;
+
   /* See if we have enough room to process the message based upon
    what the user determines is enough room in p3scan.conf */
    if ( statvfs( config->virusdir, &fs ) == SCANNER_RET_ERR){
@@ -356,6 +372,7 @@
       do_log(LOG_CRIT, "Not enough space! Available space: %d", kbfree);
       return SCANNER_RET_CRIT;
    }
+#endif
 
    /* This is where we should scan for spam - before demime to
       give SpamAssassin the virgin message */
@@ -820,8 +837,8 @@
    do_log(LOG_NOTICE, "Connection from %s:%i", inet_ntoa(p->client_addr.sin_addr), ntohs(p->client_addr.sin_port));
 
    p->server_addr.sin_family = AF_INET;
-   if (getsockopt(p->client_fd, SOL_IP, SO_ORIGINAL_DST, &p->server_addr, &p->socksize)){
-      do_log(LOG_CRIT, "No IP-Conntrack-data (getsockopt failed)");
+   if (getsockname(p->client_fd, (struct sockaddr*)&p->server_addr, &p->socksize)){
+      do_log(LOG_CRIT, "No IP-Conntrack-data (getsockname failed)");
       return 1;
    }
    do_log(LOG_NOTICE, "Real-server adress is %s:%i", inet_ntoa(p->server_addr.sin_addr), ntohs(p->server_addr.sin_port));
@@ -1534,7 +1551,7 @@
    char * responsemsg;
    int virusdirlen;
    char chownit[100];
-#define CHOWNCMD "/bin/chown"
+#define CHOWNCMD "/usr/sbin/chown"
    int len;
    int ret;
    FILE * chowncmd;
@@ -1574,8 +1591,8 @@
       };
       // chown /var/run/p3scan/p3scan.pid mail.mail
       len=strlen(CHOWNCMD)+1+strlen(config->runasuser)+1+strlen(config->runasuser)+1+strlen(config->pidfile)+1;
-      do_log(LOG_DEBUG, "%s %s.%s %s=%i",CHOWNCMD, config->runasuser, config->runasuser, config->pidfile, len);
-      snprintf(chownit, len, "%s %s.%s %s", CHOWNCMD, config->runasuser, config->runasuser, config->pidfile);
+      do_log(LOG_DEBUG, "%s %s:%s %s=%i",CHOWNCMD, config->runasuser, config->runasuser, config->pidfile, len);
+      snprintf(chownit, len, "%s %s:%s %s", CHOWNCMD, config->runasuser, config->runasuser, config->pidfile);
       if ((chowncmd=popen(chownit, "r"))==NULL){
          do_log(LOG_ALERT, "Can't '%s' !!!", chowncmd);
          return SCANNER_RET_ERR;
