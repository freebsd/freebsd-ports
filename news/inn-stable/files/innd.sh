#!/bin/sh
if [ $# -eq 0 -o x$1 = xstart ]; then
   if [ -x !!PREFIX!!/etc/rc.news -a -f !!PREFIX!!/news/lib/history.pag ]; then
      limits -C news !!PREFIX!!/etc/rc.news && echo ' inn'
   fi
fi
if [ x$1 = xstop ]; then
   !!PREFIX!!/news/bin/ctlinnd shutdown machine is going down
fi
