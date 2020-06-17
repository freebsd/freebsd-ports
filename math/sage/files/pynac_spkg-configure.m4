SAGE_SPKG_CONFIGURE([pynac], [
    SAGE_SPKG_DEPCHECK([gmp ntl flint singular giac], [
        dnl  checking with pkg-config
        PKG_CHECK_MODULES([libpynac], [pynac = 0.7.26], [], [sage_spkg_install_pynac=yes])
    ])
])
