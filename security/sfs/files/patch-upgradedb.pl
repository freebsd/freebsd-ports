--- sfsauthd/upgradedb.pl.orig	Fri Dec  6 01:26:18 2002
+++ sfsauthd/upgradedb.pl	Fri Dec  6 01:26:36 2002
@@ -16,7 +16,7 @@
 use vars qw [ $LOCATE $SFS_USERS @SFS_CONF_DIRS %FIELDS ];
 $LOCATE = "locate";
 $SFS_USERS = "sfs_users";
-@SFS_CONF_DIRS = qw [ /etc/sfs ];
+@SFS_CONF_DIRS = qw [ /usr/local/etc/sfs ];
 %FIELDS = ( user => 0, pubkey => 1, privs => 2, srpinfo => 3, privkey => 4); 
 
 
