--- ./log.h	2009-08-08 20:54:21.000000000 -0400
+++ ../../pam_ssh_agent_auth-0.9.3.fixed/log.h	2011-10-10 13:10:38.856166661 -0400
@@ -55,7 +55,7 @@
 void     logerror(const char *, ...) __attribute__((format(printf, 1, 2)));
 void     sigdie(const char *, ...) __attribute__((format(printf, 1, 2)));
 void     logit(const char *, ...) __attribute__((format(printf, 1, 2)));
-void     verbose(const char *, ...) __attribute__((format(printf, 1, 2)));
+void     pam_ssh_auth_verbose(const char *, ...) __attribute__((format(printf, 1, 2)));
 void     debug(const char *, ...) __attribute__((format(printf, 1, 2)));
 void     debug2(const char *, ...) __attribute__((format(printf, 1, 2)));
 void     debug3(const char *, ...) __attribute__((format(printf, 1, 2)));
