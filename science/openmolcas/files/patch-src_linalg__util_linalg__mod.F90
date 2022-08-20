- workaround for https://gitlab.com/Molcas/OpenMolcas/-/issues/370

--- src/linalg_util/linalg_mod.F90.orig	2022-08-20 17:37:29 UTC
+++ src/linalg_util/linalg_mod.F90
@@ -341,11 +341,11 @@ subroutine determine_eigenspaces(lambda,dimensions)
   integer(kind=iwp) :: i, low
   integer(kind=iwp) :: n_spaces
 
-# ifdef _ADDITIONAL_RUNTIME_CHECK_
-  if (any(lambda(2:) < lambda(:size(lambda)-1))) then
-    call abort_('Eigenvalues not sorted in'//__FILE__)
-  end if
-# endif
+!># ifdef _ADDITIONAL_RUNTIME_CHECK_
+!>  if (any(lambda(2:) < lambda(:size(lambda)-1))) then
+!>    call abort_('Eigenvalues not sorted in'//__FILE__)
+!>  end if
+!># endif
 
   call mma_allocate(d_buffer,size(lambda))
   d_buffer(:) = 0
