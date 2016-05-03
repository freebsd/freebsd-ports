--- xioopts.c.orig	2015-01-24 10:15:22 UTC
+++ xioopts.c
@@ -296,7 +296,7 @@ const struct optname optionnames[] = {
 #if WITH_EXT2 && defined(EXT2_COMPR_FL)
 	IF_ANY    ("compr",	&opt_ext2_compr)
 #endif
-#if OPENSSL_VERSION_NUMBER >= 0x00908000L
+#if OPENSSL_VERSION_NUMBER >= 0x00908000L && !defined OPENSSL_NO_COMP
 	IF_OPENSSL("compress",	&opt_openssl_compress)
 #endif
 #ifdef TCP_CONN_ABORT_THRESHOLD  /* HP_UX */
@@ -412,7 +412,9 @@ const struct optname optionnames[] = {
 #ifdef ECHOPRT
 	IF_TERMIOS("echoprt",	&opt_echoprt)
 #endif
+#ifndef OPENSSL_NO_EGD
 	IF_OPENSSL("egd",	&opt_openssl_egd)
+#endif
 	IF_ANY    ("end-close",	&opt_end_close)
 	IF_TERMIOS("eof",	&opt_veof)
 	IF_TERMIOS("eol",	&opt_veol)
@@ -1098,11 +1100,13 @@ const struct optname optionnames[] = {
 	IF_OPENSSL("openssl-certificate",	&opt_openssl_certificate)
 	IF_OPENSSL("openssl-cipherlist",	&opt_openssl_cipherlist)
 	IF_OPENSSL("openssl-commonname",	&opt_openssl_commonname)
-#if OPENSSL_VERSION_NUMBER >= 0x00908000L
+#if OPENSSL_VERSION_NUMBER >= 0x00908000L && !defined OPENSSL_NO_COMP
 	IF_OPENSSL("openssl-compress",	&opt_openssl_compress)
 #endif
 	IF_OPENSSL("openssl-dhparam",	&opt_openssl_dhparam)
+#ifndef OPENSSL_NO_EGD
 	IF_OPENSSL("openssl-egd",	&opt_openssl_egd)
+#endif
 #if WITH_FIPS
 	IF_OPENSSL("openssl-fips",	&opt_openssl_fips)
 #endif
@@ -2971,6 +2975,25 @@ int retropt_bind(struct opt *opts,
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
@@ -3605,21 +3628,29 @@ int applyopts(int fd, struct opt *opts, 
 
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
