SAGE_SPKG_CONFIGURE([singular], [
    SAGE_SPKG_DEPCHECK([gmp mpfr], [
        dnl  checking with pkg-config
        PKG_CHECK_MODULES([libSingular], [Singular >= 4.1.1], [], [sage_spkg_install_singular=yes])
    ])
])
