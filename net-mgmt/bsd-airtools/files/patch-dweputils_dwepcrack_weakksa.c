
$FreeBSD$

--- dweputils/dwepcrack/weakksa.c.orig	Sun Aug 22 21:34:55 2004
+++ dweputils/dwepcrack/weakksa.c	Sun Aug 22 21:35:13 2004
@@ -168,8 +168,8 @@
           memcpy(samples[B].s[samples[B].len].iv, iv, IV_SIZE);
           samples[B].s[samples[B].len++].byte = iv[4] ^ 0xaa;
 
-          fail:
-        }
+          fail: break;
+	}
       }
     }
   }
