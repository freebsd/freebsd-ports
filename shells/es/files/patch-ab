*** input.c.orig	Tue Aug 12 18:59:26 1997
--- input.c	Thu Dec  7 18:35:01 2000
***************
*** 307,313 ****
  			if (in->buflen < nread) {
  				while (in->buflen < nread)
  					in->buflen *= 2;
- 				efree(in->bufbegin);
  				in->bufbegin = erealloc(in->bufbegin, in->buflen);
  			}
  			memcpy(in->bufbegin, rlinebuf, nread - 1);
--- 307,312 ----

