--- panel-plugin/battery.c.orgi	2008-09-04 22:53:40.000000000 +0200
+++ panel-plugin/battery.c	2008-09-05 10:02:08.000000000 +0200
@@ -163,7 +163,9 @@
      except that is does not work on FreeBSD
 
   */
+#ifdef APMDEVICE
     struct apm_info apm;
+#endif
       int fd;
 
     /* First check to see if ACPI is available */
@@ -310,7 +312,9 @@
       acline = apm.ac_state ? TRUE : FALSE;
 
 #else
-    struct apm_info apm;
+#ifdef APMDEVICE    
+struct apm_info apm;
+#endif
     DBG ("Updating battery status...");
 
     if(battmon->method == BM_BROKEN) {
@@ -382,6 +386,7 @@
           rate = last_rate;
         }
 
+#ifdef __linux__
         charge = (((float)ccapacity)/((float)lcapacity))*100;
 
         if ( last_acline )
@@ -394,6 +399,17 @@
 
         last_acline = acline;
 
+#elif __FreeBSD__
+	charge = acpistate->percentage;
+	
+	if ( last_acline)
+	    time_remaining = acpistate->rtime;
+	else
+	    time_remaining = acpistate->rtime;
+
+	if ( time_remaining < 0 )
+	    time_remaining = 0;
+#endif
     }
 #ifdef __linux__
     else {
