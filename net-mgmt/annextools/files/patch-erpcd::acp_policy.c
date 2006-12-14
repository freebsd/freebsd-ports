--- erpcd/acp_policy.c.orig	Thu Dec 14 13:12:21 2006
+++ erpcd/acp_policy.c	Thu Dec 14 13:14:18 2006
@@ -333,6 +333,7 @@
                                         char *Pass, int prompt,
                                         int max_retries, char *Message,
 					ARQ_PROFILE *opt_info));
+static int map_mask_to_code(int);
 
 #ifdef _WIN32
 int syslog( int pri, const char *format, ...);
