--- crypto/evp/openbsd_hw.c.orig	2015-03-19 13:19:00 UTC
+++ crypto/evp/openbsd_hw.c
@@ -108,7 +108,10 @@ static int dev_crypto_init(session_op *s
             dev_failed = 1;
             return 0;
         }
-        close(cryptodev_fd);
+        if (fd == -1)
+            fd = cryptodev_fd;
+        else
+            close(cryptodev_fd);
     }
     assert(ses);
     memset(ses, '\0', sizeof *ses);
