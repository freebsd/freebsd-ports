#!/bin/sh
export MOZILLA_HOME; MOZILLA_HOME=${MOZILLA_HOME:=@PREFIX@/lib/netscape.us}
export CLASSPATH ; CLASSPATH=.:$MOZILLA_HOME
export XCMSDB; XCMSDB=/dev/null
exec $MOZILLA_HOME/communicator-4.07.us.bin $*
