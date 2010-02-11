--- lib/Mail/SpamAssassin/Conf/Parser.pm	(revision 903394)
+++ lib/Mail/SpamAssassin/Conf/Parser.pm	(working copy)
@@ -1127,7 +1127,8 @@
   }
   if ($type == $Mail::SpamAssassin::Conf::TYPE_HEAD_TESTS)
   {
-    if ($text =~ /^!?defined\([A-Za-z][A-Za-z0-9-]*\)$/) {
+    # RFC 5322 section 3.6.8, ftext printable US-ASCII chars not including ":"
+    if ($text =~ /^!?defined\([!-9;-\176]+\)$/) {
       # fine, implements 'exists:'
     } else {
       my ($pat) = ($text =~ /^\s*\S+\s*(?:\=|\!)\~\s*(\S.*?\S)\s*$/);

