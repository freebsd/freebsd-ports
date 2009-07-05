*** src/sipe.c.orig	Thu Jul  2 11:08:31 2009
--- src/sipe.c	Thu Jul  2 11:11:56 2009
***************
*** 2886,2892 ****
  	while (tmp) {
  		struct transaction *trans = tmp->data;
  		tmp = tmp->next;
! 		purple_debug_info("sipe", "have open transaction age: %ld\n", currtime-trans->time);
  		if ((currtime - trans->time > 5) && trans->retries >= 1) {
  			/* TODO 408 */
  		} else {
--- 2886,2892 ----
  	while (tmp) {
  		struct transaction *trans = tmp->data;
  		tmp = tmp->next;
! 		purple_debug_info("sipe", "have open transaction age: %ld\n", (long int)currtime-trans->time);
  		if ((currtime - trans->time > 5) && trans->retries >= 1) {
  			/* TODO 408 */
  		} else {
