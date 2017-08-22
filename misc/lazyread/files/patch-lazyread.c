--- lazyread.c.orig	2003-02-02 13:28:15 UTC
+++ lazyread.c
@@ -377,7 +377,7 @@ char qfilename[BUFMAX]; /* quoted filena
 
     printf("Loading..\n");
     /* $LESSOPEN will look like:  |/usr/bin/lesspipe.sh %s */
-    lesspipe = getenv("LESSOPEN");
+    lesspipe = "|/usr/bin/lesspipe.sh %s";
     if (lesspipe) {
         /* strip off the leading | */ 
         if ((c = strchr(lesspipe, '|'))) {
