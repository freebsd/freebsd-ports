--- ./scheduler/dirsvc.c.orig	2014-03-05 16:11:32.000000000 -0500
+++ ./scheduler/dirsvc.c	2014-06-30 11:02:48.000000000 -0400
@@ -237,11 +237,13 @@
   if (BrowseLocalProtocols & BROWSE_SMB)
     update_smb(1);
 
+#if defined(HAVE_DNSSD) || defined(HAVE_AVAHI)
  /*
   * Register the individual printers
   */
 
   dnssdRegisterAllPrinters(0);
+#endif /* HAVE_DNSSD || HAVE_AVAHI */
 }
 
 
@@ -255,6 +257,7 @@
   if (!Browsing || !BrowseLocalProtocols)
     return;
 
+#if defined(HAVE_DNSSD) || defined(HAVE_AVAHI)
  /*
   * De-register the individual printers
   */
@@ -265,7 +268,6 @@
   * Shut down browsing sockets...
   */
 
-#if defined(HAVE_DNSSD) || defined(HAVE_AVAHI)
   if ((BrowseLocalProtocols & BROWSE_DNSSD) && DNSSDMaster)
     dnssdStop();
 #endif /* HAVE_DNSSD || HAVE_AVAHI */
@@ -1548,7 +1550,7 @@
       if (i)
 	*bufptr++ = ',';
 
-      strlcpy(bufptr, p->auth_info_required[i], bufsize - (bufptr - buffer));
+      strlcpy(bufptr, p->auth_info_required[i], bufsize - (size_t)(bufptr - buffer));
       bufptr += strlen(bufptr);
     }
 
