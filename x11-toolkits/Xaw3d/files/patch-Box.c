*** Box.c~	1996-10-15 10:41:18.000000000 -0400
--- Box.c	2007-04-21 14:12:44.000000000 -0400
***************
*** 353,360 ****
  	else {
  	    width = preferred_width;
  	    do { /* find some width big enough to stay within this height */
! 		width *= 2;
! 		if (width > constraint->width) width = constraint->width;
  		DoLayout(w, width, 0, &preferred_width, &preferred_height, FALSE);
  	    } while (preferred_height > constraint->height &&
  		     width < constraint->width);
--- 353,363 ----
  	else {
  	    width = preferred_width;
  	    do { /* find some width big enough to stay within this height */
! 		if (width > constraint->width/2) /* avoid short int overflow */
! 		    width = constraint->width;
! 		else
! 		    width *= 2;
! 
  		DoLayout(w, width, 0, &preferred_width, &preferred_height, FALSE);
  	    } while (preferred_height > constraint->height &&
  		     width < constraint->width);
