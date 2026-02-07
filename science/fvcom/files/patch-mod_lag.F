--- mod_lag.F.orig	2008-07-25 16:44:11.000000000 -0500
+++ mod_lag.F	2014-04-28 12:23:34.000000000 -0500
@@ -212,7 +212,12 @@
   !Lagrangian particle associated scalar
   character(len=80) :: lag_scal_choice
   integer, parameter:: n_scal_choice = 6
-  character(len=80) :: scal_choices(n_scal_choice) = (/"s1","t1","rho1","km","kh","user_defined"/)
+  character(len=80) :: scal_choices(n_scal_choice) = (/ "s1          ", &
+							"t1          ", &
+							"rho1        ", &
+							"km          ", &
+							"kh          ", &
+							"user_defined"/)
   logical           :: scal_choice_valid
 
 
