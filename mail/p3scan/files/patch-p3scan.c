--- p3scan.c.orig	Tue Dec 13 02:00:00 2005
+++ p3scan.c	Wed Nov  1 11:44:03 2006
@@ -41,36 +41,37 @@
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
 
 #include "p3scan.h"
 #include "getline_ssl.h"
@@ -182,8 +183,8 @@
      do_log(LOG_NOTICE, "ERR: Exiting now...\n");
      fprintf(stderr, "%s\n", puffer);
      if (strlen(NONULL(config->emergency))){
-        snprintf(puffer,4096,"echo '%s' | %s -s 'P3Scan Terminating!' %s", config->emergency, config->mail, config->emergcon);
-        do_log(LOG_DEBUG,"echo '%s' | %s -s 'P3Scan Terminating!' %s", config->emergency, config->mail, config->emergcon);
+        snprintf(puffer,4096,"echo \"%s\" | %s -s 'P3Scan Terminating' %s", config->emergency, config->mail, config->emergcon);
+        do_log(LOG_DEBUG,"echo \"%s\" | %s -s 'P3Scan Terminating' %s", config->emergency, config->mail, config->emergcon);
         if (system(puffer)) fprintf(stderr,"ERR: Calling do_log!");
      }
      /* Tell main p3scan to abort */
@@ -1640,8 +1641,9 @@
       }
    } else {
       if (htonl(INADDR_ANY) == config->targetaddr.sin_addr.s_addr) {
-         if (getsockopt(p->client_fd, SOL_IP, SO_ORIGINAL_DST, &p->server_addr, &p->socksize)){
-            do_log(LOG_CRIT, "ERR: No IP-Conntrack-data (getsockopt failed)");
+         // if (getsockopt(p->client_fd, SOL_IP, SO_ORIGINAL_DST, &p->server_addr, &p->socksize)){
+         //   do_log(LOG_CRIT, "ERR: No IP-Conntrack-data (getsockopt failed)");
+	    if (getsockname(p->client_fd, (struct sockaddr*)&p->server_addr, &p->socksize)){
             return 1;
          }
          /* try to avoid loop */
@@ -2882,7 +2884,7 @@
    char * responsemsg;
    int virusdirlen=0;
    char chownit[100];
-#define CHOWNCMD "/bin/chown"
+#define CHOWNCMD "/usr/sbin/chown"
    int len=0;
    int ret=0;
    FILE * chowncmd;
@@ -2920,7 +2922,8 @@
       fclose(fp);
    }else do_log(LOG_CRIT, "ERR: Can't write PID to %s", PID_FILE);
    len=strlen(CHOWNCMD)+1+strlen(config->runasuser)+1+strlen(config->runasuser)+1+strlen(config->pidfile)+1;
-   snprintf(chownit, len, "%s %s:%s %s", CHOWNCMD, config->runasuser, config->runasuser, config->pidfile);
+         do_log(LOG_DEBUG, "%s %s:%s %s=%i",CHOWNCMD, config->runasuser, config->runasuser, config->pidfile, len);
+         snprintf(chownit, len, "%s %s:%s %s", CHOWNCMD, config->runasuser, config->runasuser, config->pidfile);
    if ((chowncmd=popen(chownit, "r"))==NULL){
       do_log(LOG_ALERT, "ERR: Can't '%s' !!!", chowncmd);
       return SCANNER_RET_ERR;
