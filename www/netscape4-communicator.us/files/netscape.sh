#!/bin/sh
export MOZILLA_HOME; MOZILLA_HOME=${MOZILLA_HOME:=@PREFIX@/lib/netscape.us}
export CLASSPATH ; CLASSPATH=.:$MOZILLA_HOME
export XCMSDB; XCMSDB=/dev/null
exec $MOZILLA_HOME/communicator-pro-4.05.us.bin $*
