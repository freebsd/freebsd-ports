Index: xdr_mem.c
===================================================================
RCS file: /cvs/krbdev/krb5/src/lib/rpc/xdr_mem.c,v
retrieving revision 1.8
diff -c -r1.8 xdr_mem.c
*** lib/rpc/xdr_mem.c	1998/02/14 02:27:24	1.8
--- lib/rpc/xdr_mem.c	2003/02/04 22:57:24
***************
*** 47,52 ****
--- 47,54 ----
  #include <gssrpc/xdr.h>
  #include <netinet/in.h>
  #include <stdio.h>
+ #include <string.h>
+ #include <limits.h>
  
  static bool_t	xdrmem_getlong();
  static bool_t	xdrmem_putlong();
***************
*** 83,89 ****
  	xdrs->x_op = op;
  	xdrs->x_ops = &xdrmem_ops;
  	xdrs->x_private = xdrs->x_base = addr;
! 	xdrs->x_handy = size;
  }
  
  static void
--- 85,91 ----
  	xdrs->x_op = op;
  	xdrs->x_ops = &xdrmem_ops;
  	xdrs->x_private = xdrs->x_base = addr;
! 	xdrs->x_handy = (size > INT_MAX) ? INT_MAX : size; /* XXX */
  }
  
  static void
***************
*** 98,105 ****
  	long *lp;
  {
  
! 	if ((xdrs->x_handy -= sizeof(rpc_int32)) < 0)
  		return (FALSE);
  	*lp = (long)ntohl(*((rpc_u_int32 *)(xdrs->x_private)));
  	xdrs->x_private += sizeof(rpc_int32);
  	return (TRUE);
--- 100,109 ----
  	long *lp;
  {
  
! 	if (xdrs->x_handy < sizeof(rpc_int32))
  		return (FALSE);
+ 	else
+ 		xdrs->x_handy -= sizeof(rpc_int32);
  	*lp = (long)ntohl(*((rpc_u_int32 *)(xdrs->x_private)));
  	xdrs->x_private += sizeof(rpc_int32);
  	return (TRUE);
***************
*** 111,118 ****
  	long *lp;
  {
  
! 	if ((xdrs->x_handy -= sizeof(rpc_int32)) < 0)
  		return (FALSE);
  	*(rpc_int32 *)xdrs->x_private = (rpc_int32)htonl((rpc_u_int32)(*lp));
  	xdrs->x_private += sizeof(rpc_int32);
  	return (TRUE);
--- 115,124 ----
  	long *lp;
  {
  
! 	if (xdrs->x_handy < sizeof(rpc_int32))
  		return (FALSE);
+ 	else
+ 		xdrs->x_handy -= sizeof(rpc_int32);
  	*(rpc_int32 *)xdrs->x_private = (rpc_int32)htonl((rpc_u_int32)(*lp));
  	xdrs->x_private += sizeof(rpc_int32);
  	return (TRUE);
***************
*** 125,132 ****
  	register unsigned int len;
  {
  
! 	if ((xdrs->x_handy -= len) < 0)
  		return (FALSE);
  	memmove(addr, xdrs->x_private, len);
  	xdrs->x_private += len;
  	return (TRUE);
--- 131,140 ----
  	register unsigned int len;
  {
  
! 	if (xdrs->x_handy < len)
  		return (FALSE);
+ 	else
+ 		xdrs->x_handy -= len;
  	memmove(addr, xdrs->x_private, len);
  	xdrs->x_private += len;
  	return (TRUE);
***************
*** 139,146 ****
  	register unsigned int len;
  {
  
! 	if ((xdrs->x_handy -= len) < 0)
  		return (FALSE);
  	memmove(xdrs->x_private, addr, len);
  	xdrs->x_private += len;
  	return (TRUE);
--- 147,156 ----
  	register unsigned int len;
  {
  
! 	if (xdrs->x_handy < len)
  		return (FALSE);
+ 	else
+ 		xdrs->x_handy -= len;
  	memmove(xdrs->x_private, addr, len);
  	xdrs->x_private += len;
  	return (TRUE);
***************
*** 179,185 ****
  {
  	rpc_int32 *buf = 0;
  
! 	if (xdrs->x_handy >= len) {
  		xdrs->x_handy -= len;
  		buf = (rpc_int32 *) xdrs->x_private;
  		xdrs->x_private += len;
--- 189,195 ----
  {
  	rpc_int32 *buf = 0;
  
! 	if (len >= 0 && xdrs->x_handy >= len) {
  		xdrs->x_handy -= len;
  		buf = (rpc_int32 *) xdrs->x_private;
  		xdrs->x_private += len;
