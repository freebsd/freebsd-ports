--- rays-filter.c.orig	Thu Mar  8 13:41:20 2001
+++ rays-filter.c	Sat Jan 19 15:49:11 2002
@@ -65,8 +65,8 @@
 #include <sys/types.h>
 #include <unistd.h>
 #include <regex.h>
+#include <sysexits.h>
 #include "libmilter/mfapi.h" 
-#include "libmilter/milter.h"
 #include "rays-filter.h"
 
 
@@ -326,6 +326,7 @@
       syslog(LOG_INFO, "Cannot allocate memory for log file name\n");
    else
    {
+#if 0
       if (mktemp(priv->mlfi_fname) == NULL)
          syslog(LOG_INFO, "Cannot make name for log file\n");
       else
@@ -334,6 +335,11 @@
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
