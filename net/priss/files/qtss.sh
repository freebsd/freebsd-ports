#!/bin/sh

cd `dirname $0`
cd ../..
PREFIX=`pwd`
QTSS_PROXY=${PREFIX}/sbin/QuickTimeStreamingServer
[ -x ${QTSS_PROXY} ] && ${QTSS_PROXY} && echo -n ' qtss'
