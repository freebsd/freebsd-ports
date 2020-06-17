SAGE_SPKG_CONFIGURE([gap], [
    SAGE_SPKG_DEPCHECK([gmp], [
       AC_CHECK_HEADER([gap/system.h], [
        AC_SEARCH_LIBS([GAP_COMM], [gap], [
        ], [sage_spkg_install_gap=yes])
       ], [sage_spkg_install_gap=yes])
    ])
])
