--- rays-filter.c.orig	Thu Mar  8 13:41:20 2001
+++ rays-filter.c	Wed Oct 27 15:38:15 2004
@@ -65,8 +65,8 @@
 #include <sys/types.h>
 #include <unistd.h>
 #include <regex.h>
+#include <sysexits.h>
 #include "libmilter/mfapi.h" 
-#include "libmilter/milter.h"
 #include "rays-filter.h"
 
 
@@ -219,8 +219,10 @@
 #ifndef TRUE
 #define FALSE  0
 #define TRUE   1
+#ifndef __bool_true_false_are_defined
 typedef int bool;
 #endif
+#endif
 
 /* Data Structures
 **
@@ -326,6 +328,7 @@
       syslog(LOG_INFO, "Cannot allocate memory for log file name\n");
    else
    {
+#if 0
       if (mktemp(priv->mlfi_fname) == NULL)
          syslog(LOG_INFO, "Cannot make name for log file\n");
       else
@@ -334,6 +337,11 @@
          if (priv->mlfi_fname == NULL)
             syslog(LOG_INFO, "Cannot open log file\n");
       }
+#else
+      priv->mlfi_fp = mkstemp(priv->mlfi_fname);
+      if ( priv->mlfi_fp < 0 )
+         syslog(LOG_INFO, "Cannot open new log file\n");
+#endif
    }
    
    return 0;
