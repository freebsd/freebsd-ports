--- src/pflib/NATCompiler_ipf.cpp.orig	2006-09-10 17:41:09.000000000 -0700
+++ src/pflib/NATCompiler_ipf.cpp	2007-09-19 11:39:40.000000000 -0700
@@ -398,6 +398,8 @@
 
     bool ftp_proxy    = compiler->getCachedFwOpt()->getBool("ipf_nat_ftp_proxy");
     bool rcmd_proxy   = compiler->getCachedFwOpt()->getBool("ipf_nat_rcmd_proxy");
+    bool krcmd_proxy  = compiler->getCachedFwOpt()->getBool("ipf_nat_krcmd_proxy");
+    bool ekshell_proxy  = compiler->getCachedFwOpt()->getBool("ipf_nat_ekshell_proxy");
     bool raudio_proxy = compiler->getCachedFwOpt()->getBool("ipf_nat_raudio_proxy");
     bool h323_proxy   = compiler->getCachedFwOpt()->getBool("ipf_nat_h323_proxy");
     bool ipsec_proxy  = compiler->getCachedFwOpt()->getBool("ipf_nat_ipsec_proxy");
@@ -407,6 +409,8 @@
     char ipsec_proxy_str[64];
     char ftp_proxy_str[64];
     char rcmd_proxy_str[64];
+    char krcmd_proxy_str[64];
+    char ekshell_proxy_str[64];
     char raudio_proxy_str[64];
     char h323_proxy_str[64];
     char pptp_proxy_str[64];
@@ -415,6 +419,8 @@
     sprintf(ipsec_proxy_str,  "proxy port %d ipsec/udp ",  ISAKMP_PORT);
     sprintf(ftp_proxy_str,    "proxy port %d ftp/tcp ",    FTP_PORT);
     sprintf(rcmd_proxy_str,   "proxy port %d rcmd/tcp ",   RCMD_PORT);
+    sprintf(krcmd_proxy_str,  "proxy port %d rcmd/tcp ",   KRCMD_PORT);
+    sprintf(ekshell_proxy_str,"proxy port %d rcmd/tcp ",   EKSHELL_PORT);
     sprintf(raudio_proxy_str, "proxy port %d raudio/tcp ", RAUDIO_PORT);
     sprintf(h323_proxy_str,   "proxy port %d h323/tcp ",   H323_PORT);
     sprintf(pptp_proxy_str,   "proxy port %d pptp/tcp ",   PPTP_PORT);
@@ -445,6 +451,14 @@
                 s->getInt("dst_range_start")==RCMD_PORT && s->getInt("dst_range_end")==RCMD_PORT )   
                 rule->setStr("nat_rule_proxy",rcmd_proxy_str);
 
+            if (krcmd_proxy &&
+                s->getInt("dst_range_start")==KRCMD_PORT && s->getInt("dst_range_end")==KRCMD_PORT )   
+                rule->setStr("nat_rule_proxy",krcmd_proxy_str);
+
+            if (ekshell_proxy &&
+                s->getInt("dst_range_start")==EKSHELL_PORT && s->getInt("dst_range_end")==EKSHELL_PORT )   
+                rule->setStr("nat_rule_proxy",ekshell_proxy_str);
+
             if (raudio_proxy &&
                 s->getInt("dst_range_start")==RAUDIO_PORT && s->getInt("dst_range_end")==RAUDIO_PORT ) 
                 rule->setStr("nat_rule_proxy",raudio_proxy_str);
