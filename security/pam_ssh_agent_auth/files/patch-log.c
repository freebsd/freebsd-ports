--- ./log.c	2009-08-08 20:54:21.000000000 -0400
+++ ../../pam_ssh_agent_auth-0.9.3.fixed/log.c	2011-10-10 13:10:35.865388224 -0400
@@ -166,7 +166,7 @@
 /* More detailed messages (information that does not need to go to the log). */
 
 void
-verbose(const char *fmt,...)
+pam_ssh_auth_verbose(const char *fmt,...)
 {
 	va_list args;
 
