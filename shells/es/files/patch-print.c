*** print.c.orig	Fri Apr 11 15:54:36 1997
--- print.c	Mon Mar 15 18:55:13 2004
***************
*** 279,285 ****
--- 279,289 ----
  	VA_START(format->args, fmt);
  	n += printfmt(format, fmt);
  	va_end(format->args);
+ #if NO_VA_LIST_ASSIGN
+ 	memcpy(format->args, saveargs, sizeof(va_list));
+ #else
  	format->args = saveargs;
+ #endif  
  
  	return n + format->flushed;
  }
