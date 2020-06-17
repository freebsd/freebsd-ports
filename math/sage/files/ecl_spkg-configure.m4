SAGE_SPKG_CONFIGURE([ecl], [
        AC_PATH_PROG([ECL], [ecl])
        AS_IF([test x$ECL = x], [
           AC_MSG_NOTICE([ecl not found. Installing ecl])
           sage_spkg_install_ecl=yes])
])
