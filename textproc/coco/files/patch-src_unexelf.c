diff -rBbc src/unexelf.c src/unexelf.c
*** src/unexelf.c	Tue Aug 18 14:48:41 1998
--- src/unexelf.c	Sat Dec 29 03:49:32 2001
***************
*** 678,684 ****
    if (n < 0)
      fatal ("Couldn't find segment next to .bss in %s\n", old_name, 0);
  
!   NEW_PROGRAM_H (n).p_filesz += new_data2_size;
    NEW_PROGRAM_H (n).p_memsz = NEW_PROGRAM_H (n).p_filesz;
  
  #if 0 /* Maybe allow section after data2 - does this ever happen? */
--- 678,685 ----
    if (n < 0)
      fatal ("Couldn't find segment next to .bss in %s\n", old_name, 0);
  
! /*  NEW_PROGRAM_H (n).p_filesz += new_data2_size; */
!   NEW_PROGRAM_H (n).p_filesz = new_bss_addr - NEW_PROGRAM_H (n).p_vaddr; /* From emacs 20.3 */
    NEW_PROGRAM_H (n).p_memsz = NEW_PROGRAM_H (n).p_filesz;
  
  #if 0 /* Maybe allow section after data2 - does this ever happen? */
***************
*** 849,855 ****
  
        for (; symp < symendp; symp ++)
  	if (strcmp ((char *) (symnames + symp->st_name), "_end") == 0
! 	    || strcmp ((char *) (symnames + symp->st_name), "_edata") == 0)
  	  memcpy (&symp->st_value, &new_bss_addr, sizeof (new_bss_addr));
      }
  
--- 850,858 ----
  
        for (; symp < symendp; symp ++)
  	if (strcmp ((char *) (symnames + symp->st_name), "_end") == 0
! 	    || strcmp ((char *) (symnames + symp->st_name), "end") == 0
! 	    || strcmp ((char *) (symnames + symp->st_name), "_edata") == 0
! 	    || strcmp ((char *) (symnames + symp->st_name), "edata") == 0)
  	  memcpy (&symp->st_value, &new_bss_addr, sizeof (new_bss_addr));
      }
  
