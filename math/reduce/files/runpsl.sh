#! /bin/sh

case `uname -m` in
amd64)
      STORE=2000
      ;;
i386)
      STORE=16000000
      ;;
esac

bin="/usr/local/share/reduce/psl/bpsl"
img="/usr/local/share/reduce/red/reduce.img"

exec $bin -td $STORE -f $img $*

