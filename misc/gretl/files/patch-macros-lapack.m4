--- macros/lapack.m4~	Fri Aug 26 05:19:27 2005
+++ macros/lapack.m4	Tue Jan 23 10:04:28 2007
@@ -17,7 +17,7 @@
 
   if test x"${LAPACK_LIBS}" = x ; then 
      AC_MSG_CHECKING(for libgfortran, libg2c or libf2c)
-     AC_CHECK_LIB(gfortran,etime_,FLIB="-lgfortran",FLIB="none")
+     AC_CHECK_LIB(gfortran,_gfortran_etime,FLIB="-lgfortran",FLIB="none")
      if test $FLIB = "none" ; then
         AC_CHECK_LIB(g2c,c_sqrt,FLIB="-lg2c",FLIB="none")
      fi
