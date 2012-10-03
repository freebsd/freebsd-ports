--- ./lib/core/settings.py.orig	2011-04-11 04:23:42.000000000 +0400
+++ ./lib/core/settings.py	2012-10-03 23:09:17.000000000 +0400
@@ -18,7 +18,7 @@
 
 # sqlmap version and site
 VERSION            = "0.9"
-REVISION           = getRevisionNumber()
+REVISION           = 3630
 VERSION_STRING     = "sqlmap/%s" % VERSION
 DESCRIPTION        = "automatic SQL injection and database takeover tool"
 SITE               = "http://sqlmap.sourceforge.net"
