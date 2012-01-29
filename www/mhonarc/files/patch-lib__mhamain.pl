--- ./lib/mhamain.pl.orig	2012-01-16 14:28:02.000000000 -0800
+++ ./lib/mhamain.pl	2012-01-16 14:31:22.000000000 -0800
@@ -1561,7 +1561,7 @@
 ##	Create Index2MsgId if not defined
 ##
 sub defineIndex2MsgId {
-    if (!defined(%Index2MsgId)) {
+    if (!(%Index2MsgId)) {
 	foreach (keys %MsgId) {
 	    $Index2MsgId{$MsgId{$_}} = $_;
 	}
