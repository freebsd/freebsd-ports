--- Users/Users.pm.orig	2009-11-02 17:44:21.000000000 -0500
+++ Users/Users.pm	2010-01-10 19:03:46.000000000 -0500
@@ -378,10 +379,17 @@ sub get
   my ($ifh, @users, %users_hash);
   my (@line, @users);
 
+  $NO_SHELL = "/usr/bin/nologin"; # lpm: Sets login field to nologin, if it's left to null, stb can't read passwd file
+				  # This is important, because in FreeBSD if there is a null in this field, stb 
+				  # won't create the user account.  This is one of the reasons why users couldn't
+				  # be created in FreeBSD for gnome using stb! :)  Problem solved.
+  
   # Find the passwd file.
   $ifh = &Utils::File::open_read_from_names(@passwd_names);
   return unless ($ifh);
 
+ 
+
   while (<$ifh>)
   {
     chomp;
@@ -396,6 +404,9 @@ sub get
     push @comment, "" while (scalar (@comment) < 5);
     $line[$COMMENT] = [@comment];
 
+   
+    $line[$SHELL] = $NO_SHELL if(!$line[$SHELL] || $line[$SHELL] eq ""); # check for null or empty login field, and set
+
     $users_hash{$login} = [@line];
   }
 
@@ -439,32 +450,32 @@ sub get
 sub del_user
 {
 	my ($user) = @_;
-  my (@command);
+  my ($command);
 	
   if ($Utils::Backend::tool{"system"} eq "FreeBSD")
   {
-    @command = ($cmd_pw, "userdel", "-n", $$user[$LOGIN]);
+    $command = "$cmd_pw userdel -n \'" . $$user[$LOGIN] . "\' -r ";
   }
   else
   {
     if ($cmd_deluser)
     {
-      @command = ($cmd_deluser, $$user[$LOGIN]);
+      $command = "$cmd_deluser '". $$user[$LOGIN] . "'";
     }
     else
     {
-      @command = ($cmd_userdel, $$user[$LOGIN]);
+      $command = "$cmd_userdel \'" . $$user[$LOGIN] . "\'";
     }
   }
 
-  &Utils::File::run (@command);
+  &Utils::File::run ($command);
 }
 
 sub change_user_chfn
 {
   my ($login, $old_comment, $comment) = @_;
   my ($fname, $office, $office_phone, $home_phone);
-  my (@command, $str);
+  my ($command, $str);
 
   return if !$login;
 
@@ -474,15 +485,14 @@ sub change_user_chfn
 
   if ($Utils::Backend::tool{"system"} eq "FreeBSD")
   {
-    @command = ($cmd_pw, "usermod", "-n", $login,
-                                    "-c", $str);
+    $command = "$cmd_pw usermod -n " . $login . " -c \'" . $str . "\'";
   }
   else
   {
-    @command = ($cmd_usermod, "-c", $str, $login);
+    $command = "$cmd_usermod -c \'" . $str . "\' " . $login;
   }
 
-  &Utils::File::run (@command);
+  &Utils::File::run ($command);
 }
 
 # modifies /etc/shadow directly, not good practice,
@@ -516,11 +526,11 @@ sub modify_shadow_password
 sub set_passwd
 {
   my ($login, $password) = @_;
-  my ($pwdpipe);
+  my ($pwdpipe, $command);
 
   if ($Utils::Backend::tool{"system"} eq "FreeBSD")
   {
-    my ($command);
+
     $command = "$cmd_pw usermod -H 0";
     $pwdpipe = &Utils::File::run_pipe_write ($command);
     print $pwdpipe $password;
@@ -532,105 +542,156 @@ sub set_passwd
   }
   else
   {
-    my (@command);
-    @command = ($cmd_usermod, "-p", $password, $login);
+    $command = "$cmd_usermod " .
+        " -p '" . $password . "' " . $login;
 
-    &Utils::File::run (@command);
+    &Utils::File::run ($command);
   }
 }
 
 sub add_user
 {
-	my ($user) = @_;
-	my ($home_parents, $tool_mkdir);
+  my ($user) = @_; # paramaters coming into function.
+  my ($home_parents, $tool_mkdir);
   
   $tool_mkdir = &Utils::File::locate_tool ("mkdir");
 
   if ($Utils::Backend::tool{"system"} eq "FreeBSD")
   {
+    # Author:    Larry P. Maloney (larry@kiputers.com) or larrypatrickmaloney@yahoo.com
+    # Date:      09/09/2009, 10/07/09, 12/30/2009
+    # Provides:  User creation in FreeBSD
+    # Requires:  All services that GDM or "gnome_enable" in rc.conf would start
+    #            Cleaned up /etc/passwd file (NULLS are NOT permited in /etc/passwd, and passwd
+    #            file must be perfect (no screwed up fields)
+    #            Update: 10/07/09, added code to automatically add /usr/bin/nologin to records in /etc/passwd
+    #
+    # Notes:  These changes will enable user creation on FreeBSD.
+    #         The creation of the user account requires that the /etc/passwd file
+    #         be cleaned first.  (Need to  add code to pre-process /etc/passwd)  Each password record in the
+    #         file must have values.  No NULLS allowed, or stb will not be able to edit the records.
+    #         On FreeBSD there is a "toor" account.  This account by default has a NULL value for
+    #         the login program.  This NULL should be substitued with /usr/local/nologin
+    #         Please make sure all your fields are without NULL's before trying to edit/add a user.
+    #
+    #  New Feature:  This patch will enable creation of the user account WITH the additional fields,
+    #                Full Name, Location, Home Phone and Work Phone.
+    #
+    #  Changes:  I essentially did 3 things.  One, cleaned up the /etc/passwd file on my local machine
+    #            Correctly built the string to be passed to the 'pw' command in BSD (with the -C option
+    #            for comments.  And Three, added the call to Utils::Run.
+    #
+    #  ToDo:     Enable creation of accounts WITHOUT passwords
+    #            Automatically clean up (swap nulls with default values) in /etc/passwd file.
+  
     my $pwdpipe;
     my $home;
+    my $user_login;  # lpm: $user was redfined THIS IS THE DAMN PROBLEM!  User was redfined and set to empty!
 
-    # FreeBSD doesn't create the home directory
     $home = $$user[$HOME];
-    &Utils::File::run ($tool_mkdir, "-p", $home);
+    $user_login = $$user[$LOGIN];
 
+    #get the group name (not just the ID)
+     $group_command = "$cmd_pw groupshow -g " . "\'" .$$user[$GID] . "\'";
+     $group_name = qx($group_command);
+     @tokens=split(/:/,$group_name);
+     $group_string = $tokens[0];
+
+
+    #modified by lpm, 09/04/09
     $command = "$cmd_pw useradd " .
         " -n \'" . $$user[$LOGIN] . "\'" .
         " -u \'" . $$user[$UID]   . "\'" .
         " -d \'" . $$user[$HOME]  . "\'" .
         " -g \'" . $$user[$GID]   . "\'" .
         " -s \'" . $$user[$SHELL] . "\'" .
-        " -H 0"; # pw(8) reads password from STDIN
+        " -m -h 0"; # pw(8) reads password from STDIN
+  
+   # added by lpm to get comment fields.
+   $aref=@$user[$COMMENT];   # default is $$user[$COMMENT]
+   $comment = "@$aref[0],@$aref[1],@$aref[2],@$aref[3],";
+    
+   $command = $command . " -c \"" .  $comment . "\""; #comment field must have quotes included before sending to pw command.
 
-#    @command = ($cmd_pw, "useradd", "-n", $$user[$LOGIN],
-#                                    "-u", $$user[$UID],
-#                                    "-d", $$user[$HOME],
-#                                    "-g", $$user[$GID],
-#                                    "-s", $$user[$SHELL],
-#                                    "-H", "0"); # pw(8) reads password from STDIN
+   $pwdpipe = &Utils::File::run_pipe_write ($command);
 
-    $pwdpipe = &Utils::File::run_pipe_write ($command);
-    print $pwdpipe $$user[$PASSWD];
-    &Utils::File::close_file ($pwdpipe);
+   print $pwdpipe $$user[$PASSWD];
+
+   #&Utils::File::run ($command); #added by lpm, doesn't look like the command is getting run?
+   
+  
+
+   {     
+     $group_command = "$cmd_pw groupshow -g " . "\'" .$$user[$GID] . "\'";
+     $group_name = qx($group_command);
+
+      @tokens=split(/:/,$group_name);
+      $group_string = $tokens[0];
+    }
+
+
+
+   &Utils::File::close_file ($pwdpipe);
+   &Utils::File::run ("chown -R $user_login $home");
+      
   }
   elsif ($Utils::Backend::tool{"system"} eq "SunOS")
   {
     $home_parents = $$user[$HOME];
     $home_parents =~ s/\/+[^\/]+\/*$//;
-    &Utils::File::run ($tool_mkdir, "-p", $home_parents);
+    &Utils::File::run ("$tool_mkdir -p $home_parents");
 
-    @command = ($cmd_useradd, "-d", $$user[$HOME],
-                              "-g", $$user[$GID],
-                              "-s", $$user[$SHELL],
-                              "-u", $$user[$UID],
-                                    $$user[$LOGIN]);
+    $command = "$cmd_useradd" .
+        " -d \'" . $$user[$HOME]  . "\'" .
+        " -g \'" . $$user[$GID]   . "\'" .
+        " -s \'" . $$user[$SHELL] . "\'" .
+        " -u \'" . $$user[$UID]   . "\'" .
+        " \'"    . $$user[$LOGIN] . "\'";
 
-    &Utils::File::run (@command);
+    &Utils::File::run ($command);
     &modify_shadow_password ($$user[$LOGIN], $$user[$PASSWD]);
   }
   else
   {
     $home_parents = $$user[$HOME];
     $home_parents =~ s/\/+[^\/]+\/*$//;
-    &Utils::File::run ($tool_mkdir, "-p", $home_parents);
+    &Utils::File::run ("$tool_mkdir -p $home_parents");
 
     if ($cmd_adduser &&
         $Utils::Backend::tool{"platform"} !~ /^slackware/ &&
         $Utils::Backend::tool{"platform"} !~ /^archlinux/ &&
-        $Utils::Backend::tool{"platform"} !~ /^redhat/ &&
-        $Utils::Backend::tool{"platform"} !~ /^gentoo/)
+        $Utils::Backend::tool{"platform"} !~ /^redhat/)
     {
       # use adduser if available and valid (slackware one is b0rk)
       # set empty gecos fields and password, they will be filled out later
-      @command = ($cmd_adduser, "--gecos", "",
-                                "--disabled-password",
-                                "--home", $$user[$HOME],
-                                "--gid", $$user[$GID],
-                                "--shell", $$user[$SHELL],
-                                "--uid", $$user[$UID],
-                                         $$user[$LOGIN]);
+      $command = "$cmd_adduser --gecos '' --disabled-password" .
+          " --home \'"  . $$user[$HOME]   . "\'" .
+          " --gid \'"   . $$user[$GID]    . "\'" .
+          " --shell \'" . $$user[$SHELL]  . "\'" .
+          " --uid \'"   . $$user[$UID]    . "\'" .
+          " \'"         . $$user[$LOGIN]  . "\'";
 
-      &Utils::File::run (@command);
+      &Utils::File::run ($command);
 
       # password can't be set in non-interactive
       # mode with adduser, call usermod instead
-      @command = ($cmd_usermod, "-p", $$user[$PASSWD], $$user[$LOGIN]);
+      $command = "$cmd_usermod " .
+          " -p '" . $$user[$PASSWD] . "' " . $$user[$LOGIN];
 
-      &Utils::File::run (@command);
+      &Utils::File::run ($command);
     }
     else
     {
       # fallback to useradd
-      @command = ($cmd_useradd, "-m",
-                                "-d", $$user[$HOME],
-                                "-g", $$user[$GID],
-                                "-p", $$user[$PASSWD],
-                                "-s", $$user[$SHELL],
-                                "-u", $$user[$UID],
-                                      $$user[$LOGIN]);
+      $command = "$cmd_useradd -m" .
+          " -d \'" . $$user[$HOME]   . "\'" .
+          " -g \'" . $$user[$GID]    . "\'" .
+          " -p \'" . $$user[$PASSWD] . "\'" .
+          " -s \'" . $$user[$SHELL]  . "\'" .
+          " -u \'" . $$user[$UID]    . "\'" .
+          " \'"    . $$user[$LOGIN]  . "\'";
 
-      &Utils::File::run (@command);
+      &Utils::File::run ($command);
     }
   }
 
@@ -644,14 +705,14 @@ sub change_user
   if ($Utils::Backend::tool{"system"} eq "FreeBSD")
   {
     my $pwdpipe;
-
+    #lpm note:   You can add -k here for a skelton directory to build user directories with default files! :)
     $command = "$cmd_pw usermod \'" . $$old_user[$LOGIN] . "\'" .
         " -l \'" . $$new_user[$LOGIN] . "\'" .
         " -u \'" . $$new_user[$UID]   . "\'" .
         " -d \'" . $$new_user[$HOME]  . "\'" .
         " -g \'" . $$new_user[$GID]   . "\'" .
         " -s \'" . $$new_user[$SHELL] . "\'" .
-        " -H 0"; # pw(8) reads password from STDIN
+        " -h 0"; # pw(8) reads password from STDIN
 
     $pwdpipe = &Utils::File::run_pipe_write ($command);
     print $pwdpipe $$new_user[$PASSWD];
@@ -659,27 +720,29 @@ sub change_user
   }
   elsif ($Utils::Backend::tool{"system"} eq "SunOS")
   {
-    @command = ($cmd_usermod, "-d", $$new_user[$HOME],
-                              "-g", $$new_user[$GID],
-                              "-l", $$new_user[$LOGIN],
-                              "-s", $$new_user[$SHELL],
-                              "-u", $$new_user[$UID],
-                                    $$old_user[$LOGIN]);
+    $command = "$cmd_usermod" .
+        " -d \'" . $$new_user[$HOME]   . "\'" .
+        " -g \'" . $$new_user[$GID]    . "\'" .
+        " -l \'" . $$new_user[$LOGIN]  . "\'" .
+        " -s \'" . $$new_user[$SHELL]  . "\'" .
+        " -u \'" . $$new_user[$UID]    . "\'" .
+        " \'" . $$old_user[$LOGIN] . "\'";
 
-    &Utils::File::run (@command);
+    &Utils::File::run ($command);
     &modify_shadow_password ($$new_user[$LOGIN], $$new_user[$PASSWD]);
   }
   else
   {
-    @command = ($cmd_usermod, "-d", $$new_user[$HOME],
-                              "-g", $$new_user[$GID],
-                              "-l", $$new_user[$LOGIN],
-                              "-p", $$new_user[$PASSWD],
-                              "-s", $$new_user[$SHELL],
-                              "-u", $$new_user[$UID],
-                                    $$old_user[$LOGIN]);
+    $command = "$cmd_usermod" .
+        " -d \'" . $$new_user[$HOME]   . "\'" .
+        " -g \'" . $$new_user[$GID]    . "\'" .
+        " -l \'" . $$new_user[$LOGIN]  . "\'" .
+        " -p \'" . $$new_user[$PASSWD] . "\'" .
+        " -s \'" . $$new_user[$SHELL]  . "\'" .
+        " -u \'" . $$new_user[$UID]    . "\'" .
+        " \'" . $$old_user[$LOGIN] . "\'";
 
-    &Utils::File::run (@command);
+    &Utils::File::run ($command);
   }
 
   &change_user_chfn ($$new_user[$LOGIN], $$old_user[$COMMENT], $$new_user[$COMMENT]);
