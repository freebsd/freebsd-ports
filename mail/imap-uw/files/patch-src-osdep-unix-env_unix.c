*** src/osdep/unix/env_unix.c.orig	Tue May 29 22:29:52 2007
--- src/osdep/unix/env_unix.c	Mon Jul 23 17:50:43 2007
***************
*** 79,85 ****
  static short anonymous = NIL;	/* is anonymous */
  static short blackBox = NIL;	/* is a black box */
  static short closedBox = NIL;	/* is a closed box (uses chroot() jail) */
! static short restrictBox = NIL;	/* is a restricted box */
  static short has_no_life = NIL;	/* is a cretin with no life */
  static short hideDotFiles = NIL;/* hide files whose names start with . */
  				/* advertise filesystem root */
--- 79,85 ----
  static short anonymous = NIL;	/* is anonymous */
  static short blackBox = NIL;	/* is a black box */
  static short closedBox = NIL;	/* is a closed box (uses chroot() jail) */
! static short restrictBox = -1;	/* is a restricted box */
  static short has_no_life = NIL;	/* is a cretin with no life */
  static short hideDotFiles = NIL;/* hide files whose names start with . */
  				/* advertise filesystem root */
