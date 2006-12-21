
$FreeBSD$

--- ndpmon.c.orig
+++ ndpmon.c
@@ -43,10 +43,10 @@
 char admin_mail[128] = "";
 char syslog_facility[16] = "";
 int ignor_autoconf = 0;
-char config_path[128] = "/usr/local/ndpmon/config_ndpmon.xml";
-char cache_path[128] = "/usr/local/ndpmon/neighbor_list.xml";
-char dtd_path[128] = "/usr/local/ndpmon/neighbor_list.dtd";
-char dtd_config_path[128] = "/usr/local/ndpmon/config_ndpmon.dtd";
+char config_path[128] = "%%PREFIX%%/etc/config_ndpmon.xml";
+char cache_path[128] = "%%PREFIX%%/var/ndpmon_neighbor_list.xml";
+char dtd_path[128] = "%%PREFIX%%/share/ndpmon/neighbor_list.dtd";
+char dtd_config_path[128] = "%%PREFIX%%/share/ndpmon/config_ndpmon.dtd";
 
 #ifdef _MACRESOLUTION_
 manufacturer_t *manuf = NULL;
@@ -438,7 +438,7 @@
 
 
 	/* open device for reading */
-	descr = pcap_open_live(interface,BUFSIZ,1,-1,errbuf);
+	descr = pcap_open_live(interface,BUFSIZ,1,1000,errbuf);
 	if(descr == NULL)
 	{
 		fprintf(stderr,"pcap_open_live(): %s\n",errbuf); exit(1);
