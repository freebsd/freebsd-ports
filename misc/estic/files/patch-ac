These were mailed to jhs@
by uz@wuschel.ibb.schwaben.com (Ullrich von Bassewitz)
They were titled:
	Written by Oliver von Bueren, ovb@swissmail.com, 12-Nov-1996 
	The following is only an addition to the ESTIC program, which is Copyright
	by Ullrich von Bassewitz. It's free to integrate into ESTIC as long as
	the terms for the original program from UvB are met.  
	There is absolutely no guarantee that it will work on any other system,
	it just works for me on my system.

I Julian Stacey <jhs@freebsd.org> have tried compiling without the 
	Port->DTROff ();
patch & can confirm for Ullrich, it is necessary, without it, I get
a communications timeout. Thanks Oliver.

*** estic/devstate.cc.orig	Sat Sep 14 15:40:16 1996
--- estic/devstate.cc	Tue Nov 12 20:11:06 1996
***************
*** 622,628 ****
  	    if (DevNum + 21 == E.Info.U % 256) {
  		if (GetState (stBusy) == 0) {
  		    // Get the duration
! 		    ForcedRingEnd = Time () + TimeDiff (E.Info.U / 256);
  		    // Set the new state
  		    SetState (stForcedRing | stForcedRingOn);
  		    // Send the command to the istec
--- 622,631 ----
  	    if (DevNum + 21 == E.Info.U % 256) {
  		if (GetState (stBusy) == 0) {
  		    // Get the duration
! // ovb@swissmail.com, 12-Nov-96: Added typecast (double) as the compiler 
! //				 complained about ambiguous selection 
! //				 possibilities for TimeDiff.
! 		    ForcedRingEnd = Time () + TimeDiff ((double)E.Info.U / 256);
  		    // Set the new state
  		    SetState (stForcedRing | stForcedRingOn);
  		    // Send the command to the istec
*** estic/iccom.cc.orig	Sat Sep 14 15:40:16 1996
--- estic/iccom.cc	Tue Nov 12 20:05:34 1996
***************
*** 34,39 ****
--- 34,48 ----
  #include "iccom.h"
  
  
+ /*****************************************************************************/
+ /*                      Explicit template instantiation                      */
+ /*****************************************************************************/
+ 
+ // ovb@swissmail.com, 12-Nov-96: This definition seemed to be missing.
+ #ifdef EXPLICIT_TEMPLATES
+ template class CircularBuffer<IstecMsg*>;
+ #endif
+ 
  
  /*****************************************************************************/
  /*                                   Data                                    */
***************
*** 126,131 ****
--- 135,144 ----
      // Make the RTS line active. This is needed for the new PCB of the istec
      // (beginning from version #3).
      Port->RTSOn ();
+     // ovb@swissmail.com, 12-Nov-96: Fix of Rev3.
+     // We have to turn the DTR off as this is needed for the power supply.
+     // -> Power is taken from the RTS(+) and the DTR(-) line.
+     Port->DTROff ();
  
      // Success
      return 0;
***************
*** 159,165 ****
      // Post an appropriate event
      PostEvent (evChargeUpdate);
  }
- 
  
  
  static void IstecWrite (unsigned char* Msg, unsigned BufSize)
--- 172,177 ----
*** estic/icfile.cc.orig	Sat Sep 14 15:40:16 1996
--- estic/icfile.cc	Tue Nov 12 20:06:33 1996
***************
*** 27,32 ****
--- 27,35 ----
  
  #include "syserror.h"
  
+ // ovb@swissmail.com, 12-Nov-96: This was missing to compile on FreeBSD 2.1.5
+ extern int errno;
+ 
  #include "icfile.h"
  
  
