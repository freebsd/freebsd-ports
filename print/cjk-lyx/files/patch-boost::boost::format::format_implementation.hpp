$NetBSD$

--- ./boost/boost/format/format_implementation.hpp.orig	2002-11-21 11:33:01.000000000 -0700
+++ ./boost/boost/format/format_implementation.hpp
@@ -151,7 +151,7 @@ basic_format<Ch,Tr>& basic_format<Ch,Tr>
 {
     if(argN<1 || argN > num_args_ || bound_.size()==0 || !bound_[argN-1] )
       {
-	if( exceptions() & out_of_range_bit )
+       if( exceptions() & io::out_of_range_bit )
 	  boost::throw_exception(io::out_of_range()); // arg not in range.
 	else return *this;
       }
