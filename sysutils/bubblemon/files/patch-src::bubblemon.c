$FreeBSD$

--- src/bubblemon.c.orig	Sun Oct 27 07:45:31 2002
+++ src/bubblemon.c	Wed Jun 18 03:35:13 2003
@@ -169,7 +169,7 @@ const char *bubblemon_getTooltip(void)
   if (sysload.swapSize > 0)
   {
     usage2string(swapstring, sysload.swapUsed, sysload.swapSize);
-    snprintf(loadstring, 90,
+    snprintf(loadstring, sizeof loadstring,
 	     _("\nSwap used: %s"),
 	     swapstring);
     strcat(tooltipstring, loadstring);
@@ -177,7 +177,7 @@ const char *bubblemon_getTooltip(void)
 
   if (sysload.nCpus == 1)
     {
-      snprintf(loadstring, 45,
+      snprintf(loadstring, sizeof loadstring,
                _("\nCPU load: %d%%"),
                bubblemon_getCpuLoadPercentage(0));
       strcat(tooltipstring, loadstring);
@@ -188,7 +188,7 @@ const char *bubblemon_getTooltip(void)
            cpu_number < sysload.nCpus;
            cpu_number++)
         {
-          snprintf(loadstring, 45,
+          snprintf(loadstring, sizeof loadstring,
                    _("\nCPU #%d load: %d%%"),
                    cpu_number,
                    bubblemon_getCpuLoadPercentage(cpu_number));
