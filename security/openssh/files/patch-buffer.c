*** buffer.c.orig	Sat Jun 29 06:33:59 2002
--- buffer.c	Tue Sep 16 00:33:54 2003
***************
*** 69,74 ****
--- 69,75 ----
  void *
  buffer_append_space(Buffer *buffer, u_int len)
  {
+ 	u_int newlen;
  	void *p;
  
  	if (len > 0x100000)
***************
*** 98,108 ****
  		goto restart;
  	}
  	/* Increase the size of the buffer and retry. */
! 	buffer->alloc += len + 32768;
! 	if (buffer->alloc > 0xa00000)
  		fatal("buffer_append_space: alloc %u not supported",
! 		    buffer->alloc);
! 	buffer->buf = xrealloc(buffer->buf, buffer->alloc);
  	goto restart;
  	/* NOTREACHED */
  }
--- 99,111 ----
  		goto restart;
  	}
  	/* Increase the size of the buffer and retry. */
! 	
! 	newlen = buffer->alloc + len + 32768;
! 	if (newlen > 0xa00000)
  		fatal("buffer_append_space: alloc %u not supported",
! 		    newlen);
! 	buffer->buf = xrealloc(buffer->buf, newlen);
! 	buffer->alloc = newlen;
  	goto restart;
  	/* NOTREACHED */
  }
