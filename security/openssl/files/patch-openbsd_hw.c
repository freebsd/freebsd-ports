Index: crypto/evp/openbsd_hw.c
===================================================================
RCS file: /home/ncvs/src/crypto/openssl/crypto/evp/openbsd_hw.c,v
retrieving revision 1.1.1.1
diff -u -r1.1.1.1 openbsd_hw.c
--- crypto/evp/openbsd_hw.c	28 Jan 2003 21:24:39 -0000	1.1.1.1
+++ crypto/evp/openbsd_hw.c	18 Jan 2005 12:26:45 -0000
@@ -109,7 +109,10 @@
 	    dev_failed=1;
 	    return 0;
 	    }
-	close(cryptodev_fd);
+	if (fd == -1)
+		fd = cryptodev_fd;
+	else
+		close(cryptodev_fd);
 	}
     assert(ses);
     memset(ses,'\0',sizeof *ses);
