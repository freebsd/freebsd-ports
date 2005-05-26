--- cherokee/config_protocol_scanner.c.orig	Sat May 21 02:14:14 2005
+++ cherokee/config_protocol_scanner.c	Tue May 24 16:15:26 2005
@@ -782,7 +782,7 @@
 case 6:
 YY_RULE_SETUP
 #line 47 "config_protocol_scanner.l"
-{ yy_config_protocol_lval.number = atoll(yy_config_protocol_text); return T_NUM; }
+{ yy_config_protocol_lval.number = strtoll(yy_config_protocol_text, (char **)NULL, 10); return T_NUM; }
 	YY_BREAK
 case 7:
 /* rule 7 can match eol */
