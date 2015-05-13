#! /bin/sh

case `uname -m` in
amd64)
      STORE=2000
      ;;
esac

bin="/usr/local/share/reduce/psl/bpsl"
img="/usr/local/share/reduce/red/reduce.img"

exec $bin -td $STORE -f $img $*

