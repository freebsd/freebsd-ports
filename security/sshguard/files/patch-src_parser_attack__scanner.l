--- src/parser/attack_scanner.l.orig	2021-03-01 01:01:21 UTC
+++ src/parser/attack_scanner.l
@@ -247,7 +247,7 @@ HTTP_LOGIN_200OK_BAD       .*({WORDPRESS_LOGIN}|{TYPO3
 
  /* cyrus-imap login error */
 "badlogin: "[^\[]*"["                                           { BEGIN(cyrusimap_loginerr); return CYRUSIMAP_SASL_LOGINERR_PREF; }
-<cyrusimap_loginerr>"] ".*"SASL".*"failed".?$                   { BEGIN(INITIAL); return CYRUSIMAP_SASL_LOGINERR_SUFF; }
+<cyrusimap_loginerr>"] ".*"SASL".*"fail".*$                   { BEGIN(INITIAL); return CYRUSIMAP_SASL_LOGINERR_SUFF; }
 
  /* postfix */
 "warning: "({WORD}|{HOSTADDR})"["                               { BEGIN(postfix_loginerr); return POSTFIX_SASL_LOGINERR_PREF; }
