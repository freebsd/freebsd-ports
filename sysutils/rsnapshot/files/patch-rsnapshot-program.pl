# Description: rsnapshot doesn't build with perl >= 5.18 pod2man otherwise
# Issue ID: https://github.com/DrHyde/rsnapshot/issues/8
#
--- rsnapshot-program.pl.orig	2014-12-07 09:17:47 UTC
+++ rsnapshot-program.pl
@@ -6716,6 +6716,8 @@ Putting it all together (an example file
 
 =back
 
+=back
+
 =head1 USAGE
 
 B<rsnapshot> can be used by any user, but for system-wide backups
