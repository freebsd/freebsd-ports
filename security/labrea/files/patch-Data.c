--- Data.c.orig	Tue Feb 11 01:04:04 2003
+++ Data.c	Sat Jun 14 11:39:04 2003
@@ -22,3 +22,6 @@
+#ifndef CONFIG_PATH
+#define COFNIG_PATH "/etc"
+#endif
 #ifdef OLDSTYLE
 #ifdef WIN32
 char HardExcludeName[] = "LaBreaHardExclude.cfg";
@@ -30,14 +33,14 @@
 char IgnorePortName[] = "LaBreaIgnorePort.cfg";
 char IgnorePortNotFound[] = "LaBreaIgnorePort.cfg not found - nothing to ignore";
 #else
-char HardExcludeName[] = "/etc/LaBreaHardExclude";
-char HardExcludeNotFound[] = "/etc/LaBreaHardExclude not found - no hard exclusions";
-char IgnoreName[] = "/etc/LaBreaIgnoreIP";
-char IgnoreNotFound[] = "/etc/LaBreaIgnoreIP not found - nothing to ignore";
-char ExcludeName[] = "/etc/LaBreaExclude";
-char ExcludeNotFound[] = "/etc/LaBreaExclude not found - no hard exclusions";
-char IgnorePortName[] = "/etc/LaBreaIgnorePort";
-char IgnorePortNotFound[] = "/etc/LaBreaIgnorePort not found - nothing to ignore";
+char HardExcludeName[] = CONFIG_PATH"/LaBreaHardExclude";
+char HardExcludeNotFound[] = CONFIG_PATH"/LaBreaHardExclude not found - no hard exclusions";
+char IgnoreName[] = CONFIG_PATH"/LaBreaIgnoreIP";
+char IgnoreNotFound[] = CONFIG_PATH"/LaBreaIgnoreIP not found - nothing to ignore";
+char ExcludeName[] = CONFIG_PATH"/LaBreaExclude";
+char ExcludeNotFound[] = CONFIG_PATH"/LaBreaExclude not found - no hard exclusions";
+char IgnorePortName[] = CONFIG_PATH"/LaBreaIgnorePort";
+char IgnorePortNotFound[] = CONFIG_PATH"/LaBreaIgnorePort not found - nothing to ignore";
 #endif /* WIN32 */
 char format3[] = "Exclude: %i.%i.%i.%i\n";
 char format4[] = "HardExclude: %i.%i.%i.%i\n";
@@ -46,8 +49,8 @@
 char ConfigName[] = "LaBrea.cfg";
 char ConfigNotFound[] = "LaBrea.cfg not found";
 #else
-char ConfigName[] = "/etc/LaBreaConfig";
-char ConfigNotFound[] = "/etc/LaBreaConfig not found";
+char ConfigName[] = CONFIG_PATH"/LaBreaConfig";
+char ConfigNotFound[] = CONFIG_PATH"/LaBreaConfig not found";
 #endif /* WIN32 */
 #endif /* OLDSTYLE */
 
@@ -127,7 +130,7 @@
 char err17[]   = "Invalid or missing interface!\n";
 char getoptstr[] = "HXPoOdTRqr:i:t:lvVxs?hzap:bE:I:Dfj";
 #else
-char strRandFileName[] = "/etc/LaBreaRandom";
+char strRandFileName[] = CONFIG_PATH"/LaBreaRandom";
 char err18[]   = "User specified netmask: %s\nUser specified network number: %s\n";
 char getoptstr[] = "HXPoOdTRqF:r:i:t:lvVxsn:m:?hzap:bfj";
 #endif
