*** ntlm/ntlmdes.c.orig	Wed Feb 12 07:08:05 2003
--- ntlm/ntlmdes.c	Wed Feb 12 07:08:24 2003
***************
*** 60,67 ****
    des_ecb_encrypt (iv, result, ks, DES_ENCRYPT);
  
    /* paranoia */
!   memset (key, 0, sizeof key);
!   memset (ks, 0, sizeof ks);
  }
  
  /* Copy and convert to upper case.  If supplied string is shorter than the
--- 60,67 ----
    des_ecb_encrypt (iv, result, ks, DES_ENCRYPT);
  
    /* paranoia */
!   memset (&key, 0, sizeof key);
!   memset (&ks, 0, sizeof ks);
  }
  
  /* Copy and convert to upper case.  If supplied string is shorter than the
