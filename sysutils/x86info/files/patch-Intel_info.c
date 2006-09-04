--- Intel/info.c.orig	Thu Aug 24 01:24:35 2006
+++ Intel/info.c	Thu Aug 24 01:25:13 2006
@@ -35,7 +35,7 @@
 	if (show_msr) {
 		if (cpu->family==0xf)
 			dump_p4_MSRs(cpu);
-		if (cpu->family==0x6 && cpu->model==9)
+		if (cpu->family==0x6 && (cpu->model == 9 || cpu->model == 13))
 			dump_centrino_MSRs(cpu);
 	}
 
