--- ./grok_discover.c.orig	2013-10-10 13:26:22.000000000 -0400
+++ ./grok_discover.c	2013-10-10 13:27:24.000000000 -0400
@@ -187,6 +187,9 @@
       if (first_match_endpos > 0) {
         offset += first_match_endpos;
       }
+      else {
+        offset += 1;
+      }
     } else { /* We found a match, replace it in the pattern */
       grok_log(gdt, LOG_DISCOVER, "%d: Matched %s on '%.*s'",
                rounds, best_match.grok->pattern,
