--- src/input_dataset_mod.F90.orig	2023-06-02 20:37:00 UTC
+++ src/input_dataset_mod.F90
@@ -2097,7 +2097,7 @@ END IF
  INTEGER :: input_unit,echo_unit
  INTEGER :: i_all,i_dx,i_xmin,i_zmesh,i_range
  LOGICAL :: has_to_echo
- CHARACTER(200) :: inputline
+ CHARACTER(256) :: inputline
  TYPE(input_dataset_t),POINTER :: dataset
 
 !------------------------------------------------------------------
