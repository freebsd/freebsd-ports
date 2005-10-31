--- doorman-0.81/doormand.c	2005-10-30 14:00:27.000000000 +0100
+++ doormand.c	2005-10-30 14:05:18.000000000 +0100
@@ -387,7 +387,11 @@
     int datalink_header_lengths[] = {
     //    hdr len      code      data link type
     //    -------      --- ---------------------------
+#ifdef __FreeBSD__
+             4,    //   0  no link-layer encapsulation
+#else
              0,    //   0  no link-layer encapsulation
+#endif
             14,    //   1  Ethernet (10Mb)
             -1,    //   2  Experimental Ethernet (3Mb)
             -1,    //   3  Amateur Radio AX.25
@@ -614,6 +618,14 @@
 // more readable.
 //
 
+/*
+// lsof on FreeBSD produces one more field.
+// This should be rewritten to use a regular expression, anyway.
+//
+// And who said using C++ style comments in C was good for portability?!?
+*/
+
+#ifdef __FreeBSD__
 #define LSOF()\
 sprintf (cmd, "lsof -Pn -iTCP@%s:%s", interface_ip_str, dport_string) ;\
 \
@@ -635,6 +647,7 @@
     if ((p1 = token (&p2, " ")) == NULL) continue ;\
     if ((p1 = token (&p2, " ")) == NULL) continue ;\
     if ((p1 = token (&p2, " ")) == NULL) continue ;\
+    if ((p1 = token (&p2, " ")) == NULL) continue ;\
     if ((p1 = token (&p2, " :")) == NULL) continue ;\
     local_ip = inet_addr(p1) ;\
     if ((p1 = token (&p2, "-")) == NULL) continue ;\
@@ -659,7 +672,53 @@
     }\
 }\
 pclose(f) ;
-
+#else
+#define LSOF()\
+sprintf (cmd, "lsof -Pn -iTCP@%s:%s", interface_ip_str, dport_string) ;\
+\
+f = popen (cmd, "r") ;\
+if (f == NULL) {\
+    croak (errno, "Can't execute '%s'; exiting.", cmd) ;\
+}\
+\
+fgets(buffer, 254, f) ;   /* throw away the first line. */ \
+while (fgets(buffer, 254, f)) {\
+    p2 = buffer ;\
+    if ((p1 = token (&p2, " ")) == NULL) continue ;\
+    dname = p1 ;\
+    if ((p1 = token (&p2, " ")) == NULL) continue ;\
+    pid = p1 ;\
+    if ((p1 = token (&p2, " ")) == NULL) continue ;\
+    uname = p1 ;\
+    if ((p1 = token (&p2, " ")) == NULL) continue ;\
+    if ((p1 = token (&p2, " ")) == NULL) continue ;\
+    if ((p1 = token (&p2, " ")) == NULL) continue ;\
+    if ((p1 = token (&p2, " ")) == NULL) continue ;\
+    if ((p1 = token (&p2, " :")) == NULL) continue ;\
+    local_ip = inet_addr(p1) ;\
+    if ((p1 = token (&p2, "-")) == NULL) continue ;\
+    local_port = atoi(p1) ;\
+    if ((p1 = token (&p2, "->:")) == NULL) continue ;\
+    aptr = p1 ;\
+    remote_ip = inet_addr(p1) ;\
+    if ((p1 = token (&p2, " ")) == NULL) continue ;\
+    pptr = p1 ;\
+    remote_port = atoi(p1) ;\
+    if ((p1 = token (&p2, " ()")) == NULL) continue ;\
+    status = p1 ;\
+\
+    if ((saddr == remote_ip) &&\
+        (daddr == local_ip) &&\
+        (sport == remote_port) &&\
+        (dport == local_port) && \
+        (strcmp(status, "ESTABLISHED") == 0))\
+    {\
+        connected = TRUE ;\
+        break ;\
+    }\
+}\
+pclose(f) ;
+#endif
 
 
 
@@ -704,7 +763,11 @@
     snprintf (cmd, 254, "tcp and dst port %s and src %s and dst %s",
               dport_string, src_addr, interface_ip_str) ;
     DEBUG "open a secondary pcap: '%s'", cmd) ;
+#ifdef __FreeBSD__
+    hdr_len = open_a_pcap (device, 1000, &cap, cmd) ;
+#else
     hdr_len = open_a_pcap (device, 0, &cap, cmd) ;
+#endif
 
     // set broad firewall rule
     sprintf (G_fw_broad_rule, " %s %s 0 %s %s",
@@ -716,7 +779,22 @@
 
     for (;;) {
 
+#ifdef __FreeBSD__
+	{
+	    int ret = 0;
+	    struct pcap_pkthdr * packet_hdr_p;
+
+	    while (ret == 0) {
+		ret = pcap_next_ex (cap, &packet_hdr_p, (const u_char **)&p) ;
+		packet_hdr = *packet_hdr_p;
+		if (ret < 0) {
+		    p = NULL;
+		}
+	    }
+	}
+#else
         p = (unsigned char*)pcap_next (cap, &packet_hdr) ;
+#endif
         if (p == NULL) {
             WARNX "manage_firewall got null from 'pcap_next': %s  Exiting.",
                    pcap_geterr(G_cap)) ;
@@ -1300,9 +1378,13 @@
         croak (errno, "Can't get interface address of %s", device) ;
     }
 
+#ifdef __FreeBSD__
+    hdr_len = open_a_pcap (device, 1000, &G_cap, "udp and port %d and dst %s",
+                           port, interface_ip) ;
+#else
     hdr_len = open_a_pcap (device, 0, &G_cap, "udp and port %d and dst %s",
                            port, interface_ip) ;
-
+#endif
     if (G_reconfigure) {
         G_reconfigure = FALSE ;
         NOTICE "reconfigured.") ;
@@ -1330,9 +1412,22 @@
         char            src_addr_buff[16] ;
 
         errno = 0 ;
-        netdown_count = 0 ;
-
+#ifdef __FreeBSD__
+	{
+	    int ret = 0;
+	    struct pcap_pkthdr * packet_hdr_p;
+
+	    while (ret == 0) {
+		ret = pcap_next_ex (G_cap, &packet_hdr_p, (const u_char **)&p) ;
+		packet_hdr = *packet_hdr_p;
+		if (ret < 0) {
+		    p = NULL;
+		}
+	    }
+	}
+#else
         p = (unsigned char *)pcap_next (G_cap, &packet_hdr) ;
+#endif
         if (G_reconfigure) {
             if (daemonize) err_closelog() ;
             goto reconfigure ;
