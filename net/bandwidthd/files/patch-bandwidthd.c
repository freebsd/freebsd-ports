--- bandwidthd.c.orig	Mon Nov 10 17:16:04 2003
+++ bandwidthd.c	Tue Nov 11 13:52:27 2003
@@ -129,7 +129,11 @@
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
@@ -264,7 +268,7 @@
             tcp = (struct tcphdr *)(ip+1);
 			tcp = (struct tcphdr *) ( ((char *)tcp) + ((ip->ip_hl-5)*4) ); // Compensate for IP Options
             Stats->tcp += size;
-#if defined(SOLARIS)
+#if defined(SOLARIS) || defined (FREEBSD)
             sport = ntohs(tcp->th_sport);
             dport = ntohs(tcp->th_dport);			
 #else
