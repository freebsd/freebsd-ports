--- aclocal.m4	2004-12-20 12:44:09.000000000 -0800
+++ aclocal.m4	2008-03-02 23:38:19.000000000 -0800
@@ -49,25 +49,33 @@
 )
 
 AC_DEFUN(MY_CHECK_FOMIT_FRAME_POINTER,[
- AC_MSG_CHECKING([attempted use of -fomit-frame-pointer on x86])
+ AC_MSG_CHECKING([for improper use of -fomit-frame-pointer])
  result=no
- if echo "$CXX $CXXFLAGS" | grep fomit-frame-pointer ; then
+ if echo "$CXX $CXXFLAGS" | grep fomit-frame-pointer > /dev/null ; then
   if test -n "$host_alias" ; then
    my_host="$host_alias"
   else
    my_host=`uname -m`
   fi
-  if echo "$my_host" | grep 86 ; then
-   AC_MSG_WARN([cannot build with -fomit-frame-pointer on x86.
-gcc does not handle exceptions properly in code compiled with
+  if echo "$my_host" | grep 86 > /dev/null ; then
+   if test "$GXX" = "yes"; then
+    case `$CXX -dumpversion` in
+     [
+     [012].* | 3.[012]* | 3.3 | 3.3.0* )
+     ]dnl quote the tests with []'s to prevent m4 from eating the []'s in the tests.
+       AC_MSG_WARN([cannot build with -fomit-frame-pointer on x86.
+Old versions of gcc do not handle exceptions properly in code compiled with
 -fomit-frame-pointer on x86 platforms.  See:
 http://gcc.gnu.org/cgi-bin/gnatsweb.pl?cmd=view&pr=2447&database=gcc
 
 Removing -fomit-frame-pointer from the compiler flags.
 ])
-   CXX=`echo $CXX | sed "s/-fomit-frame-pointer//"`
-   CXXFLAGS=`echo $CXXFLAGS | sed "s/-fomit-frame-pointer//"`
-   result=removed
+       CXX=`echo $CXX | sed "s/-fomit-frame-pointer//"`
+       CXXFLAGS=`echo $CXXFLAGS | sed "s/-fomit-frame-pointer//"`
+       result=removed
+       ;;
+    esac
+   fi
   fi
  fi
  AC_MSG_RESULT($result)
@@ -138,12 +146,31 @@
   AC_DEFINE(HAVE_[]translit([$1], [a-z], [A-Z]),1,[Do we have $5?])])dnl
 ])
 
-AC_DEFUN([MY_CHECK_TERMSTUFF],[MY_SEARCH_LIBS(working_termstuff,
-[#include <term.h>
-#include <stdio.h>],
-[tputs(clr_bol, 1, putchar);],
-[termcap curses ncurses],
-[a working term.h, tputs, and clr_bol])
+AC_DEFUN([MY_CHECK_TERMSTUFF],[
+ MY_SEARCH_LIBS(netbsd_curses,
+  [#include <termcap.h>],
+  [struct tinfo *info;
+   char *term="foo";
+   int res = t_getent(&info, term);],
+  [termcap],
+  [netbsd-style termcap])
+ if test "$my_cv_netbsd_curses" = no ; then
+  MY_SEARCH_LIBS(new_curses,
+   [#include <term.h>
+    #include <stdio.h>],
+   [int res = tputs(clr_bol, 1, putchar);],
+   [termcap curses ncurses],
+   [new curses terminfo])
+ fi
+ if test "$my_cv_netbsd_curses" = no -a "$my_cv_new_curses" = no ; then
+  MY_SEARCH_LIBS(old_curses,
+   [#include <curses.h>
+    #include <term.h>],
+   [setupterm((char *)0, 1, (int *)0);
+    int res = putp(clr_bol);],
+   [curses],
+   [sysv terminfo])
+ fi
 ])
 
 AC_DEFUN([MY_CHECK_SOCKET],[MY_SEARCH_LIBS(socket,
