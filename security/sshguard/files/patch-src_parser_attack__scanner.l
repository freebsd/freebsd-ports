https://github.com/SSHGuard/sshguard/commit/06caf25a6abccdbba51e67ac99d83df9d412dc3f
https://github.com/SSHGuard/sshguard/commit/f180843f6da34f9ca7a2557fa1b51ca85c561634

--- src/parser/attack_scanner.l.orig	2025-04-28 18:20:39 UTC
+++ src/parser/attack_scanner.l
@@ -95,8 +95,9 @@ HTTP_VERSION    HTTP"/"[0-9]("."[0-9])?
 HTTP_REQUEST    (GET|HEAD|PUT|POST|DELETE)
 HTTP_VERSION    HTTP"/"[0-9]("."[0-9])?
 
- // host part of a hostname (without any domain parts)
-SYSLOG_HOSTNAME   {WORD}
+ // RFC 5424 says HOSTNAME header field SHOULD contain the FQDN.
+ // IP addresss and hostname may also be present in HOSTNAME.
+SYSLOG_HOSTNAME   {WORD}|{HOSTADDR}
 
  // timestamp (optional PRI) hostname
 SYSLOG_HEADER     ({TIMESTAMP_SYSLOG}|{TIMESTAMP_ISO8601})[ ]+{FACLEVEL}?[ ]*{SYSLOG_HOSTNAME}[ ]+
