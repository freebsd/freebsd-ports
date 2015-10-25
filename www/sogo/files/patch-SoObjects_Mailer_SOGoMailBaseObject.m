--- SoObjects/Mailer/SOGoMailBaseObject.m.orig	2015-09-16 18:41:30 UTC
+++ SoObjects/Mailer/SOGoMailBaseObject.m
@@ -32,9 +32,11 @@
 #import <NGExtensions/NSString+misc.h>
 #import <NGExtensions/NSURL+misc.h>
 #import <NGImap4/NGImap4Connection.h>
+#import <NGImap4/NGImap4Client.h>
 
 #import <SOGo/SOGoCache.h>
 #import <SOGo/SOGoUser.h>
+#import <SOGo/WORequest+SOGo.h>
 
 #import "SOGoMailAccount.h"
 #import "SOGoMailManager.h"
