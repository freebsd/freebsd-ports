--- rtpdump.c.orig	2016-06-20 15:59:04 UTC
+++ rtpdump.c
@@ -441,8 +441,8 @@ static int parse_control(FILE *out, char
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
@@ -458,8 +458,8 @@ static int parse_control(FILE *out, char
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
