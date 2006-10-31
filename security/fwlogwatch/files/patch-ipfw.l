--- ipfw.l.orig	Wed Mar  8 21:27:59 2006
+++ ipfw.l	Sat Oct 21 20:46:44 2006
@@ -33,7 +33,7 @@
 %%
 
 {MONTH}[ ]{1,2}{DIGIT}{1,2}[ ]{DIGIT}{2}:{DIGIT}{2}:{DIGIT}{2}[ ]{LOGHOST}	ipfw_parse_start(ipfwtext);
-" kernel: ipfw: "{NUMBER}	{ xstrncpy(opt.line->chainlabel, ipfwtext+15, SHORTLEN); opt.parser=opt.parser|IPFW_CHAIN; };
+" /"?"kernel: ipfw: "{NUMBER}  { xstrncpy(opt.line->chainlabel, ipfwtext+14, SHORTLEN); opt.parser=opt.parser|IPFW_CHAIN; };
 " ipfw: "{NUMBER}		{ xstrncpy(opt.line->chainlabel, ipfwtext+7, SHORTLEN); opt.parser=opt.parser|IPFW_CHAIN; };
 "Deny"				{ xstrncpy(opt.line->branchname, ipfwtext, SHORTLEN); opt.parser=opt.parser|IPFW_BRANCH; };
 "Count"				{ xstrncpy(opt.line->branchname, ipfwtext, SHORTLEN); opt.parser=opt.parser|IPFW_BRANCH; };
