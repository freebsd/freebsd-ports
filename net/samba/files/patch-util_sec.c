*** source/lib/util_sec.c	Wed Jul 17 15:47:49 2002
--- source/lib/util_sec.c.neu	Mon Jun  2 15:30:43 2003
***************
*** 112,119 ****
--- 112,121 ----
  				 (int)rgid, (int)egid,
  				 (int)getgid(), (int)getegid(),
  				 (int)getuid(), (int)geteuid()));
+ #if 0
  			smb_panic("failed to set gid\n");
  			exit(1);
+ #endif
  		}
  	}
  }
