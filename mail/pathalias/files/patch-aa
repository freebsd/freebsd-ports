*** ./mapit.c	Sat Jun  9 12:32:18 1990
--- ../../m/mapit.c	Thu Feb 10 07:00:02 1994
***************
*** 298,303 ****
--- 298,306 ----
  		 || (NETDIR(l) == LRIGHT && (prev->n_flag & HASLEFT)))
  			cost += INF;			/* mixed syntax */
  	}
+ 					/* Dirk meyer 10.02.94 */
+ 	if ( cost < 0 )			/* Overflow, more than 31 bit */
+ 		cost = INF;		/* Limit, to avoid recursive paths */
  
  	return cost;
  }
