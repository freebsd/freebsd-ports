Index: appl/telnet/telnet/telnet.c
===================================================================
RCS file: appl/telnet/telnet/telnet.c,v
retrieving revision 5.18
diff -c -r5.18 telnet.c
*** telnet.c	15 Nov 2002 20:21:35 -0000	5.18
--- telnet.c	15 Mar 2005 18:59:32 -0000
***************
*** 1475,1480 ****
--- 1475,1482 ----
  	unsigned char flags;
  	cc_t value;
  {
+ 	if ((slc_replyp - slc_reply) + 6 > sizeof(slc_reply))
+ 		return;
  	if ((*slc_replyp++ = func) == IAC)
  		*slc_replyp++ = IAC;
  	if ((*slc_replyp++ = flags) == IAC)
***************
*** 1488,1498 ****
  {
      register int len;
  
-     *slc_replyp++ = IAC;
-     *slc_replyp++ = SE;
      len = slc_replyp - slc_reply;
!     if (len <= 6)
  	return;
      if (NETROOM() > len) {
  	ring_supply_data(&netoring, slc_reply, slc_replyp - slc_reply);
  	printsub('>', &slc_reply[2], slc_replyp - slc_reply - 2);
--- 1490,1501 ----
  {
      register int len;
  
      len = slc_replyp - slc_reply;
!     if (len <= 4 || (len + 2 > sizeof(slc_reply)))
  	return;
+     *slc_replyp++ = IAC;
+     *slc_replyp++ = SE;
+     len += 2;
      if (NETROOM() > len) {
  	ring_supply_data(&netoring, slc_reply, slc_replyp - slc_reply);
  	printsub('>', &slc_reply[2], slc_replyp - slc_reply - 2);
***************
*** 1645,1650 ****
--- 1648,1654 ----
  	register unsigned char *ep;
  {
  	register unsigned char *vp, c;
+ 	unsigned int len, olen, elen;
  
  	if (opt_reply == NULL)		/*XXX*/
  		return;			/*XXX*/
***************
*** 1662,1680 ****
  		return;
  	}
  	vp = env_getvalue(ep);
! 	if (opt_replyp + (vp ? strlen((char *)vp) : 0) +
! 				strlen((char *)ep) + 6 > opt_replyend)
  	{
! 		register unsigned int len;
! 		opt_replyend += OPT_REPLY_SIZE;
! 		len = opt_replyend - opt_reply;
  		opt_reply = (unsigned char *)realloc(opt_reply, len);
  		if (opt_reply == NULL) {
  /*@*/			printf("env_opt_add: realloc() failed!!!\n");
  			opt_reply = opt_replyp = opt_replyend = NULL;
  			return;
  		}
! 		opt_replyp = opt_reply + len - (opt_replyend - opt_replyp);
  		opt_replyend = opt_reply + len;
  	}
  	if (opt_welldefined((char *) ep))
--- 1666,1684 ----
  		return;
  	}
  	vp = env_getvalue(ep);
! 	elen = 2 * (vp ? strlen((char *)vp) : 0) +
! 		2 * strlen((char *)ep) + 6;
! 	if ((opt_replyend - opt_replyp) < elen)
  	{
! 		len = opt_replyend - opt_reply + elen;
! 		olen = opt_replyp - opt_reply;
  		opt_reply = (unsigned char *)realloc(opt_reply, len);
  		if (opt_reply == NULL) {
  /*@*/			printf("env_opt_add: realloc() failed!!!\n");
  			opt_reply = opt_replyp = opt_replyend = NULL;
  			return;
  		}
! 		opt_replyp = opt_reply + olen;
  		opt_replyend = opt_reply + len;
  	}
  	if (opt_welldefined((char *) ep))
