--- test.rb.orig	Sun Dec  3 22:36:02 2000
+++ test.rb	Thu Jun 21 23:06:55 2001
@@ -11,6 +11,9 @@
 when /^SunOS/
   $DEV = "/quotas"
   $QUOTAS = "/quotas"
+when /BSD/
+  $DEV = "/mnt/test"
+  $QUOTAS = "/mnt/test/quota.user"
 end
 
 print("user id: ")
