--- a/scanner.c
+++ b/scanner.c
@@ -633,7 +633,7 @@ void cScanner::Action(void) {
          else
            continue;
          cCondWait::SleepMs(2000);
-         vbiSupport = vcap.capabilities & (V4L2_CAP_VBI_CAPTURE || V4L2_CAP_SLICED_VBI_CAPTURE);
+         vbiSupport = vcap.capabilities & (V4L2_CAP_VBI_CAPTURE | V4L2_CAP_SLICED_VBI_CAPTURE);
          if (vbiSupport)
            dlog(1, "device can capture vbi");
          }
