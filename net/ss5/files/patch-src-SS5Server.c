--- src/SS5Server.c.orig	2009-08-02 01:57:19.000000000 -0500
+++ src/SS5Server.c	2013-03-05 19:49:44.744425659 -0600
@@ -44,6 +44,8 @@
   SS5SocksOpt.PreforkProcesses = 1;
   SS5SocksOpt.PropagateKey     = 0;
   SS5SocksOpt.Role             = ALONE;
+  SS5SocksOpt.SyslogFa         = LOG_LOCAL6;
+  SS5SocksOpt.SyslogLe         = LOG_ERR;
   S5Radius.AuthPort            = RADIUS_AUTH_PORT;
   S5Radius.AcctPort            = RADIUS_ACCT_PORT;
 
