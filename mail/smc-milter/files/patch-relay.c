*** relay.c.orig	Thu Mar 10 06:23:13 2005
--- relay.c	Thu Mar 24 11:23:49 2005
***************
*** 202,209 ****
  		    return -1;
  		}
  
! 		if (!(gethostbyname_r(host_name, &host_buf, buffer, sizeof(buffer),
! 		    &host, &ret))) {
  		    while (*host->h_addr_list) {
  			if (host_addr == *(uint32_t *)(*host->h_addr_list)) {
  			    resolver_close(&res_local);
--- 202,209 ----
  		    return -1;
  		}
  
! 		host = gethostbyname_r(host_name, &host_buf, buffer, sizeof(buffer), &ret);
! 		if (!ret) {
  		    while (*host->h_addr_list) {
  			if (host_addr == *(uint32_t *)(*host->h_addr_list)) {
  			    resolver_close(&res_local);
