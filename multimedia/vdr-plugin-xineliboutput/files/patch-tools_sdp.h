--- a/tools/sdp.h.orig	2012-05-11 07:37:27 UTC
+++ b/tools/sdp.h
@@ -54,7 +54,7 @@ static const char *vdr_sdp_description(c
   s_data = cString::sprintf(
            /*** session ***/
            /* version    */        "v=0"
-           /* origin     */ "\r\n" "o=%s %u %"PRIu64" IN IP4 %s"
+           /* origin     */ "\r\n" "o=%s %u %" PRIu64 " IN IP4 %s"
            /* name       */ "\r\n" "s=%s@%s (multicast %s:%d)"
            /* opt:info   */ /*"\r\n" "i=vdr-xineliboutput primary device output"*/
            /* time       */ "\r\n" "t=0 0"
