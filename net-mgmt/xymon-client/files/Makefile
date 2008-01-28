# Toplevel Makefile for Hobbit
# $FreeBSD$
BUILDTOPDIR=`pwd`
CLIENTONLY = yes
LOCALCLIENT = no

# configure settings for Hobbit
#
# Toplevel dir
BBTOPDIR = ${PREFIX}/www/hobbit
# Server home dir for etc/, www/
BBHOME = ${PREFIX}/www/hobbit/client

# hobbit settings follows
#
# Username running hobbit
#BBUSER = nobody
# Hobbit server IP-address
#BBHOSTIP = 127.0.0.1
# Large File Support settings
LFSDEF = -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64

include build/Makefile.FreeBSD


#
# Add local CFLAGS etc. settings here

include build/Makefile.rules

