#!/bin/sh
export MOZILLA_HOME; MOZILLA_HOME=${MOZILLA_HOME:=@PREFIX@/lib/netscape}
export CLASSPATH ; CLASSPATH=.:$MOZILLA_HOME
exec $MOZILLA_HOME/communicator-4.04.bin $*
