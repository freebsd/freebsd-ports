*** scsh/static.scm.orig	Fri Jan 11 12:50:39 2002
--- scsh/static.scm	Fri Jan 11 12:50:46 2002
***************
*** 128,134 ****
  	 options
  	 (or (options:temp-dir options)
  	     (getenv "TMPDIR") 
! 	     "/usr/tmp"))
  	(set-options:cc-command
  	 options
  	 (or (options:cc-command options)
--- 128,134 ----
  	 options
  	 (or (options:temp-dir options)
  	     (getenv "TMPDIR") 
! 	     "/var/tmp"))
  	(set-options:cc-command
  	 options
  	 (or (options:cc-command options)
