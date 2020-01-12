--- m4/cs_salome.m4.orig	2019-12-23 11:17:00 UTC
+++ m4/cs_salome.m4
@@ -167,16 +167,16 @@ AC_LANG_SAVE
 
 omniORB_ok=no # in case following test is not called
 
-AS_IF([test $cs_have_salome_kernel = yes -o $cs_have_salome_gui = yes],
+AS_IF([test "x$cs_have_salome_kernel" = "xyes" -o "x$cs_have_salome_gui" = "xyes"],
       [CS_AC_TEST_OMNIORB
        CS_AC_TEST_CORBA])
 
 AC_LANG_RESTORE
 
 AM_CONDITIONAL(HAVE_SALOME,
-               test $cs_have_salome_kernel = yes \
-                 -a $cs_have_salome_gui = yes \
-                 -a $omniORB_ok = yes)
+               test x$cs_have_salome_kernel = xyes \
+                 -a x$cs_have_salome_gui = xyes \
+                 -a x$omniORB_ok = xyes)
 
 ])dnl
 
