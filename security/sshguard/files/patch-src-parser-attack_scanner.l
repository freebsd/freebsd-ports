--- src/parser/attack_scanner.l.orig	2015-05-16 19:49:47.000000000 -0500
+++ src/parser/attack_scanner.l	2015-05-16 19:57:07.000000000 -0500
@@ -74,6 +74,7 @@
 IPV4MAPPED6 ((:(:0{1,4}){0,4}|0{1,4}:(:0{1,4}){1,3}|(0{1,4}:){2}(0{1,4}:0{0,4}:0{1,4}|(:0{1,4}){1,2})|(0{1,4}:){1,4}):[fF]{4}:(((2[0-4]|1[0-9]|[1-9])?[0-9]|25[0-5])\.){3}((2[0-4]|1[0-9]|[1-9])?[0-9]|25[0-5]))
 
 HOSTADDR    localhost|([-a-zA-Z0-9]+\.)+[a-zA-Z]+|{IPV4}|{IPV6}|{IPV4MAPPED6}
+FACLEVEL    (<[a-zA-Z0-9]+\.[a-zA-Z0-9]+>)
 
 %%
 
@@ -87,13 +88,14 @@
   */
 
  /* handle entries with PID and without PID from processes other than sshguard */
-({TIMESTAMP_SYSLOG}|{TIMESTAMP_ISO8601})[ ]+([a-zA-Z0-9]|{WORD}|{HOSTADDR})[ ]+{PROCESSNAME}("/"{PROCESSNAME})?"["{NUMBER}"]: "{SOLARIS_MSGID_TAG}? {
+({TIMESTAMP_SYSLOG}|{TIMESTAMP_ISO8601})[ ]+{FACLEVEL}?[ ]*([a-zA-Z0-9]|{WORD}|{HOSTADDR})[ ]+{PROCESSNAME}("/"{PROCESSNAME})?"["{NUMBER}"]: "{SOLARIS_MSGID_TAG}? {
         /* extract PID */
         yylval.num = getsyslogpid(yytext, yyleng);
         return SYSLOG_BANNER_PID;
         }
 
-({TIMESTAMP_SYSLOG}|{TIMESTAMP_ISO8601})[ ]+([a-zA-Z0-9]|{WORD}|{HOSTADDR})[ ]+({PROCESSNAME}("/"{PROCESSNAME})?":")?   { return SYSLOG_BANNER; }
+({TIMESTAMP_SYSLOG}|{TIMESTAMP_ISO8601})[ ]+{FACLEVEL}?[ ]*([a-zA-Z0-9]|{WORD}|{HOSTADDR})[ ]+({PROCESSNAME}("/"{PROCESSNAME})?":")?   { return SYSLOG_BANNER; }
+
 
  /* syslog style  "last message repeated N times" */
 "last message repeated "([1-9][0-9]*)" times"                   {
