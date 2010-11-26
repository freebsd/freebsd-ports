--- pmlist.c.orig	2010-11-26 17:45:26.000000000 +0300
+++ pmlist.c	2010-11-26 17:49:30.000000000 +0300
@@ -1,3 +1,5 @@
+#include <stdio.h>
+#include <string.h>
 #include <stdlib.h>
 #include <sys/wait.h>
 #include <unistd.h>
@@ -8,10 +10,6 @@
 #include "gatedevice.h"
 #include "util.h"
 
-#if HAVE_LIBIPTC
-#include "iptc.h"
-#endif
-
 struct portMap* pmlist_NewNode(int enabled, long int duration, char *remoteHost,
 			       char *externalPort, char *internalPort,
 			       char *protocol, char *internalClient, char *desc)
@@ -233,55 +231,18 @@
 {
     if (enabled)
     {
-#if HAVE_LIBIPTC
-	char *buffer = malloc(strlen(internalClient) + strlen(internalPort) + 2);
-	if (buffer == NULL) {
-		fprintf(stderr, "failed to malloc memory\n");
-		return 0;
-	}
-
-	strcpy(buffer, internalClient);
-	strcat(buffer, ":");
-	strcat(buffer, internalPort);
-
-	if (g_vars.forwardRules)
-		iptc_add_rule("filter", g_vars.forwardChainName, protocol, NULL, NULL, NULL, internalClient, NULL, internalPort, "ACCEPT", NULL, FALSE);
-
-	iptc_add_rule("nat", g_vars.preroutingChainName, protocol, g_vars.extInterfaceName, NULL, NULL, NULL, NULL, externalPort, "DNAT", buffer, TRUE);
-	free(buffer);
-#else
 	char command[COMMAND_LEN];
-	int status;
 	
-	{
-	  char dest[DEST_LEN];
-	  char *args[] = {"iptables", "-t", "nat", "-I", g_vars.preroutingChainName, "-i", g_vars.extInterfaceName, "-p", protocol, "--dport", externalPort, "-j", "DNAT", "--to", dest, NULL};
-
-	  snprintf(dest, DEST_LEN, "%s:%s", internalClient, internalPort);
-	  snprintf(command, COMMAND_LEN, "%s -t nat -I %s -i %s -p %s --dport %s -j DNAT --to %s:%s", g_vars.iptables, g_vars.preroutingChainName, g_vars.extInterfaceName, protocol, externalPort, internalClient, internalPort);
-	  trace(3, "%s", command);
-	  if (!fork()) {
-	    int rc = execv(g_vars.iptables, args);
-	    exit(rc);
-	  } else {
-	    wait(&status);		
-	  }
-	}
-
-	if (g_vars.forwardRules)
-	{
-	  char *args[] = {"iptables", "-A", g_vars.forwardChainName, "-p", protocol, "-d", internalClient, "--dport", internalPort, "-j", "ACCEPT", NULL};
-	  
-	  snprintf(command, COMMAND_LEN, "%s -A %s -p %s -d %s --dport %s -j ACCEPT", g_vars.iptables,g_vars.forwardChainName, protocol, internalClient, internalPort);
-	  trace(3, "%s", command);
-	  if (!fork()) {
-	    int rc = execv(g_vars.iptables, args);
-	    exit(rc);
-	  } else {
-	    wait(&status);		
-	  }
-	}
-#endif
+	FILE *ipnat = popen("/sbin/ipnat -f -", "w");
+	sprintf(command, "rdr %s %s/32 port %s -> %s port %s %s\n",
+		g_vars.extInterfaceName, g_vars.extIpAddress, externalPort, internalClient, internalPort, protocol);
+	trace(3, "%s", command);
+	fprintf(ipnat, command);
+	sprintf(command, "rdr lo0 %s/32 port %s -> %s port %s %s\n",
+		g_vars.extIpAddress, externalPort, internalClient, internalPort, protocol);
+	trace(3, "%s", command);
+	fprintf(ipnat, command);
+	pclose(ipnat);
     }
     return 1;
 }
@@ -290,52 +251,18 @@
 {
     if (enabled)
     {
-#if HAVE_LIBIPTC
-	char *buffer = malloc(strlen(internalClient) + strlen(internalPort) + 2);
-	strcpy(buffer, internalClient);
-	strcat(buffer, ":");
-	strcat(buffer, internalPort);
-
-	if (g_vars.forwardRules)
-	    iptc_delete_rule("filter", g_vars.forwardChainName, protocol, NULL, NULL, NULL, internalClient, NULL, internalPort, "ACCEPT", NULL);
-
-	iptc_delete_rule("nat", g_vars.preroutingChainName, protocol, g_vars.extInterfaceName, NULL, NULL, NULL, NULL, externalPort, "DNAT", buffer);
-	free(buffer);
-#else
 	char command[COMMAND_LEN];
-	int status;
 	
-	{
-	  char dest[DEST_LEN];
-	  char *args[] = {"iptables", "-t", "nat", "-D", g_vars.preroutingChainName, "-i", g_vars.extInterfaceName, "-p", protocol, "--dport", externalPort, "-j", "DNAT", "--to", dest, NULL};
-
-	  snprintf(dest, DEST_LEN, "%s:%s", internalClient, internalPort);
-	  snprintf(command, COMMAND_LEN, "%s -t nat -D %s -i %s -p %s --dport %s -j DNAT --to %s:%s",
-		  g_vars.iptables, g_vars.preroutingChainName, g_vars.extInterfaceName, protocol, externalPort, internalClient, internalPort);
-	  trace(3, "%s", command);
-	  
-	  if (!fork()) {
-	    int rc = execv(g_vars.iptables, args);
-	    exit(rc);
-	  } else {
-	    wait(&status);		
-	  }
-	}
-
-	if (g_vars.forwardRules)
-	{
-	  char *args[] = {"iptables", "-D", g_vars.forwardChainName, "-p", protocol, "-d", internalClient, "--dport", internalPort, "-j", "ACCEPT", NULL};
-	  
-	  snprintf(command, COMMAND_LEN, "%s -D %s -p %s -d %s --dport %s -j ACCEPT", g_vars.iptables, g_vars.forwardChainName, protocol, internalClient, internalPort);
-	  trace(3, "%s", command);
-	  if (!fork()) {
-	    int rc = execv(g_vars.iptables, args);
-	    exit(rc);
-	  } else {
-	    wait(&status);		
-	  }
-	}
-#endif
+	FILE *ipnat = popen("/sbin/ipnat -rf -", "w");
+	sprintf(command, "rdr %s %s/32 port %s -> %s port %s %s\n",
+		g_vars.extInterfaceName, g_vars.extIpAddress, externalPort, internalClient, internalPort, protocol);
+	trace(3, "%s", command);
+	fprintf(ipnat, command);
+	sprintf(command, "rdr lo0 %s/32 port %s -> %s port %s %s\n",
+		g_vars.extIpAddress, externalPort, internalClient, internalPort, protocol);
+	trace(3, "%s", command);
+	fprintf(ipnat, command);
+	pclose(ipnat);
     }
     return 1;
 }
