--- src/plugins/gateways/gateways.cpp.orig	2018-09-01 12:43:54 UTC
+++ src/plugins/gateways/gateways.cpp
@@ -18,7 +18,7 @@
 #define GATEWAY_TIMEOUT           30000
 #define KEEP_INTERVAL             120000
 
-#define MAIL_NODE_PATTERN         "[a-zA-Z0-9_\\-\\.]+"
+#define  MAIL_NODE_PATTERN          "[a-zA-Z0-9_\\-\\.]+"
 
 Gateways::Gateways()
 {
@@ -218,7 +218,7 @@ bool Gateways::initConnections(IPluginManager *APlugin
 
 bool Gateways::initObjects()
 {
-	static const QString JabberContactPattern = "^"JID_NODE_PATTERN"@"JID_DOMAIN_PATTERN"$";
+	static const QString JabberContactPattern = "^" JID_NODE_PATTERN "@" JID_DOMAIN_PATTERN "$";
 
 	// !!Последовательность добавления дескрипторов имеет значение!!
 	IGateServiceDescriptor sms;
@@ -258,7 +258,7 @@ bool Gateways::initObjects()
 	magent.loginField = "username";
 	magent.passwordField = "password";
 	magent.domainSeparator = "@";
-	magent.homeContactPattern = "^"MAIL_NODE_PATTERN"@(mail|inbox|bk|list)\\.ru$";
+	magent.homeContactPattern = "^" MAIL_NODE_PATTERN "@(mail|inbox|bk|list)\\.ru$";
 	magent.availContactPattern = magent.homeContactPattern;
 	magent.linkedDescriptors.append(GSID_MAIL);
 	FGateDescriptors.append(magent);
@@ -288,7 +288,7 @@ bool Gateways::initObjects()
 	gtalk.domainField = "server";
 	gtalk.passwordField = "password";
 	gtalk.domainSeparator = "@";
-	gtalk.homeContactPattern = "^"MAIL_NODE_PATTERN"@(gmail|googlemail)\\.com$";
+	gtalk.homeContactPattern = "^" MAIL_NODE_PATTERN "@(gmail|googlemail)\\.com$";
 	gtalk.availContactPattern = JabberContactPattern;
 	gtalk.linkedDescriptors.append(GSID_MAIL);
 	FGateDescriptors.append(gtalk);
@@ -305,7 +305,7 @@ bool Gateways::initObjects()
 	yonline.domainField = "server";
 	yonline.passwordField = "password";
 	yonline.domainSeparator = "@";
-	yonline.homeContactPattern = "^"MAIL_NODE_PATTERN"@(ya\\.ru|yandex\\.ru|yandex\\.net|yandex\\.com|yandex\\-co\\.ru|narod\\.ru|yandex\\.by|yandex\\.kz|yandex\\.ua)$";
+	yonline.homeContactPattern = "^" MAIL_NODE_PATTERN "@(ya\\.ru|yandex\\.ru|yandex\\.net|yandex\\.com|yandex\\-co\\.ru|narod\\.ru|yandex\\.by|yandex\\.kz|yandex\\.ua)$";
 	yonline.availContactPattern = JabberContactPattern;
 	yonline.linkedDescriptors.append(GSID_MAIL);
 	FGateDescriptors.append(yonline);
@@ -324,7 +324,7 @@ bool Gateways::initObjects()
 	qip.domainField = "server";
 	qip.passwordField = "password";
 	qip.domainSeparator = "@";
-	qip.homeContactPattern = "^"MAIL_NODE_PATTERN"@qip\\.ru$";
+	qip.homeContactPattern = "^" MAIL_NODE_PATTERN "@qip\\.ru$";
 	qip.availContactPattern = JabberContactPattern;
 	qip.linkedDescriptors.append(GSID_MAIL);
 	FGateDescriptors.append(qip);
@@ -343,7 +343,7 @@ bool Gateways::initObjects()
 	//vkontakte.domainField = "server";
 	vkontakte.passwordField = "password";
 	//vkontakte.domainSeparator = "@";
-	vkontakte.homeContactPattern = "^"MAIL_NODE_PATTERN"@vk\\.com$";
+	vkontakte.homeContactPattern = "^" MAIL_NODE_PATTERN "@vk\\.com$";
 	vkontakte.availContactPattern = JabberContactPattern;
 	vkontakte.blockedDescriptors.append(GSID_MAIL);
 	FGateDescriptors.append(vkontakte);
@@ -362,7 +362,7 @@ bool Gateways::initObjects()
 	facebook.domainField = "server";
 	facebook.passwordField = "password";
 	facebook.domainSeparator = "@";
-	facebook.homeContactPattern = "^"MAIL_NODE_PATTERN"@chat\\.facebook\\.com$";
+	facebook.homeContactPattern = "^" MAIL_NODE_PATTERN "@chat\\.facebook\\.com$";
 	facebook.availContactPattern = JabberContactPattern;
 	facebook.blockedDescriptors.append(GSID_MAIL);
 	FGateDescriptors.append(facebook);
@@ -379,7 +379,7 @@ bool Gateways::initObjects()
 	livejournal.domainField = "server";
 	livejournal.passwordField = "password";
 	livejournal.domainSeparator = "@";
-	livejournal.homeContactPattern = "^"MAIL_NODE_PATTERN"@livejournal\\.com$";
+	livejournal.homeContactPattern = "^" MAIL_NODE_PATTERN "@livejournal\\.com$";
 	livejournal.availContactPattern = JabberContactPattern;
 	livejournal.blockedDescriptors.append(GSID_MAIL);
 	FGateDescriptors.append(livejournal);
@@ -396,7 +396,7 @@ bool Gateways::initObjects()
 	rambler.domainField = "server";
 	rambler.passwordField = "password";
 	rambler.domainSeparator = "@";
-	rambler.homeContactPattern = "^"MAIL_NODE_PATTERN"@(rambler|lenta|myrambler|autorambler|ro|r0)\\.ru$";
+	rambler.homeContactPattern = "^" MAIL_NODE_PATTERN "@(rambler|lenta|myrambler|autorambler|ro|r0)\\.ru$";
 	rambler.availContactPattern = JabberContactPattern;
 	rambler.linkedDescriptors.append(GSID_MAIL);
 	FGateDescriptors.append(rambler);
@@ -428,7 +428,7 @@ bool Gateways::initObjects()
 	mail.loginLabel = tr("Mail");
 	mail.loginField = "username";
 	mail.passwordField = "password";
-	mail.homeContactPattern = "^"MAIL_NODE_PATTERN"@"JID_DOMAIN_PATTERN"$";
+	mail.homeContactPattern = "^" MAIL_NODE_PATTERN "@" JID_DOMAIN_PATTERN "$";
 	mail.availContactPattern = mail.homeContactPattern;
 	FGateDescriptors.append(mail);
 
