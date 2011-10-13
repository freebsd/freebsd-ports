--- smbldap-config.pl.orig	2011-10-13 11:26:12.939953317 +0200
+++ smbldap-config.pl	2011-10-13 11:27:09.173960781 +0200
@@ -48,7 +48,7 @@
 print "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
 
 # we first check if Samba is up and running
-my $test_smb=`pidof smbd`;
+my $test_smb=`pgrep -x smbd`;
 chomp($test_smb);
 die "\nSamba needs to be started first !\n" if ($test_smb eq "" || not defined $test_smb);
 
@@ -290,7 +290,7 @@
 
 my $default_computer_gidnumber=read_entry(". default computer gidNumber","","515",0);
 
-my $userLoginShell=read_entry(". default login shell","","/bin/bash",0);
+my $userLoginShell=read_entry(". default login shell","","/bin/sh",0);
 
 my $skeletonDir=read_entry(". default skeleton directory","","/etc/skel",0);
 
@@ -441,7 +441,7 @@
 
 # Login defs
 # Default Login Shell
-# Ex: userLoginShell=\"/bin/bash\"
+# Ex: userLoginShell=\"/bin/sh\"
 userLoginShell=\"$userLoginShell\"
 
 # Home directory
@@ -511,12 +511,12 @@
 # Allows not to use smbpasswd (if with_smbpasswd=\"0\" in smbldap.conf) but
 # prefer Crypt::SmbHash library
 with_smbpasswd=\"0\"
-smbpasswd=\"/usr/bin/smbpasswd\"
+smbpasswd=\"%%LOCALBASE%%/bin/smbpasswd\"
 
 # Allows not to use slappasswd (if with_slappasswd=\"0\" in smbldap.conf)
 # but prefer Crypt:: libraries
 with_slappasswd=\"0\"
-slappasswd=\"/usr/sbin/slappasswd\"
+slappasswd=\"%%LOCALBASE%%/sbin/slappasswd\"
 
 # comment out the following line to get rid of the default banner
 # no_banner=\"1\"
