--- nmicmpd.c.orig      Tue Feb  6 15:34:03 2001
+++ nmicmpd.c   Tue Feb  6 15:44:53 2001
@@ -924,6 +924,14 @@
     
     if (rc != size) {
	if (rc < 0) {
+ 	  /*
+ 	   *  If we get an EHOSTDOWN error, this probably means that
+ 	   *  the the pending ARP entry has timed out for the host.
+ 	   *  Just ignore the error, and attempt a normal retry.
+ 	   */
+ 	  if (errno == EHOSTDOWN)
+ 	    return 0;
+ 
	    PosixError("sendto failed");
        }
        job->status = ICMP_STATUS_GENERROR;
