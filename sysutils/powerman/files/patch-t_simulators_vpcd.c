--- t/simulators/vpcd.c.orig	2024-04-11 21:45:47 UTC
+++ t/simulators/vpcd.c
@@ -239,7 +239,7 @@ _spew_one(int linenum)
 
     linenum %= strlen(SPEW);
 
-    memcpy(buf, SPEW + linenum, strlen(SPEW) - linenum);
+    memcpy(buf, &SPEW[linenum], strlen(SPEW) - linenum);
     memcpy(buf + strlen(SPEW) - linenum, SPEW, linenum);
     buf[strlen(SPEW)] = '\0';
     printf("%s\n", buf);
