SAGE_SPKG_CONFIGURE([linbox], [
    SAGE_SPKG_DEPCHECK([gmp givaro fflas-ffpack], [
        dnl  checking with pkg-config
        PKG_CHECK_MODULES([LINBOX], [linbox >= 1.6.3], [], [sage_spkg_install_linbox=yes])
    ])
])
