*** lib/krb5/verify_krb5_conf.c.orig	Mon Aug 18 19:15:38 2003
--- lib/krb5/verify_krb5_conf.c	Mon Aug 18 19:15:57 2003
***************
*** 449,456 ****
  
  #if 0
  struct entry kdcdefaults_entries[] = {
!     { "kdc_ports, krb5_config_string, mit_entry },
!     { "v4_mode, krb5_config_string, mit_entry },
      { NULL }
  };
  #endif
--- 449,456 ----
  
  #if 0
  struct entry kdcdefaults_entries[] = {
!     { "kdc_ports", krb5_config_string, mit_entry },
!     { "v4_mode", krb5_config_string, mit_entry },
      { NULL }
  };
  #endif
