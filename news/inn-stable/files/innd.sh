#!/bin/sh
if [ $# -eq 0 -o x$1 = xstart ]; then
   if [ -x !!PREFIX!!/news/bin/rc.news -a -f !!PREFIX!!/news/db/history.pag ]; then
      limits -C news !!PREFIX!!/bin/rc.news && echo ' inn'
   fi
fi
if [ x$1 = xstop ]; then
   !!PREFIX!!/news/bin/ctlinnd shutdown machine is going down
fi
