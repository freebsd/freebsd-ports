--- p3scan.c.orig	Thu Jan  6 04:53:04 2005
+++ p3scan.c	Fri Jul 29 10:10:15 2005
@@ -36,36 +36,38 @@
 TODO: Wanted: white-list support
 TODO: Wanted: no iptables support
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
+#include <sys/statvfs.h>
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
-#include <sys/statvfs.h>
 #include <assert.h>
 #include <sys/select.h>
+#include <sys/ucred.h>
+#include <sys/mount.h>
+
 
 #include "p3scan.h"
 #include "getline.h"
@@ -94,13 +96,13 @@
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
 #define MINSPACE                 0
 #define DELIT                    0
 #define NEWLINE                  '\n'
@@ -507,10 +509,21 @@
    FILE * scanner;
    static char  line[4096*16];
    //static char  line[4096];
-   struct statvfs fs;
    unsigned long kbfree;
    int htmlfd;
 
+   struct statfs fs;
+    if ((ret=statfs(config->virusdir,&fs))!=0) {
+      do_log(LOG_EMERG, "Unable to get available space!");
+      return SCANNER_RET_CRIT; // Should never reach here, but keep it clean. :)
+    }
+    kbfree=fs.f_bavail*fs.f_bsize/1024;
+    if ( config->freespace != 0 && kbfree < config->freespace ){
+      do_log(LOG_CRIT, "Not enough space! Available space: %d", kbfree);
+      return SCANNER_RET_CRIT;
+    }
+
+
    ret=checktimeout(p);
    if (ret < 0) return SCANNER_RET_CRIT;
    /* See if we have enough room to process the message based upon
@@ -521,7 +534,7 @@
       do_log(LOG_EMERG, "Unable to get available space!");
       return SCANNER_RET_CRIT; // Should never reach here, but keep it clean. :)
    }
-   kbfree=(fs.f_bavail * fs.f_frsize / 1024);
+   kbfree=(fs.f_bavail * fs.f_bsize / 1024);
    if ( config->freespace != 0 && kbfree < config->freespace ){
       p->errmsg=1;
       do_log(LOG_CRIT, "Not enough space! Available space: %d", kbfree);
@@ -1179,8 +1192,10 @@
 
    p->server_addr.sin_family = AF_INET;
    if (htonl(INADDR_ANY) == config->targetaddr.sin_addr.s_addr) {
-      if (getsockopt(p->client_fd, SOL_IP, SO_ORIGINAL_DST, &p->server_addr, &p->socksize)){
-         do_log(LOG_CRIT, "No IP-Conntrack-data (getsockopt failed)");
+//      if (getsockopt(p->client_fd, SOL_IP, SO_ORIGINAL_DST, &p->server_addr, &p->socksize)){
+//         do_log(LOG_CRIT, "No IP-Conntrack-data (getsockopt failed)");
+   if (getsockname(p->client_fd, (struct sockaddr*)&p->server_addr, &p->socksize)){
+      do_log(LOG_CRIT, "No IP-Conntrack-data (getsockname failed)");
          return 1;
       }
       /* try to avoid loop */
@@ -2041,7 +2056,7 @@
    char * responsemsg;
    int virusdirlen;
    char chownit[100];
-#define CHOWNCMD "/bin/chown"
+#define CHOWNCMD "/usr/sbin/chown"
    int len;
    int ret;
    FILE * chowncmd;
@@ -2080,7 +2095,10 @@
       if (!config->debug){
          len=strlen(CHOWNCMD)+1+strlen(config->runasuser)+1+strlen(config->runasuser)+1+strlen(config->pidfile)+1;
          //do_log(LOG_DEBUG, "%s %s.%s %s=%i",CHOWNCMD, config->runasuser, config->runasuser, config->pidfile, len);
-         snprintf(chownit, len, "%s %s.%s %s", CHOWNCMD, config->runasuser, config->runasuser, config->pidfile);
+//         snprintf(chownit, len, "%s %s.%s %s", CHOWNCMD, config->runasuser, config->runasuser, config->pidfile);
+         do_log(LOG_DEBUG, "%s %s:%s %s=%i",CHOWNCMD, config->runasuser, config->runasuser, config->pidfile, len);
+         snprintf(chownit, len, "%s %s:%s %s", CHOWNCMD, config->runasuser, config->runasuser, config->pidfile);
+
          if ((chowncmd=popen(chownit, "r"))==NULL){
             do_log(LOG_ALERT, "Can't '%s' !!!", chowncmd);
             return SCANNER_RET_ERR;
