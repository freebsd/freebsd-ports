--- loader/win32.c.orig	Sun Apr  6 01:29:17 2003
+++ loader/win32.c	Sun Apr  6 01:29:30 2003
@@ -931,6 +931,8 @@
 
 	    switch(gCpuCaps.cpuType)
 	    {
+		case CPUTYPE_I686_8:
+		case CPUTYPE_I686_7:
 		case CPUTYPE_I686:
 		case CPUTYPE_I586:
 		    cachedsi.dwProcessorType = PROCESSOR_INTEL_PENTIUM;
