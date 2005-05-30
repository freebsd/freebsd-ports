AC_INIT([senna],[0.0],[senna@razil.jp])
AM_INIT_AUTOMAKE([senna], 0.0)
AM_CONFIG_HEADER(config.h)

SENNA_HOME="/var/senna"

AC_ARG_WITH(sennahome,
  [  --with-sennahome=DIR      Specify Senna home dictionary],SENNA_HOME="$withval")

AC_PROG_CC
AM_PROG_LIBTOOL
AC_CONFIG_FILES([Makefile test/Makefile lib/Makefile])
AC_SUBST(SENNA_HOME)
AC_CHECK_LIB(mecab-razil, mecab_new3, [],[echo "No libmecab-razil found (You need a patched version, if using mecab without mecab_new3)"; exit 1])

AC_OUTPUT
