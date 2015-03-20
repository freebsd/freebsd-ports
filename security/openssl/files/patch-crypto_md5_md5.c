--- crypto/md5/md5.c.orig	2015-03-19 13:19:00 UTC
+++ crypto/md5/md5.c
@@ -83,7 +83,7 @@ int main(int argc, char **argv)
                 err++;
                 continue;
             }
-            printf("MD5(%s)= ", argv[i]);
+            printf("MD5 (%s) = ", argv[i]);
             do_fp(IN);
             fclose(IN);
         }
