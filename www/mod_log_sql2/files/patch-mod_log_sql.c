--- mod_log_sql.c.orig	Fri Apr 16 14:47:38 2004
+++ mod_log_sql.c	Fri Apr 16 14:47:51 2004
@@ -1,5 +1,13 @@
 /* $Id: mod_log_sql.c,v 1.20 2004/03/05 00:30:58 urkle Exp $ */
 
+#if defined(WITH_APACHE20)
+#	include "apache20.h"
+#elif defined(WITH_APACHE13)
+#	include "apache13.h"
+#else
+#	error Unsupported Apache version
+#endif
+
 #ifdef HAVE_CONFIG_H
 /* Undefine these to prevent conflicts between Apache ap_config_auto.h and 
  * my config.h. Only really needed for Apache < 2.0.48, but it can't hurt.
@@ -11,14 +19,6 @@
 #undef PACKAGE_VERSION
 
 #include "config.h"
-#endif
-
-#if defined(WITH_APACHE20)
-#	include "apache20.h"
-#elif defined(WITH_APACHE13)
-#	include "apache13.h"
-#else
-#	error Unsupported Apache version
 #endif
 
 #if APR_HAVE_UNISTD_H
