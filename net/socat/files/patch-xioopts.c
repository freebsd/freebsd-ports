--- xioopts.c.orig	2015-01-24 10:15:22 UTC
+++ xioopts.c
@@ -2971,6 +2971,25 @@ int retropt_bind(struct opt *opts,
    OFUNC_TERMIOS_FLAG, OFUNC_TERMIOS_PATTERN, and some OFUNC_SPEC */
 int applyopts(int fd, struct opt *opts, enum e_phase phase) {
    struct opt *opt;
+#ifdef HAVE_TERMIOS_ISPEED
+   int ispeed_major = -1, ospeed_major = -1;
+   unsigned int ispeed_value, ospeed_value;
+   bool speed_done = false;
+
+   opt = opts; while (opt && opt->desc != ODESC_END) {
+      if (opt->desc == ODESC_DONE ||
+          (phase != PH_ALL && opt->desc->phase != phase)) {
+         ++opt; continue; }
+         if (opt->desc->optcode == OPT_ISPEED) {
+           ispeed_major = opt->desc->major;
+           ispeed_value = opt->value.u_uint; }
+         if (opt->desc->optcode == OPT_OSPEED) {
+           ospeed_major = opt->desc->major;
+           ospeed_value = opt->value.u_uint; }
+      ++opt;
+      continue;
+   }
+#endif /* HAVE_TERMIOS_ISPEED */
 
    opt = opts; while (opt && opt->desc != ODESC_END) {
       if (opt->desc == ODESC_DONE ||
@@ -3605,21 +3624,29 @@ int applyopts(int fd, struct opt *opts, 
 
 #ifdef HAVE_TERMIOS_ISPEED
       } else if (opt->desc->func == OFUNC_TERMIOS_SPEED) {
-	 union {
-	    struct termios termarg;
-	    speed_t speeds[sizeof(struct termios)/sizeof(speed_t)];
-	 } tdata;
-	 if (Tcgetattr(fd, &tdata.termarg) < 0) {
-	    Error3("tcgetattr(%d, %p): %s",
-		   fd, &tdata.termarg, strerror(errno));
-	    opt->desc = ODESC_ERROR; ++opt; continue;
-	 }
-	 tdata.speeds[opt->desc->major] = opt->value.u_uint;
-	 if (Tcsetattr(fd, TCSADRAIN, &tdata.termarg) < 0) {
-	    Error3("tcsetattr(%d, TCSADRAIN, %p): %s",
-		   fd, &tdata.termarg, strerror(errno));
-	    opt->desc = ODESC_ERROR; ++opt; continue;
-	 }
+         if (speed_done == false) {
+           union {
+              struct termios termarg;
+              speed_t speeds[sizeof(struct termios)/sizeof(speed_t)];
+           } tdata;
+           if (Tcgetattr(fd, &tdata.termarg) < 0) {
+              Error3("tcgetattr(%d, %p): %s",
+                     fd, &tdata.termarg, strerror(errno));
+              opt->desc = ODESC_ERROR; ++opt; continue;
+           }
+           if (ispeed_major < 0 || ospeed_major < 0)
+             tdata.speeds[opt->desc->major] = opt->value.u_uint;
+           else{ 
+             tdata.speeds[ispeed_major] = ispeed_value;
+             tdata.speeds[ospeed_major] = ospeed_value;
+             speed_done = true;
+           }
+           if (Tcsetattr(fd, TCSADRAIN, &tdata.termarg) < 0) {
+             Error3("tcsetattr(%d, TCSADRAIN, %p): %s",
+                     fd, &tdata.termarg, strerror(errno));
+              opt->desc = ODESC_ERROR; ++opt; continue;
+           }
+         }
 #endif /* HAVE_TERMIOS_ISPEED */
 
       } else if (opt->desc->func == OFUNC_TERMIOS_SPEC) {
