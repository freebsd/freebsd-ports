$FreeBSD$

--- src/bubblemon.c.orig	Mon Jul 22 10:19:32 2002
+++ src/bubblemon.c	Sun May  4 16:31:56 2003
@@ -170,7 +170,7 @@
 
   if (sysload.nCpus == 1)
     {
-      snprintf(loadstring, 45,
+      snprintf(loadstring, sizeof loadstring,
                _("\nCPU load: %d%%"),
                bubblemon_getCpuLoadPercentage(0));
       strcat(tooltipstring, loadstring);
@@ -181,7 +181,7 @@
            cpu_number < sysload.nCpus;
            cpu_number++)
         {
-          snprintf(loadstring, 45,
+          snprintf(loadstring, sizeof loadstring,
                    _("\nCPU #%d load: %d%%"),
                    cpu_number,
                    bubblemon_getCpuLoadPercentage(cpu_number));
