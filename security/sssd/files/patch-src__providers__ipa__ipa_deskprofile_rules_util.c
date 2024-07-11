--- src/providers/ipa/ipa_deskprofile_rules_util.c.orig	2020-03-17 13:31:28 UTC
+++ src/providers/ipa/ipa_deskprofile_rules_util.c
@@ -25,6 +25,8 @@
 #include "providers/ipa/ipa_rules_common.h"
 #include <ctype.h>
 #include <fcntl.h>
+#include <sys/types.h>
+#include <signal.h>
 
 #define DESKPROFILE_GLOBAL_POLICY_MIN_VALUE 1
 #define DESKPROFILE_GLOBAL_POLICY_MAX_VALUE 24
