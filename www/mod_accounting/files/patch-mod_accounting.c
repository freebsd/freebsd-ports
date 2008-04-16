*** mod_accounting.c.orig	Sun Sep  8 18:17:22 2002
--- mod_accounting.c	Fri Nov 11 11:26:43 2005
***************
*** 140,146 ****
  // computes the number of bytes received
  static long BytesRecvd( request_rec *r )
  {
! 	long		recvd;
  	const char *len;
  
  #ifdef DEBUG
--- 140,146 ----
  // computes the number of bytes received
  static long BytesRecvd( request_rec *r )
  {
! 	long recvd=0;
  	const char *len;
  
  #ifdef DEBUG
***************
*** 148,153 ****
--- 148,155 ----
  				  "BytesRecvd" );
  #endif
  
+ 	if( ! r ) return( 0 ); // empty request
+ 	if( ! r->the_request  ) return( 0 ); // empty request
  	recvd = strlen( r->the_request ) + TableLen( r, r->headers_in ) + 4; // 2 for CRLF after the request, 2 for CRLF after all headers
  
  	len = ap_table_get( r->headers_in, "Content-Length" );
