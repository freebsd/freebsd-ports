# Toplevel Makefile for Xymon
# $FreeBSD$

BUILDTOPDIR=`pwd`
CLIENTONLY = yes
LOCALCLIENT = no

# configure settings for Xymon
#
# Toplevel dir
XYMONTOPDIR = ${PREFIX}/www/xymon/client

# hobbit settings follows
#
# Username running hobbit
#XYMONUSER = nobody
# Xymon server IP-address
#XYMONHOSTIP = 127.0.0.1
# Large File Support settings
LFSDEF = -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64

include build/Makefile.FreeBSD

# Add local CFLAGS, etc. settings here

include build/Makefile.rules
