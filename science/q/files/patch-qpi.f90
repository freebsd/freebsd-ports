--- qpi.f90.orig	2017-11-19 12:13:54 UTC
+++ qpi.f90
@@ -209,29 +209,26 @@ end program QPI6
 
 ! signal handlers
 
-INTEGER(4) FUNCTION sigint_handler(sig_num)
+SUBROUTINE sigint_handler(sig_num)
   use QCP
   implicit none
   INTEGER(4)					:: sig_num
 
   call die('user request (control-C)')
-  sigint_handler = 1
-END FUNCTION sigint_handler
+END SUBROUTINE sigint_handler
 
-INTEGER(4) FUNCTION sigkill_handler(sig_num)
+SUBROUTINE sigkill_handler(sig_num)
   use QCP
   implicit none
   INTEGER(4)					:: sig_num
 
   call die('kill signal')
-  sigkill_handler = 1
-END FUNCTION sigkill_handler
+END SUBROUTINE sigkill_handler
 
-INTEGER(4) FUNCTION sigabrt_handler(sig_num)
+SUBROUTINE sigabrt_handler(sig_num)
   use QCP
   implicit none
   INTEGER(4)					:: sig_num
 
   call die('kill signal')
-  sigabrt_handler = 1
-END FUNCTION sigabrt_handler
+END SUBROUTINE sigabrt_handler
