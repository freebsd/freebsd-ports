Index: kuser/kuser_locl.h
===================================================================
RCS file: /home/kth-krb/heimdal/kuser/kuser_locl.h,v
retrieving revision 1.12
retrieving revision 1.13
diff -c -c -r1.12 -r1.13
*** kuser/kuser_locl.h	2 Dec 1999 17:05:01 -0000	1.12
--- kuser/kuser_locl.h	21 Jan 2003 14:13:51 -0000	1.13
***************
*** 85,89 ****
--- 85,90 ----
  #include <sys/ioccom.h>
  #endif
  #include <kafs.h>
+ #include "crypto-headers.h" /* for des_read_pw_string */
  
  #endif /* __KUSER_LOCL_H__ */
