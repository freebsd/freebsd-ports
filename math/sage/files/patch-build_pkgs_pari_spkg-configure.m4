--- build/pkgs/pari/spkg-configure.m4.orig	2020-10-27 19:12:31 UTC
+++ build/pkgs/pari/spkg-configure.m4
@@ -77,17 +77,6 @@ SAGE_SPKG_CONFIGURE([pari], [
            AC_MSG_NOTICE([Otherwise Sage will build its own pari/GP.])
            sage_spkg_install_pari=yes
         fi
-        AC_MSG_CHECKING([whether bnfisunit bug of pari 2.11.3 is fixed])
-        bug_check=`echo "bnf = bnfinit(y^4-y-1); bnfisunit(bnf,-y^3+2*y^2-1)" | $GP -qf 2>> config.log`
-        expected="[[0, 2, Mod(0, 2)]]~"
-        if test x"$bug_check" = x"$expected"; then
-           AC_MSG_RESULT([yes])
-        else
-           AC_MSG_RESULT([no; cannot use system pari/GP with known bug])
-           AC_MSG_NOTICE([Upgrade your system package and reconfigure.])
-           AC_MSG_NOTICE([Otherwise Sage will build its own pari/GP.])
-           sage_spkg_install_pari=yes
-        fi
         AC_MSG_CHECKING([whether qfisom bug of pari 2.11.2 is fixed])
         bug_check=`echo "qfisom([[16,6;6,10]],[[4,3;3,10]])" | $GP -qf 2>> config.log`
         expected="0"
