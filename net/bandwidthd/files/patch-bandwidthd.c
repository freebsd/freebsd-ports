--- bandwidthd.c.orig	Fri Oct 10 20:22:39 2003
+++ bandwidthd.c	Sun Nov  2 12:21:17 2003
@@ -114,7 +114,11 @@
 			}
 		else
 			{
+#ifndef FREEBSD
 			printf("My shared memory segment %d is already in use (%ld locks), perhaps bandwidthd is already running in this directory?\n", shmid, shmstatus.shm_nattch);
+#else
+			printf("My shared memory segment %d is already in use (%hd locks), perhaps bandwidthd is already running in this directory?\n", shmid, shmstatus.shm_nattch);
+#endif
 			exit(1);
 			}
 		}
@@ -244,7 +248,7 @@
             tcp = (struct tcphdr *)(ip+1);
 			tcp = (struct tcphdr *) ( ((char *)tcp) + ((ip->ip_hl-5)*4) ); // Compensate for IP Options
             Stats->tcp += size;
-#ifdef SOLARIS
+#if defined(SOLARIS) || defined(FREEBSD)
             sport = ntohs(tcp->th_sport);
             dport = ntohs(tcp->th_dport);			
 #else
