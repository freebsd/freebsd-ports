*** ./src/trivial-rewrite/resolve.c	Mon Jul 28 16:34:38 2003
--- ./src/trivial-rewrite/resolve.c	Mon Jul 28 16:35:04 2003
***************
*** 148,153 ****
--- 148,154 ----
  	    if (saved_domain)
  		tok822_free_tree(saved_domain);
  	    saved_domain = domain;
+ 	    domain = 0;
  	}
  
  	/*
