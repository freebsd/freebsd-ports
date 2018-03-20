--- tools/srchtools/sigfind.cpp.orig	2018-02-21 04:27:25 UTC
+++ tools/srchtools/sigfind.cpp
@@ -302,7 +302,7 @@ main(int argc, char **argv)
             break;
         }
         else if (retval == -1) {
-            fprintf(stderr, "error reading bytes %"PRIuOFF"\n", i);
+            fprintf(stderr, "error reading bytes %" PRIuOFF "\n", i);
             exit(1);
         }
 
@@ -312,9 +312,9 @@ main(int argc, char **argv)
             ((sig_size < 3) || (block[rel_offset + 2] == sig[2])) &&
             ((sig_size < 4) || (block[rel_offset + 3] == sig[3]))) {
             if (prev_hit == -1)
-                printf("Block: %"PRIuOFF" (-)\n",  i);
+                printf("Block: %" PRIuOFF " (-)\n",  i);
             else
-                printf("Block: %"PRIuOFF" (+%"PRIuOFF")\n", i,
+                printf("Block: %" PRIuOFF " (+%" PRIuOFF ")\n", i,
                        (i - prev_hit));
 
             prev_hit = i;
