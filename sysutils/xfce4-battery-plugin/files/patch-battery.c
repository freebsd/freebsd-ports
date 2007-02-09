--- panel-plugin/battery.c.orig	Wed Jan 24 20:42:09 2007
+++ panel-plugin/battery.c	Wed Jan 24 20:46:51 2007
@@ -378,6 +378,7 @@
           rate = last_rate;
         }
         
+#ifdef __linux__	
         charge = (((float)ccapacity)/((float)lcapacity))*100;
 
         if ( last_acline )
@@ -389,6 +390,20 @@
             time_remaining = 0;
         
         last_acline = acline;
+
+#elif __FreeBSD__
+	charge = acpistate->percentage;
+
+	if ( last_acline )
+	    time_remaining = acpistate->rtime;
+	else
+	    time_remaining = acpistate->rtime;
+
+	if ( time_remaining < 0 )
+	    time_remaining = 0;
+
+	last_acline = acline;
+#endif
 
     }    
 #ifdef __linux__
