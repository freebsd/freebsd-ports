X-Git-Url: http://git.haproxy.org/?p=haproxy.git;a=blobdiff_plain;f=src%2Fhaproxy.c;h=30e850c4ac4719b71adccb3b6bd41248ef5bb470;hp=7af4ab479c761a43b2fa64d2124388dbf5c21fc3;hb=97148f60b8feec39b76768d1bcfab6d755c12164;hpb=0d00593361b91017b894c4c7d5e24721a7838d6e

--- src/haproxy.c.orig	2018-02-05 02:24:58 UTC
+++ src/haproxy.c
@@ -2031,7 +2031,18 @@ int main(int argc, char **argv)
 		    proc < LONGBITS &&       /* only the first 32/64 processes may be pinned */
 		    global.cpu_map[proc])    /* only do this if the process has a CPU map */
 #ifdef __FreeBSD__
-			cpuset_setaffinity(CPU_LEVEL_WHICH, CPU_WHICH_PID, -1, sizeof(unsigned long), (void *)&global.cpu_map[proc]);
+		{
+			cpuset_t cpuset;
+			int i;
+			unsigned long cpu_map = global.cpu_map[proc];
+
+			CPU_ZERO(&cpuset);
+			while ((i = ffsl(cpu_map)) > 0) {
+				CPU_SET(i - 1, &cpuset);
+				cpu_map &= ~(1 << (i - 1));
+			}
+			ret = cpuset_setaffinity(CPU_LEVEL_WHICH, CPU_WHICH_PID, -1, sizeof(cpuset), &cpuset);
+		}
 #else
 			sched_setaffinity(0, sizeof(unsigned long), (void *)&global.cpu_map[proc]);
 #endif
