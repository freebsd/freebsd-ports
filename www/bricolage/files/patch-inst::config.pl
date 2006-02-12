*** inst/config.pl.bak	Sun Jul 24 16:44:16 2005
--- inst/config.pl	Tue Jan 31 23:06:03 2006
***************
*** 156,167 ****
  
  
    # make sure this directory doesn't already house a Bricolage install
!   if (-e $CONFIG{BRICOLAGE_ROOT} and
!       -e catfile($CONFIG{BRICOLAGE_ROOT}, "conf", "bricolage.conf")) {
!       print "That directory already contains a Bricolage installation.\n";
!       print "Consider running `make upgrade`, instead.\n";
!       exit 1 unless ask_yesno("Continue and overwrite existing installation?", 0);
!   }
  
    # some prefs are based on BRICOLAGE_ROOT, need to eval them now
    foreach (qw(TEMP_DIR MODULE_DIR BIN_DIR MAN_DIR LOG_DIR PID_FILE
--- 156,167 ----
  
  
    # make sure this directory doesn't already house a Bricolage install
! #  if (-e $CONFIG{BRICOLAGE_ROOT} and
! #      -e catfile($CONFIG{BRICOLAGE_ROOT}, "conf", "bricolage.conf")) {
! #      print "That directory already contains a Bricolage installation.\n";
! #      print "Consider running `make upgrade`, instead.\n";
! #      exit 1 unless ask_yesno("Continue and overwrite existing installation?", 0);
! #  }
  
    # some prefs are based on BRICOLAGE_ROOT, need to eval them now
    foreach (qw(TEMP_DIR MODULE_DIR BIN_DIR MAN_DIR LOG_DIR PID_FILE
