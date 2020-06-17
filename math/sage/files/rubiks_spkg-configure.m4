SAGE_SPKG_CONFIGURE([rubiks], [
        AC_PATH_PROG([rubiks], [cu2])
        AC_PATH_PROG([rubiks], [cubex])
        AC_PATH_PROG([rubiks], [dikcube])
        AC_PATH_PROG([rubiks], [mcube])
        AC_PATH_PROG([rubiks], [optimal])
        AC_PATH_PROG([rubiks], [size222])
        AS_IF([test x$rubiks = x], [
           AC_MSG_NOTICE([rubiks not found. Installing rubiks])
           sage_spkg_install_rubiks=yes])
])
