--- ipfw.l.orig	Sun Mar 21 10:42:55 2004
+++ ipfw.l	Sat Dec 11 16:57:23 2004
@@ -33,7 +33,7 @@
 %%
 
 {MONTH}[ ]{1,2}{DIGIT}{1,2}[ ]{DIGIT}{2}:{DIGIT}{2}:{DIGIT}{2}[ ]{LOGHOST}	ipfw_parse_start(ipfwtext);
-" kernel: ipfw: "{NUMBER}	{ xstrncpy(opt.line->chainlabel, ipfwtext+15, SHORTLEN); opt.parser=opt.parser|IPFW_CHAIN; };
+" /"?"kernel: ipfw: "{NUMBER}	{ xstrncpy(opt.line->chainlabel, ipfwtext+15, SHORTLEN); opt.parser=opt.parser|IPFW_CHAIN; };
 "Deny"				{ xstrncpy(opt.line->branchname, ipfwtext, SHORTLEN); opt.parser=opt.parser|IPFW_BRANCH; };
 {PROTO}				ipfw_parse_proto(ipfwtext, IPFW_OPT_NONE);
 "ICMP:"{NUMBER}"."{NUMBER}	ipfw_parse_proto(ipfwtext+5, IPFW_OPT_ICMP);
