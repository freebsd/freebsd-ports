--- src/parser/attack_scanner.l.orig	2015-03-24 02:08:55 UTC
+++ src/parser/attack_scanner.l
@@ -78,6 +78,7 @@ MINPS       [0-5][0-9]
 WORD        [a-zA-Z0-9][-_a-zA-Z0-9]+
 NUMBER      [1-9][0-9]*
 HOSTADDR    localhost|([-a-zA-Z0-9]+\.)+[a-zA-Z]+
+FACLEVEL    (<[a-zA-Z0-9]+\.[a-zA-Z0-9]+>)
 
 TIMESTAMP_SYSLOG    {MONTH}\ +{DAYNO}\ +{HOUR}:{MINPS}:{MINPS}
 TIMESTAMP_TAI64     [0-9A-Fa-f]{24}
@@ -107,13 +108,13 @@ IPV4MAPPED6 ((:(:0{1,4}){0,4}|0{1,4}:(:0
   */
 
  /* handle entries with PID and without PID from processes other than sshguard */
-{TIMESTAMP_SYSLOG}[ ]+([a-zA-Z0-9]|{WORD}|{HOSTADDR})[ ]+{PROCESSNAME}"["{NUMBER}"]: "{SOLARIS_MSGID_TAG}? {
+{TIMESTAMP_SYSLOG}[ ]+{FACLEVEL}?[ ]*([a-zA-Z0-9]|{WORD}|{HOSTADDR})[ ]+{PROCESSNAME}"["{NUMBER}"]: "{SOLARIS_MSGID_TAG}? {
         /* extract PID */
         yylval.num = getsyslogpid(yytext, yyleng);
         return SYSLOG_BANNER_PID;
         }
 
-{TIMESTAMP_SYSLOG}[ ]+([a-zA-Z0-9]|{WORD}|{HOSTADDR})[ ]+({PROCESSNAME}":")?   { return SYSLOG_BANNER; }
+{TIMESTAMP_SYSLOG}[ ]+{FACLEVEL}?[ ]*([a-zA-Z0-9]|{WORD}|{HOSTADDR})[ ]+({PROCESSNAME}":")?   { return SYSLOG_BANNER; }
 
  /* syslog style  "last message repeated N times" */
 "last message repeated "([1-9][0-9]*)" times"                   {
