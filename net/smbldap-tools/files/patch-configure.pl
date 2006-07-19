--- configure.pl.orgi	Wed Jul 12 18:36:29 2006
+++ configure.pl	Wed Jul 12 18:40:30 2006
@@ -49,7 +49,7 @@
 print "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
 
 # we first check if Samba is up and running
-my $test_smb=`pidof smbd`;
+my $test_smb=`pgrep -x smbd`;
 chomp($test_smb);
 die "\nSamba need to be started first !\n" if ($test_smb eq "" || not defined $test_smb);
 
@@ -304,7 +304,7 @@
 
 my $default_computer_gidnumber=read_entry(". default computer gidNumber","","515",0);
 
-my $userLoginShell=read_entry(". default login shell","","/bin/bash",0);
+my $userLoginShell=read_entry(". default login shell","","/bin/sh",0);
 
 my $skeletonDir=read_entry(". default skeleton directory","","/etc/skel",0);
 
@@ -528,12 +528,12 @@
 # Allows not to use smbpasswd (if with_smbpasswd == 0 in smbldap_conf.pm) but
 # prefer Crypt::SmbHash library
 with_smbpasswd=\"0\"
-smbpasswd=\"/usr/bin/smbpasswd\"
+smbpasswd=\"%%LOCALBASE%%/bin/smbpasswd\"
 
 # Allows not to use slappasswd (if with_slappasswd == 0 in smbldap_conf.pm)
 # but prefer Crypt:: libraries
 with_slappasswd=\"0\"
-slappasswd=\"/usr/sbin/slappasswd\"
+slappasswd=\"%%LOCALBASE%%/sbin/slappasswd\"
 
 # comment out the following line to get rid of the default banner
 # no_banner=\"1\"
