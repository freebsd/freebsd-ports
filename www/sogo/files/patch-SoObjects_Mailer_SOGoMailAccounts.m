--- SoObjects/Mailer/SOGoMailAccounts.m.orig	2015-09-16 18:41:30 UTC
+++ SoObjects/Mailer/SOGoMailAccounts.m
@@ -41,6 +41,8 @@
 
 #define XMLNS_INVERSEDAV @"urn:inverse:params:xml:ns:inverse-dav"
 
+// TODO: prune redundant methods
+
 @implementation SOGoMailAccounts
 
 - (NSArray *) mailAccounts
@@ -206,6 +208,9 @@
 </D:multistatus>
 
 */
+
+/* No longer in use, causes objc-method-access warning
+
 - (NSException *) setDavMailsLabels: (NSString *) newLabels
 {
   id <DOMElement> documentElement, labelNode;
@@ -253,5 +258,6 @@
 
   return nil;
 }
+*/
 
 @end /* SOGoMailAccounts */
