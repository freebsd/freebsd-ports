*** smbval/smblib.c.orig	Sat Aug 16 09:42:32 2003
--- smbval/smblib.c	Sat Aug 16 09:43:34 2003
***************
*** 338,344 ****
  
    }
  
!   strcpy(pword, PassWord);
  #ifdef PAM_SMB_ENC_PASS
    if (Con_Handle -> encrypt_passwords)
    {
--- 338,344 ----
  
    }
  
!   (void)strlcpy(pword, PassWord, sizeof(pword));
  #ifdef PAM_SMB_ENC_PASS
    if (Con_Handle -> encrypt_passwords)
    {
