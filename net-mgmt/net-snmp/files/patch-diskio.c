--- ./agent/mibgroup/ucd-snmp/diskio.c.orig	Mon Jan 24 23:35:53 2005
+++ ./agent/mibgroup/ucd-snmp/diskio.c	Mon Jan 24 23:37:24 2005
@@ -458,8 +458,8 @@
 		    ERROR_MSG("Memory alloc failure - devla_getstats()\n");
 		    return;
 	    }
+	    memset(lastat->dinfo, 0, sizeof(struct devinfo));
 	}
-	memset(lastat->dinfo, 0, sizeof(struct devinfo));
 
         if ((GETDEVS(lastat)) == -1) {
                 ERROR_MSG("can't do getdevs()\n");
