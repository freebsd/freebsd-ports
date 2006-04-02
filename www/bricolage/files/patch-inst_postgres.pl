*** inst/postgres.pl.orig	Sun Apr  2 10:26:59 2006
--- inst/postgres.pl	Sun Apr  2 10:27:55 2006
***************
*** 135,141 ****
  
      unless ($PG{host_name}) {
          $PG{system_user} = $PG{root_user};
!         while(1) {
              ask_confirm("Postgres System Username", \$PG{system_user}, $QUIET);
              $PG{system_user_uid} = (getpwnam($PG{system_user}))[2];
              last if defined $PG{system_user_uid};
--- 135,141 ----
  
      unless ($PG{host_name}) {
          $PG{system_user} = $PG{root_user};
!         while(!$QUIET) {
              ask_confirm("Postgres System Username", \$PG{system_user}, $QUIET);
              $PG{system_user_uid} = (getpwnam($PG{system_user}))[2];
              last if defined $PG{system_user_uid};
