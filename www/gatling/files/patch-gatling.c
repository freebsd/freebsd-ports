! Fix a filedescriptor leak. This change requires libowfat-0.18
! Obtained from gatling cvs
--- gatling.c.orig	Fri Feb 27 16:09:53 2004
+++ gatling.c	Fri Feb 27 16:13:28 2004
@@ -876,7 +876,7 @@
 	  c+=fmt_str(c,"\r\n\r\n");
 	  iob_addbuf_free(&h->iob,h->hdrbuf,c - h->hdrbuf);
 	  if (!head)
-	    iob_addfile(&h->iob,fd,range_first,range_last-range_first);
+	    iob_addfile_close(&h->iob,fd,range_first,range_last-range_first);
 	  if (logging) {
 	    if (h->hdrbuf[9]=='3') {
 	      buffer_puts(buffer_1,head?"HEAD/304 ":"GET/304 ");
@@ -1034,7 +1034,7 @@
       range_last=ss.st_size;
     range_first=h->ftp_rest; h->ftp_rest=0;
     if (range_first>range_last) range_first=range_last;
-    iob_addfile(&b->iob,b->filefd,range_first,range_last-range_first);
+    iob_addfile_close(&b->iob,b->filefd,range_first,range_last-range_first);
     if (logging) {
       buffer_putulonglong(buffer_1,range_last-range_first);
       buffer_putspace(buffer_1);
