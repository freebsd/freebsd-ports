--- jabberd/log.cc.orig	Tue Jul 17 01:20:44 2007
+++ jabberd/log.cc	Tue Jul 17 15:57:22 2007
@@ -282,7 +282,7 @@
  * @param action action that is logged (e.g. a failed auth)
  * @param msgfmt printf()-like format string, parameters are following
  */
-void log_generic(const char *logtype, const char *id, const char *type, const char *action, const char *msgfmt, ...) {
+void log_generic(char *logtype, char *id, char *type, char *action, const char *msgfmt, ...) {
     va_list ap;
     char logmsg[512] = "";
     xmlnode log;
@@ -327,7 +327,7 @@
  * @param action action that is logged (e.g. a failed auth)
  * @param msgfmt printf()-like format string, parameters are following
  */
-void log_record(const char *id, const char *type, const char *action, const char *msgfmt, ...) {
+void log_record(char *id, char *type, char *action, const char *msgfmt, ...) {
     va_list ap;
     char logmsg[512] = "";
 
