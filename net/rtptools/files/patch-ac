--- rtpdump.c.orig	Sat Apr  7 08:02:13 2001
+++ rtpdump.c	Sat Apr 21 21:54:10 2001
@@ -429,8 +429,8 @@
         for (i = 0; i < r->common.count; i++) {
           fprintf(out, "  (ssrc=0x%lx fraction=%g lost=%lu last_seq=%lu jit=%lu lsr=%lu dlsr=%lu )\n",
            (unsigned long)ntohl(r->r.sr.rr[i].ssrc),
-           r->r.sr.rr[i].fraction / 256.,
-           (unsigned long)ntohl(r->r.sr.rr[i].lost), /* XXX I'm pretty sure this is wrong */
+           RTCP_FRACTION(ntohl(r->r.sr.rr[i].fraclost)) / 256.,
+           RTCP_LOST(ntohl(r->r.sr.rr[i].fraclost)),
            (unsigned long)ntohl(r->r.sr.rr[i].last_seq),
            (unsigned long)ntohl(r->r.sr.rr[i].jitter),
            (unsigned long)ntohl(r->r.sr.rr[i].lsr),
@@ -446,8 +446,8 @@
         for (i = 0; i < r->common.count; i++) {
           fprintf(out, "  (ssrc=0x%lx fraction=%g lost=%lu last_seq=%lu jit=%lu lsr=%lu dlsr=%lu )\n",
             (unsigned long)ntohl(r->r.rr.rr[i].ssrc),
-            r->r.rr.rr[i].fraction / 256.,
-            (unsigned long)ntohl(r->r.rr.rr[i].lost),
+            RTCP_FRACTION(ntohl(r->r.rr.rr[i].fraclost)) / 256.,
+            RTCP_LOST(ntohl(r->r.rr.rr[i].fraclost)),
             (unsigned long)ntohl(r->r.rr.rr[i].last_seq),
             (unsigned long)ntohl(r->r.rr.rr[i].jitter),
             (unsigned long)ntohl(r->r.rr.rr[i].lsr),
