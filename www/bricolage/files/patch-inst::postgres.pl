*** inst/postgres.pl.orig	Thu Jul 14 00:03:08 2005
--- inst/postgres.pl	Fri Aug  5 22:52:39 2005
***************
*** 36,50 ****
  use File::Spec::Functions;
  use Data::Dumper;
  
  print "\n\n==> Probing PostgreSQL Configuration <==\n\n";
  
  our %PG;
  
  # setup some defaults
! $PG{root_user} = 'postgres';
  $PG{root_pass} = '';
  $PG{sys_user}  = 'bric';
! $PG{sys_pass}  = 'NONE';
  $PG{db_name}   = 'bric';
  $PG{host_name} = '';
  $PG{host_port} = '';
--- 36,54 ----
  use File::Spec::Functions;
  use Data::Dumper;
  
+ # check whether questions should be asked
+ our $QUIET;
+ $QUIET = 1 if $ARGV[0] and $ARGV[0] eq 'QUIET';
+ 
  print "\n\n==> Probing PostgreSQL Configuration <==\n\n";
  
  our %PG;
  
  # setup some defaults
! $PG{root_user} = 'pgsql';
  $PG{root_pass} = '';
  $PG{sys_user}  = 'bric';
! $PG{sys_pass}  = ''; # Ask the user to deal with it
  $PG{db_name}   = 'bric';
  $PG{host_name} = '';
  $PG{host_port} = '';
***************
*** 58,65 ****
  get_bin_dir();
  get_psql();
  get_version();
! get_users();
! get_host();
  get_version();
  
  # all done, dump out apache database, announce success and exit
--- 62,70 ----
  get_bin_dir();
  get_psql();
  get_version();
! # Skip for automated installation
! #get_users();
! #get_host();
  get_version();
  
  # all done, dump out apache database, announce success and exit
***************
*** 122,134 ****
  # ask the user for user settings
  sub get_users {
      print "\n";
!     ask_confirm("Postgres Root Username", \$PG{root_user});
      ask_password("Postgres Root Password (leave empty for no password)",
  		\$PG{root_pass});
  
      while(1) {
  	$PG{system_user} = $PG{root_user};
! 	ask_confirm("Postgres System Username", \$PG{system_user});
  	$PG{system_user_uid} = (getpwnam($PG{system_user}))[2];
  	last if defined $PG{system_user_uid};
  	print "User \"$PG{system_user}\" not found!  This user must exist ".
--- 127,144 ----
  # ask the user for user settings
  sub get_users {
      print "\n";
!     if ($QUIET) {
!         print "Postgres Root Username ". $PG{root_user} ."\n";
!     }
!     else {
!         ask_confirm("Postgres Root Username", \$PG{root_user});
!     }
      ask_password("Postgres Root Password (leave empty for no password)",
  		\$PG{root_pass});
  
      while(1) {
  	$PG{system_user} = $PG{root_user};
! 	ask_confirm("Postgres System Username", \$PG{system_user}) unless $QUIET;
  	$PG{system_user_uid} = (getpwnam($PG{system_user}))[2];
  	last if defined $PG{system_user_uid};
  	print "User \"$PG{system_user}\" not found!  This user must exist ".
