SAGE_SPKG_CONFIGURE([maxima], [
        AC_PATH_PROG([MAXIMA], [maxima])
        AS_IF([test x$MAXIMA = x], [
           AC_MSG_NOTICE([maxima not found. Installing maxima])
           sage_spkg_install_maxima=yes])
])
