--- lmtpconf.c.org	2004-10-26 17:59:50.000000000 +0200
+++ lmtpconf.c	2006-12-24 11:23:03.000000000 +0100
@@ -197,6 +197,7 @@
   return rl;
 }
 
+static int readconf1(char *file, struct fstate *state, struct conf *spec);
 
 static int setval(void *val, int type, char *args) {
   switch(type) {
@@ -392,8 +393,6 @@
     return 0;
   case FLAGS_INCLUDE: 
     if (args) {
-      static int readconf1(char *file, struct fstate *state,
-			   struct conf *spec);
       struct conf_state *cstate = val;
       char *filename = args;
       int ret = -1;
