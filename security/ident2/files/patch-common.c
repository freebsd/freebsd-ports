*** common.c.orig	Fri Apr 16 10:02:41 2004
--- common.c	Fri Apr 16 10:17:43 2004
***************
*** 41,63 ****
  	/*
  	 *	a (skewed) fgets() that works on file descriptors
  	 *	the '\r' charecter is ignored
  	 */
  static int
! _getl (int d, char *p, u_short l)
  {
! 	size_t n = 0;
  
! 	while (read (d, p, 1) == 1) {
  		if (*p == '\n')
  			break;
  		if (*p == '\r')
  			p--;	/* ignore \r */
- 		p++;
- 		if (n++ >= l)
- 			break;
  	}
! 	*p = 0;
! 	return n;
  }
  
  	/*
--- 41,65 ----
  	/*
  	 *	a (skewed) fgets() that works on file descriptors
  	 *	the '\r' charecter is ignored
+ 	 *	returns the number of bytes written into the given
+ 	 *	 buffer, including the terminating NUL
  	 */
  static int
! _getl (int d, char *begin, u_short l)
  {
! 	char *p, *end;
  
! 	end = &begin[l-1]; /* leave room for terminating NUL */
! 	for (p = begin; p < end; ++p) {
! 		if (read (d, p, 1) != 1)
! 			break;
  		if (*p == '\n')
  			break;
  		if (*p == '\r')
  			p--;	/* ignore \r */
  	}
! 	*p++ = 0;
! 	return p-begin;
  }
  
  	/*
