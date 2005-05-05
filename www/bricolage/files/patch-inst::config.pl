*** inst/config.pl.orig	Fri Mar 18 17:12:51 2005
--- inst/config.pl	Tue May  3 18:40:57 2005
***************
*** 36,41 ****
--- 36,45 ----
  use Config;
  use Cwd;
  
+ # check whether questions should be asked
+ our $QUIET;
+ $QUIET = 1 if $ARGV[0] and $ARGV[0] eq 'QUIET';
+ 
  print "\n\n==> Gathering User Configuration <==\n\n";
  our %CONFIG;
  
***************
*** 73,94 ****
  
  END
  
!     $CONFIG{set} = ask_choice("Your choice?",
!                               [ "s", "m" ], "m");
  
      # setup the default
      if ($CONFIG{set} eq 's') {
          # single system defaults
          $CONFIG{BRICOLAGE_ROOT}  = '/usr/local/bricolage';
          $CONFIG{TEMP_DIR}        = tmpdir();
!         $CONFIG{MODULE_DIR}      = $Config{sitelib};
!         $CONFIG{BIN_DIR}         = $Config{scriptdir};
!         $CONFIG{MAN_DIR}         = $Config{man3dir};
          $CONFIG{MASON_COMP_ROOT} = '$CONFIG{BRICOLAGE_ROOT}/comp';
          $CONFIG{MASON_DATA_ROOT} = '$CONFIG{BRICOLAGE_ROOT}/data';
  
          # remove man3 trailer
!         $CONFIG{MAN_DIR} =~ s!/man3!!;
  
          # construct default system-wide log directory based on Apache
          # error_log setting
--- 77,101 ----
  
  END
  
!     $CONFIG{set} = "s";
!     ask_choice("Your choice?", 
!                [ "s", "m" ], $CONFIG{set}) unless $QUIET;
  
      # setup the default
      if ($CONFIG{set} eq 's') {
          # single system defaults
          $CONFIG{BRICOLAGE_ROOT}  = '/usr/local/bricolage';
          $CONFIG{TEMP_DIR}        = tmpdir();
!         $CONFIG{MODULE_DIR}      = '/usr/local/lib/perl5/site_perl/5.8.2/ '; #$Config{sitelib};
!         $CONFIG{BIN_DIR}         = '/usr/local/bin'; #$Config{scriptdir};
!         $CONFIG{MAN1_DIR}         = '/usr/local/man/man1'; #$Config{man1dir};
!         $CONFIG{MAN3_DIR}         = '/usr/local/lib/perl5/5.8.2/man/man3'; #$Config{man3dir};
          $CONFIG{MASON_COMP_ROOT} = '$CONFIG{BRICOLAGE_ROOT}/comp';
          $CONFIG{MASON_DATA_ROOT} = '$CONFIG{BRICOLAGE_ROOT}/data';
  
          # remove man3 trailer
!         $CONFIG{MAN1_DIR} =~ s!/man1!!;
!         $CONFIG{MAN3_DIR} =~ s!/man3!!;
  
          # construct default system-wide log directory based on Apache
          # error_log setting
***************
*** 115,121 ****
          $CONFIG{TEMP_DIR}         = '$CONFIG{BRICOLAGE_ROOT}/tmp';
          $CONFIG{MODULE_DIR}       = '$CONFIG{BRICOLAGE_ROOT}/lib';
          $CONFIG{BIN_DIR}          = '$CONFIG{BRICOLAGE_ROOT}/bin';
!         $CONFIG{MAN_DIR}          = '$CONFIG{BRICOLAGE_ROOT}/man';
          $CONFIG{LOG_DIR}          = '$CONFIG{BRICOLAGE_ROOT}/log';
          $CONFIG{PID_FILE}         = '$CONFIG{BRICOLAGE_ROOT}/log/httpd.pid';
          $CONFIG{MASON_COMP_ROOT}  = '$CONFIG{BRICOLAGE_ROOT}/comp';
--- 122,129 ----
          $CONFIG{TEMP_DIR}         = '$CONFIG{BRICOLAGE_ROOT}/tmp';
          $CONFIG{MODULE_DIR}       = '$CONFIG{BRICOLAGE_ROOT}/lib';
          $CONFIG{BIN_DIR}          = '$CONFIG{BRICOLAGE_ROOT}/bin';
!         $CONFIG{MAN1_DIR}          = '$CONFIG{BRICOLAGE_ROOT}/man';
!         $CONFIG{MAN3_DIR}          = $CONFIG{MAN1_DIR};
          $CONFIG{LOG_DIR}          = '$CONFIG{BRICOLAGE_ROOT}/log';
          $CONFIG{PID_FILE}         = '$CONFIG{BRICOLAGE_ROOT}/log/httpd.pid';
          $CONFIG{MASON_COMP_ROOT}  = '$CONFIG{BRICOLAGE_ROOT}/comp';
***************
*** 125,131 ****
  
  sub confirm_settings {
    my $default_root = $CONFIG{BRICOLAGE_ROOT};
!   ask_confirm("\nBricolage Root Directory", \$CONFIG{BRICOLAGE_ROOT});
  
    # make sure this directory isn't the same at the source directory
    if (canonpath($CONFIG{BRICOLAGE_ROOT}) eq canonpath(cwd())) {
--- 133,144 ----
  
  sub confirm_settings {
    my $default_root = $CONFIG{BRICOLAGE_ROOT};
!   if ($QUIET) {
!     print "\bBricolage Root Directory ". $CONFIG{BRICOLAGE_ROOT} ."\n";
!   }
!   else {
!     ask_confirm("\nBricolage Root Directory", \$CONFIG{BRICOLAGE_ROOT});
!   }
  
    # make sure this directory isn't the same at the source directory
    if (canonpath($CONFIG{BRICOLAGE_ROOT}) eq canonpath(cwd())) {
***************
*** 142,165 ****
        -e catfile($CONFIG{BRICOLAGE_ROOT}, "conf", "bricolage.conf")) {
        print "That directory already contains a Bricolage installation.\n";
        print "Consider running `make upgrade`, instead.\n";
!       exit 1 unless ask_yesno("Continue and overwrite existing installation? ".
!                               "[no] ", 0);
    }
  
    # some prefs are based on BRICOLAGE_ROOT, need to eval them now
!   foreach (qw(TEMP_DIR MODULE_DIR BIN_DIR MAN_DIR LOG_DIR PID_FILE
                MASON_COMP_ROOT MASON_DATA_ROOT)) {
      $CONFIG{$_} = eval qq{"$CONFIG{$_}"};
    }
  
!   ask_confirm("Temporary Directory",       \$CONFIG{TEMP_DIR});
!   ask_confirm("Perl Module Directory",     \$CONFIG{MODULE_DIR});
!   ask_confirm("Executable Directory",      \$CONFIG{BIN_DIR});
!   ask_confirm("Man-Page Directory (! to skip)", \$CONFIG{MAN_DIR});
!   ask_confirm("Log Directory",             \$CONFIG{LOG_DIR});
!   ask_confirm("PID File Location",         \$CONFIG{PID_FILE});
    $CONFIG{PID_FILE} = catfile($CONFIG{PID_FILE}, 'httpd.pid')
      if -d $CONFIG{PID_FILE};
-   ask_confirm("Mason Component Directory", \$CONFIG{MASON_COMP_ROOT});
-   ask_confirm("Mason Data Directory",      \$CONFIG{MASON_DATA_ROOT});
  }
--- 155,192 ----
        -e catfile($CONFIG{BRICOLAGE_ROOT}, "conf", "bricolage.conf")) {
        print "That directory already contains a Bricolage installation.\n";
        print "Consider running `make upgrade`, instead.\n";
!       exit 1 unless ($QUIET or ask_yesno("Continue and overwrite existing installation? ".
!                               "[no] ", 0));
    }
  
    # some prefs are based on BRICOLAGE_ROOT, need to eval them now
!   foreach (qw(TEMP_DIR MODULE_DIR BIN_DIR MAN1_DIR MAN3_DIR LOG_DIR PID_FILE
                MASON_COMP_ROOT MASON_DATA_ROOT)) {
      $CONFIG{$_} = eval qq{"$CONFIG{$_}"};
    }
  
!   if ($QUIET) {
!     print "Temporary Directory ".       $CONFIG{TEMP_DIR} ."\n";
!     print "Perl Module Directory ".     $CONFIG{MODULE_DIR} ."\n";
!     print "Executable Directory ".      $CONFIG{BIN_DIR} ."\n";
!     print "Man1-Page Directory ".        $CONFIG{MAN1_DIR} ."\n";
!     print "Man3-Page Directory ".        $CONFIG{MAN3_DIR} ."\n";
!     print "Log Directory ".             $CONFIG{LOG_DIR} ."\n";
!     print "PID File Location ".         $CONFIG{PID_FILE} ."\n";
!     print "Mason Component Directory ". $CONFIG{MASON_COMP_ROOT} ."\n";
!     print "Mason Data Directory ".      $CONFIG{MASON_DATA_ROOT} ."\n";
!   }
!   else {
!     ask_confirm("Temporary Directory",       \$CONFIG{TEMP_DIR});
!     ask_confirm("Perl Module Directory",     \$CONFIG{MODULE_DIR});
!     ask_confirm("Executable Directory",      \$CONFIG{BIN_DIR});
!     ask_confirm("Man1-Page Directory (! to skip)", \$CONFIG{MAN1_DIR});
!     ask_confirm("Man3-Page Directory (! to skip)", \$CONFIG{MAN3_DIR});
!     ask_confirm("Log Directory",             \$CONFIG{LOG_DIR});
!     ask_confirm("PID File Location",         \$CONFIG{PID_FILE});
!     ask_confirm("Mason Component Directory", \$CONFIG{MASON_COMP_ROOT});
!     ask_confirm("Mason Data Directory",      \$CONFIG{MASON_DATA_ROOT});
!   }
    $CONFIG{PID_FILE} = catfile($CONFIG{PID_FILE}, 'httpd.pid')
      if -d $CONFIG{PID_FILE};
  }
