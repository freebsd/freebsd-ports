--- common/jk_status.c.ori	2014-02-07 14:08:44.000000000 -0700
+++ common/jk_status.c	2014-02-07 14:09:05.000000000 -0700
@@ -3647,7 +3647,7 @@
                 }
             }
             if (sync_needed == JK_TRUE) {
-                wr->sequence = 0;
+                wr->sequence = -1;
                 if (!rc)
                     rc = 3;
             }
