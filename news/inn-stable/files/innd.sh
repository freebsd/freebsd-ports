#!/bin/sh
if [ $# -eq 0 -o x$1 = xstart ]; then
   if [ -x !!PREFIX!!/news/bin/rc.news -a -f !!PREFIX!!/news/db/history.dir ]; then
      su -fm news -c !!PREFIX!!/news/bin/rc.news && echo ' inn'
   fi
fi
if [ x$1 = xstop ]; then
      su -fm news -c '!!PREFIX!!/news/bin/rc.news stop'
fi
