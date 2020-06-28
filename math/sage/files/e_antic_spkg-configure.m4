SAGE_SPKG_CONFIGURE([e_antic], [
    SAGE_SPKG_DEPCHECK([arb gmp flint], [
       AC_CHECK_HEADER([e-antic/e-antic.h], [
        AC_SEARCH_LIBS([nf_init], [eantic], [
        ], [sage_spkg_install_e_antic=yes])
       ], [sage_spkg_install_e_antic=yes])
    ])
])
