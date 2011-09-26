--- ./src/knockd.c.orig	2005-06-27 07:11:34.000000000 +0200
+++ ./src/knockd.c	2011-08-17 13:24:16.000000000 +0200
@@ -1,8 +1,8 @@
 /*
  *  knockd.c
- * 
+ *
  *  Copyright (c) 2004-2005 by Judd Vinet <jvinet@zeroflux.org>
- * 
+ *
  *  This program is free software; you can redistribute it and/or modify
  *  it under the terms of the GNU General Public License as published by
  *  the Free Software Foundation; either version 2 of the License, or
@@ -15,7 +15,7 @@
  *
  *  You should have received a copy of the GNU General Public License
  *  along with this program; if not, write to the Free Software
- *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, 
+ *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307,
  *  USA.
  */
 
@@ -28,6 +28,11 @@
 #include <ctype.h>
 #include <string.h>
 #include <fcntl.h>
+#if defined(__FreeBSD__) || defined(__APPLE__)
+#include <limits.h>
+#include <sys/socket.h>
+#include <netinet/in_systm.h>
+#endif
 #include <netinet/in.h>
 #include <netinet/if_ether.h>
 #include <netinet/ip.h>
@@ -35,8 +40,9 @@
 #include <netinet/udp.h>
 #include <netinet/ip_icmp.h>
 #include <net/if.h>
+#if !defined(__FreeBSD__) && !defined(__APPLE__)
 #include <bits/time.h>
-#include <sys/socket.h>
+#endif
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <sys/ioctl.h>
@@ -48,7 +54,7 @@
 #include <errno.h>
 #include "list.h"
 
-static char version[] = "0.5";
+static char version[] = "#VERSION#";
 
 #define SEQ_TIMEOUT 25 /* default knock timeout in seconds */
 #define CMD_TIMEOUT 10 /* default timeout in seconds between start and stop commands */
@@ -131,7 +137,7 @@
 int  o_daemon    = 0;
 int  o_lookup    = 0;
 char o_int[32]           = "";		/* default (eth0) is set after parseconfig() */
-char o_cfg[PATH_MAX]     = "/etc/knockd.conf";
+char o_cfg[PATH_MAX]     = "%%PREFIX%%/etc/knockd.conf";
 char o_pidfile[PATH_MAX] = "/var/run/knockd.pid";
 char o_logfile[PATH_MAX] = "";
 
@@ -193,7 +199,11 @@
 		}
 	}
 
+#if defined(__FreeBSD__) || defined(__APPLE__)
+	cap = pcap_open_live(o_int, 65535, 0, 1, pcapErr);
+#else
 	cap = pcap_open_live(o_int, 65535, 0, 0, pcapErr);
+#endif
 	if(strlen(pcapErr)) {
 		fprintf(stderr, "could not open %s: %s\n", o_int, pcapErr);
 	}
@@ -212,7 +222,10 @@
 		case DLT_RAW:
 			dprint("raw interface detected, no encapsulation\n");
 			break;
-		default: 
+		case DLT_NULL:
+			dprint("tun interface detected. pppoe on freebsd\n");
+			break;
+		default:
 			fprintf(stderr, "error: unsupported link-layer type: %d\n", lltype);
 			cleanup(1);
 			break;
@@ -301,9 +314,9 @@
 		struct tm *tm;
 		t = time(NULL);
 		tm = localtime(&t);
-		
-		fprintf(logfd, "[%04d-%02d-%02d %02d:%02d] %s\n", tm->tm_year+1900,
-			tm->tm_mon+1, tm->tm_mday, tm->tm_hour, tm->tm_min, msg);
+
+		fprintf(logfd, "[%04d-%02d-%02d %02d:%02d:%02d] %s\n", tm->tm_year+1900,
+			tm->tm_mon+1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec, msg);
 		fflush(logfd);
 	}
 }
@@ -420,7 +433,7 @@
 	if(pch != str) {
 		memmove(str, pch, (strlen(pch) + 1));
 	}
-	
+
 	pch = (char*)(str + (strlen(str) - 1));
 	while(isspace(*pch)) {
 		pch--;
@@ -503,7 +516,7 @@
 					dprint("config: usesyslog\n");
 				} else {
 					fprintf(stderr, "config: line %d: syntax error\n", linenum);
-					return(1);			
+					return(1);
 				}
 			} else {
 				trim(ptr);
@@ -681,7 +694,7 @@
 		return(1);
 	}
 	dprint_sequence(door, "new sequence for door %s: ", door->name);
-	
+
 	return(0);
 }
 
@@ -694,7 +707,7 @@
 {
 	char line[PATH_MAX+1];
 	int pos;
-	
+
 	pos = ftell(door->one_time_sequences_fd);
 	while(fgets(line, PATH_MAX, door->one_time_sequences_fd)) {
 		trim(line);
@@ -746,7 +759,7 @@
 
 	rewind(door->one_time_sequences_fd);
 	pseudo_door.one_time_sequences_fd = door->one_time_sequences_fd;
-	
+
 	pos = get_next_one_time_sequence(&pseudo_door);
 	while(pos >= 0) {
 		if(door->seqcount == pseudo_door.seqcount) {
@@ -769,10 +782,10 @@
 void generate_pcap_filter()
 {
 	/* NOTE: We're doing string manipulations in a daemon -- use defensive programming! */
-		
+
 	PMList *lp;
 	opendoor_t *door;
-	char *buffer = NULL;			/* temporary buffer to create the individual filter strings */ 
+	char *buffer = NULL;			/* temporary buffer to create the individual filter strings */
 	size_t bufsize = 0;			/* size of buffer */
 	char port_str[10];			/* used by snprintf to convert unsigned short --> string */
 	short head_set = 0;			/* flag indicating if protocol head is set (i.e. "((tcp dst port") */
@@ -781,7 +794,7 @@
 	unsigned int i;
 	short modified_filters = 0;		/* flag indicating if at least one filter has changed --> recompile the filter */
 	struct bpf_program bpf_prog;		/* compiled BPF filter program */
-	
+
 	/* generate subfilters for each door having a NULL pcap_filter_exp
 	 *
 	 * Example filter for one single door:
@@ -796,11 +809,11 @@
 
 		/* if we get here at least one door had a pcap_filter_exp == NULL */
 		modified_filters = 1;
-		
+
 		head_set = 0;
 		tcp_present = 0;
 		udp_present = 0;
-		
+
 		/* allocate memory for buffer if needed.
 		 * The first allocation will be 200 Bytes (should be large enough for common sequences). If there is
 		 * not enough space, a call to realloc_strcat() will eventually increase its size. The buffer will be
@@ -913,7 +926,7 @@
 		if(udp_present) {
 			bufsize = realloc_strcat(&buffer, ")", bufsize);		/* close parentheses of UDP ports */
 		}
-		
+
 		/* test if in any of the precedent calls to realloc_strcat() failed. We can do this safely here because
 		 * realloc_strcat() returns 0 on failure and if a buffer size of 0 is passed to it, the function does
 		 * nothing but returning 0 again. Because we never read buffer in the above code, it is secure to test
@@ -930,7 +943,7 @@
 			perror("malloc");
 			cleanup(1);
 		}
-		strcpy(door->pcap_filter_exp, buffer);	
+		strcpy(door->pcap_filter_exp, buffer);
 
 		buffer[0] = '\0';	/* "clear" the buffer */
 	}
@@ -941,7 +954,7 @@
 	 * Note that we don't check if a port is included in multiple doors, we simply concatenate the individual door
 	 * filters and rely on pcap's optimization capabilities.
 	 *
-	 * Example filter for two doors with sequences 8000:tcp,4000:udp,8001:tcp,4001:udp,8002:tcp (syn) and 
+	 * Example filter for two doors with sequences 8000:tcp,4000:udp,8001:tcp,4001:udp,8002:tcp (syn) and
 	 * 1234:tcp,4567:tcp,8901:tcp (syn,ack) :
 	 * dst host the.hosts.ip.address and (
 	 *      ((tcp dst port 8000 or 8001 or 8002) and tcp[tcpflags] & tcp-syn != 0) or (udp dst port 4000 or 4001)
@@ -1005,7 +1018,7 @@
 
 	needed_size = strlen(*dest) + strlen(src) + 1;		/* '+ 1' for '\0' */
 	new_size = size;
-	
+
 	while(needed_size > new_size) {
 		new_size *= 2;
 	}
@@ -1018,7 +1031,7 @@
 
 	/* now dest is large enough to strcat() the src */
 	strcat(*dest, src);
-	
+
 	return new_size;
 }
 
@@ -1059,7 +1072,11 @@
 	}
 	buf[0] = '\0';
 
+#if defined(__FreeBSD__) || defined(__APPLE__)
 	s = socket(AF_INET, SOCK_DGRAM, 0);
+#else
+	s = socket(PF_PACKET, SOCK_DGRAM, 0);
+#endif
 	if(s < 0) {
 		return(NULL);
 	}
@@ -1161,12 +1178,17 @@
 void sniff(u_char* arg, const struct pcap_pkthdr* hdr, const u_char* packet)
 {
 	/* packet structs */
+#if defined(__FreeBSD__) || defined(__APPLE__)
+	struct ether_header* eth = NULL;
+	struct ip* ip = NULL;
+#else
 	struct ethhdr* eth = NULL;
 	struct iphdr* ip   = NULL;
+#endif
 	struct tcphdr* tcp = NULL;
 	struct udphdr* udp = NULL;
 	char proto[8];
-	/* TCP/IP data */	
+	/* TCP/IP data */
 	struct in_addr inaddr;
 	unsigned short sport, dport;
 	char srcIP[16], dstIP[16];
@@ -1179,23 +1201,46 @@
 	knocker_t *attempt = NULL;
 
 	if(lltype == DLT_EN10MB) {
+#if defined(__FreeBSD__) || defined(__APPLE__)
+		eth = (struct ether_header*)packet;
+		if(ntohs(eth->ether_type) != ETHERTYPE_IP) {
+			return;
+		}
+
+		ip = (struct ip*)(packet + sizeof(struct ether_header));
+	} else if(lltype == DLT_LINUX_SLL) {
+		ip = (struct ip*)((u_char*)packet + 16);
+	} else if(lltype == DLT_RAW) {
+		ip = (struct ip*)((u_char*)packet);
+	} else if(lltype == DLT_NULL) {
+		ip = (struct ip*)((u_char*)packet + 4);
+	}
+
+	if(ip->ip_v != 4) {
+#else
 		eth = (struct ethhdr*)packet;
 		if(ntohs(eth->h_proto) != ETH_P_IP) {
 			return;
 		}
+
 		ip = (struct iphdr*)(packet + sizeof(struct ethhdr));
 	} else if(lltype == DLT_LINUX_SLL) {
 		ip = (struct iphdr*)((u_char*)packet + 16);
 	} else if(lltype == DLT_RAW) {
 		ip = (struct iphdr*)((u_char*)packet);
 	}
-	
+
 	if(ip->version != 4) {
+#endif
 		/* no IPv6 yet */
 		dprint("packet is not IPv4, ignoring...\n");
 		return;
 	}
+#if defined(__FreeBSD__) || defined(__APPLE__)
+	if(ip->ip_p == IPPROTO_ICMP) {
+#else
 	if(ip->protocol == IPPROTO_ICMP) {
+#endif
 		/* we don't do ICMP */
 		return;
 	}
@@ -1207,12 +1252,30 @@
 		fprintf(stderr, "error: could not understand IP address: %s\n", myip);
 		return;
 	}
+#if defined(__FreeBSD__) || defined(__APPLE__)
+	if(ip->ip_dst.s_addr != inaddr.s_addr) {
+#else
 	if(ip->daddr != inaddr.s_addr) {
+#endif
 		dprint("packet destined for another host, ignoring...\n");
 		return;
 	}
-	
+
 	sport = dport = 0;
+
+#if defined(__FreeBSD__) || defined(__APPLE__)
+	if(ip->ip_p == IPPROTO_TCP) {
+		strncpy(proto, "tcp", sizeof(proto));
+		tcp = (struct tcphdr*)((u_char*)ip + (ip->ip_hl *4));
+		sport = ntohs(tcp->th_sport);
+		dport = ntohs(tcp->th_dport);
+	}
+	if(ip->ip_p == IPPROTO_UDP) {
+		strncpy(proto, "udp", sizeof(proto));
+		udp = (struct udphdr*)((u_char*)ip + (ip->ip_hl * 4));
+		sport = ntohs(udp->uh_sport);
+		dport = ntohs(udp->uh_dport);
+#else
 	if(ip->protocol == IPPROTO_TCP) {
 		strncpy(proto, "tcp", sizeof(proto));
 		tcp = (struct tcphdr*)((u_char*)ip + (ip->ihl * 4));
@@ -1224,6 +1287,7 @@
 		udp = (struct udphdr*)((u_char*)ip + (ip->ihl * 4));
 		sport = ntohs(udp->source);
 		dport = ntohs(udp->dest);
+#endif
 	}
 
 	/* get the date/time */
@@ -1234,10 +1298,17 @@
 			pkt_tm->tm_sec);
 
 	/* convert IPs from binary to string */
+#if defined(__FreeBSD__) || defined(__APPLE__)
+	inaddr.s_addr = ip->ip_src.s_addr;
+	strncpy(srcIP, inet_ntoa(inaddr), sizeof(srcIP)-1);
+	srcIP[sizeof(srcIP)-1] = '\0';
+	inaddr.s_addr = ip->ip_dst.s_addr;
+#else
 	inaddr.s_addr = ip->saddr;
 	strncpy(srcIP, inet_ntoa(inaddr), sizeof(srcIP)-1);
 	srcIP[sizeof(srcIP)-1] = '\0';
 	inaddr.s_addr = ip->daddr;
+#endif
 	strncpy(dstIP, inet_ntoa(inaddr), sizeof(dstIP)-1);
 	dstIP[sizeof(dstIP)-1] = '\0';
 
@@ -1297,6 +1368,73 @@
 		/* if tcp, check the flags to ignore the packets we don't want
 		 * (don't even use it to cancel sequences)
 		 */
+#if defined(__FreeBSD__) || defined(__APPLE__)
+		if(ip->ip_p == IPPROTO_TCP) {
+			if(attempt->door->flag_fin != DONT_CARE) {
+				if(attempt->door->flag_fin == SET && !(tcp->th_flags & TH_FIN)) {
+					dprint("packet is not FIN, ignoring...\n");
+					flagsmatch = 0;
+				}
+				if(attempt->door->flag_fin == NOT_SET && (tcp->th_flags & TH_FIN)) {
+					dprint("packet is not !FIN, ignoring...\n");
+					flagsmatch = 0;
+				}
+			}
+			if(attempt->door->flag_syn != DONT_CARE) {
+				if(attempt->door->flag_syn == SET && !(tcp->th_flags & TH_SYN)) {
+					dprint("packet is not SYN, ignoring...\n");
+					flagsmatch = 0;
+				}
+				if(attempt->door->flag_syn == NOT_SET && (tcp->th_flags & TH_SYN)) {
+					dprint("packet is not !SYN, ignoring...\n");
+					flagsmatch = 0;
+				}
+			}
+			if(attempt->door->flag_rst != DONT_CARE) {
+				if(attempt->door->flag_rst == SET && !(tcp->th_flags & TH_RST)) {
+					dprint("packet is not RST, ignoring...\n");
+					flagsmatch = 0;
+				}
+				if(attempt->door->flag_rst == NOT_SET && (tcp->th_flags & TH_RST)) {
+					dprint("packet is not !RST, ignoring...\n");
+					flagsmatch = 0;
+				}
+			}
+			if(attempt->door->flag_psh != DONT_CARE) {
+				if(attempt->door->flag_psh == SET && !(tcp->th_flags & TH_PUSH)) {
+					dprint("packet is not PSH, ignoring...\n");
+					flagsmatch = 0;
+				}
+				if(attempt->door->flag_psh == NOT_SET && (tcp->th_flags & TH_PUSH)) {
+					dprint("packet is not !PSH, ignoring...\n");
+					flagsmatch = 0;
+				}
+			}
+			if(attempt->door->flag_ack != DONT_CARE) {
+				if(attempt->door->flag_ack == SET && !(tcp->th_flags & TH_ACK)) {
+					dprint("packet is not ACK, ignoring...\n");
+					flagsmatch = 0;
+				}
+				if(attempt->door->flag_ack == NOT_SET && !(tcp->th_flags & TH_ACK)) {
+					dprint("packet is not !ACK, ignoring...\n");
+					flagsmatch = 0;
+				}
+			}
+			if(attempt->door->flag_urg != DONT_CARE) {
+				if(attempt->door->flag_urg == SET && !(tcp->th_flags & TH_URG)) {
+					dprint("packet is not URG, ignoring...\n");
+					flagsmatch = 0;
+				}
+				if(attempt->door->flag_urg == NOT_SET && !(tcp->th_flags & TH_URG)) {
+					dprint("packet is not !URG, ignoring...\n");
+					flagsmatch = 0;
+				}
+			}
+		}
+		if(flagsmatch && ip->ip_p == attempt->door->protocol[attempt->stage] &&
+				dport == attempt->door->sequence[attempt->stage]) {
+
+#else
 		if(ip->protocol == IPPROTO_TCP) {
 			if(attempt->door->flag_fin != DONT_CARE) {
 				if(attempt->door->flag_fin == SET && tcp->fin != 1) {
@@ -1361,6 +1499,7 @@
 		}
 		if(flagsmatch && ip->protocol == attempt->door->protocol[attempt->stage] &&
 				dport == attempt->door->sequence[attempt->stage]) {
+#endif
 			/* level up! */
 			attempt->stage++;
 			if(attempt->srchost) {
@@ -1387,7 +1526,7 @@
 						size_t cmd_len = 0;
 
 						setsid();
-						
+
 						/* parse start and stop command and check if the parsed commands fit in the given buffer. Don't
 						 * execute any command if one of them has been truncated */
 						cmd_len = parse_cmd(parsed_start_cmd, sizeof(parsed_start_cmd), attempt->door->start_command, attempt->src);
@@ -1419,7 +1558,7 @@
 							}
 							exec_cmd(parsed_stop_cmd, attempt->door->name);
 						}
-						
+
 						exit(0); /* exit child */
 					}
 				}
@@ -1451,6 +1590,36 @@
 		for(lp = doors; lp; lp = lp->next) {
 			opendoor_t *door = (opendoor_t*)lp->data;
 			/* if we're working with TCP, try to match the flags */
+#if defined(__FreeBSD__) || defined(__APPLE__)
+			if(ip->ip_p == IPPROTO_TCP){
+				if(door->flag_fin != DONT_CARE) {
+					if(door->flag_fin == SET && !(tcp->th_flags & TH_FIN)) {dprint("packet is not FIN, ignoring...\n");continue;}
+					if(door->flag_fin == NOT_SET && (tcp->th_flags & TH_FIN)) {dprint("packet is not !FIN, ignoring...\n");continue;}
+				}
+				if(door->flag_syn != DONT_CARE) {
+					if(door->flag_syn == SET && !(tcp->th_flags & TH_SYN)) {dprint("packet is not SYN, ignoring...\n");continue;}
+					if(door->flag_syn == NOT_SET && (tcp->th_flags & TH_SYN)) {dprint("packet is not !SYN, ignoring...\n");continue;}
+				}
+				if(door->flag_rst != DONT_CARE) {
+					if(door->flag_rst == SET && !(tcp->th_flags & TH_RST)) {dprint("packet is not RST, ignoring...\n");continue;}
+					if(door->flag_rst == NOT_SET && (tcp->th_flags & TH_RST)) {dprint("packet is not !RST, ignoring...\n");continue;}
+				}
+				if(door->flag_psh != DONT_CARE) {
+					if(door->flag_psh == SET && !(tcp->th_flags & TH_PUSH)) {dprint("packet is not PSH, ignoring...\n");continue;}
+					if(door->flag_psh == NOT_SET && (tcp->th_flags & TH_PUSH)) {dprint("packet is not !PSH, ignoring...\n");continue;}
+				}
+				if(door->flag_ack != DONT_CARE) {
+					if(door->flag_ack == SET && !(tcp->th_flags & TH_ACK)) {dprint("packet is not ACK, ignoring...\n");continue;}
+					if(door->flag_ack == NOT_SET && (tcp->th_flags & TH_ACK)) {dprint("packet is not !ACK, ignoring...\n");continue;}
+				}
+				if(door->flag_urg != DONT_CARE) {
+					if(door->flag_urg == SET && !(tcp->th_flags & TH_URG)) {dprint("packet is not URG, ignoring...\n");continue;}
+					if(door->flag_urg == NOT_SET && (tcp->th_flags & TH_URG)) {dprint("packet is not !URG, ignoring...\n");continue;}
+				}
+			}
+
+			if(ip->ip_p == door->protocol[0] && dport == door->sequence[0]) {
+#else
 			if(ip->protocol == IPPROTO_TCP){
 				if(door->flag_fin != DONT_CARE) {
 					if(door->flag_fin == SET && tcp->fin != 1) {dprint("packet is not FIN, ignoring...\n");continue;}
@@ -1479,6 +1648,7 @@
 			}
 
 			if(ip->protocol == door->protocol[0] && dport == door->sequence[0]) {
+#endif
 				struct hostent *he;
 				/* create a new entry */
 				attempt = (knocker_t*)malloc(sizeof(knocker_t));
@@ -1490,7 +1660,11 @@
 				strcpy(attempt->src, srcIP);
 				/* try a reverse lookup if enabled  */
 				if (o_lookup) {
+#if defined(__FreeBSD__) || defined(__APPLE__)
+					inaddr.s_addr = ip->ip_src.s_addr;
+#else
 					inaddr.s_addr = ip->saddr;
+#endif
 					he = gethostbyaddr((void *)&inaddr, sizeof(inaddr), AF_INET);
 					if(he) {
 						attempt->srchost = strdup(he->h_name);
