--- Portscout/SiteHandler.pm.orig	2010-04-29 01:07:51 UTC
+++ Portscout/SiteHandler.pm
@@ -31,6 +31,8 @@ package Portscout::SiteHandler;
 use XML::XPath;
 use XML::XPath::XMLParser;
 
+use Portscout::SiteHandler::GitHub;
+use Portscout::SiteHandler::PyPI;
 use Portscout::SiteHandler::SourceForge;
 
 use strict;
