*** dspam.c	Fri Jan 28 14:33:46 2005
--- dspam.c.orig	Fri Jan 28 14:33:40 2005
***************
*** 2748,2757 ****
      free(SIG.data);
    nt_destroy (inoc_users);
    nt_destroy (classify_users);
!   if (CTX)
      dspam_destroy (CTX);
    return result;
- 
  }
  
  int
--- 2748,2760 ----
      free(SIG.data);
    nt_destroy (inoc_users);
    nt_destroy (classify_users);
!   if (CTX) {
!     if (CTX->signature == &SIG) {
!       CTX->signature = NULL;
!      }
      dspam_destroy (CTX);
+   }
    return result;
  }
  
  int
