#!/bin/sh
#
# Sample startup script for xyoubin.
#

xyoubin=@PREFIX@/bin/xyoubin
mailserver=localhost
bitmapdir=@PREFIX@/share/examples/youbin/Bitmap

if [ -x ${xyoubin} ]; then
    ${xyoubin} -server ${mailserver} -full ${bitmapdir}/youbinFull.xpm -empty ${bitmapdir}/youbinEmpty.xpm
fi
