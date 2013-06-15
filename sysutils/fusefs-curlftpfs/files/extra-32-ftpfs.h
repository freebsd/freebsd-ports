--- ftpfs.h.orig	2008-04-25 19:32:30.000000000 +0900
+++ ftpfs.h	2012-12-21 18:18:20.000000000 +0900
@@ -75,7 +75,7 @@
         do { if (level <= ftpfs.debug) {\
                int i = 0; \
                while (++i < level) fprintf(stderr, " "); \
-               fprintf(stderr, "%ld ", time(NULL));\
+               fprintf(stderr, "%d ", time(NULL));\
                fprintf(stderr, __FILE__ ":%d ", __LINE__);\
                fprintf(stderr, args);\
              }\
