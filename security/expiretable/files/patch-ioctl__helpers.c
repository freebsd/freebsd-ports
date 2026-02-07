--- ioctl_helpers.c.orig	2021-04-19 18:12:17 UTC
+++ ioctl_helpers.c
@@ -160,46 +160,3 @@ radix_get_tstats(int dev, struct pfr_tstats **tstats, 
 	*tstats = (struct pfr_tstats *)pt.pfrio_buffer;
 	return pt.pfrio_size;
 }
-
-
-int
-get_states(int dev, struct pf_state **states) { 
-	struct pfioc_states ps;
-	caddr_t inbuf, newinbuf;
-	size_t len = 0;
-
-	inbuf = newinbuf = NULL;
-	memset(&ps, 0, sizeof(struct pfioc_states));
-	*states = NULL;	
-	for (;;) {
-		ps.ps_len = len;
-		if (len) {
-			newinbuf = realloc(inbuf, len);
-			if (newinbuf == NULL) {
-				if (inbuf != NULL) {
-					free(inbuf);
-					inbuf = newinbuf = NULL;
-					return (-1);
-				}
-			}
-			ps.ps_buf = inbuf = newinbuf;
-		}
-		if (ioctl(dev, DIOCGETSTATES, &ps) < 0) {
-			if (inbuf != NULL) {
-				free(inbuf);
-				inbuf = newinbuf = NULL;
-			}
-			return (-1);
-		}
-		if (ps.ps_len + sizeof(struct pfioc_states) < len)
-			break; /* We have states! */
-		if (ps.ps_len == 0)
-			return (0); /* No states available */
-		if (len == 0)
-			len = ps.ps_len;
-		len *= 2;
-	}
-		
-	*states = ps.ps_states;
-	return ps.ps_len / sizeof(struct pf_state);
-}
