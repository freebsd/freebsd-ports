SAGE_SPKG_CONFIGURE(
    [py_libs], [dnl direct testing for import module
      AC_MSG_CHECKING(Import module py_libs...)
      python3 -c "import py_libs;" > /dev/null 2>&1
      if test $? -ne 0; then
        AC_MSG_RESULT(KO)
        sage_spkg_install_py_libs=yes
      else
        AC_MSG_RESULT(OK)
      fi
])
