*** src/proxy.c.orig	Thu Jan 22 08:27:26 2004
--- src/proxy.c	Thu Jan 22 08:28:05 2004
***************
*** 974,980 ****
  
  	gaim_input_remove(phb->inpa);
  
! 	while ((nlc != 2) && (read(source, &inputline[pos++], 1) == 1)) {
  		if (inputline[pos - 1] == '\n')
  			nlc++;
  		else if (inputline[pos - 1] != '\r')
--- 974,980 ----
  
  	gaim_input_remove(phb->inpa);
  
! 	while ((pos < sizeof(inputline)-1) && (nlc != 2) && (read(source, &inputline[pos++], 1) == 1)) {
  		if (inputline[pos - 1] == '\n')
  			nlc++;
  		else if (inputline[pos - 1] != '\r')
