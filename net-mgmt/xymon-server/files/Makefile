# Toplevel Makefile for Hobbit
# $FreeBSD$
BUILDTOPDIR=`pwd`

# configure settings for Hobbit
#
# Toplevel dir
BBTOPDIR = ${PREFIX}/www/hobbit
# Server home dir for etc/, bin/
BBHOME = ${PREFIX}/www/hobbit/server
# Server data dir for hist/ etc.
BBVAR = ${PREFIX}/www/hobbit/data
# CGI scripts go in CGIDIR
CGIDIR = ${PREFIX}/www/hobbit/cgi-bin
# Admin CGI scripts go in SECURECGIDIR
SECURECGIDIR = ${PREFIX}/www/hobbit/cgi-secure
# Where to put logfiles
BBLOGDIR = /var/log/hobbit
# Where to install manpages
MANROOT = ${PREFIX}/man
# How to run fping or hobbitping
FPING = hobbitping

# Username running hobbit
#BBUSER = nobody
# Hobbit server hostname
#BBHOSTNAME = hobbit.example.com
# Hobbit server IP-address
#BBHOSTIP = 127.0.0.1
# Hobbit server OS
BBHOSTOS = freebsd

# URL for Hobbit webpages
BBHOSTURL = /hobbit
# URL for Hobbit CGIs
BBCGIURL = /hobbit-cgi
# URL for Hobbit Admin CGIs
SECUREBBCGIURL = /hobbit-seccgi
# Webserver group-ID
HTTPDGID=80

# RRDtool settings
RRDDEF = -DRRDTOOL12
RRDINCDIR = -I${LOCALBASE}/include
RRDLIBS = -L${LOCALBASE}/lib -lrrd -L${LOCALBASE}/lib -lpng
RPATHVAL += ${LOCALBASE}/lib

# PCRE settings
PCREINCDIR = -I${LOCALBASE}/include
PCRELIBS = -L${LOCALBASE}/lib -lpcre
RPATHVAL += ${LOCALBASE}/lib
#
# OpenSSL settings
SSLFLAGS = -DBBGEN_SSL
SSLINCDIR = -I${OPENSSLINC}
SSLLIBS = -L${OPENSSLLIB} -lssl -lcrypto
RPATHVAL += ${OPENSSLLIB}
#
ifdef WITH_LDAP
# OpenLDAP settings
LDAPFLAGS = -DBBGEN_LDAP -DBBGEN_LDAP_USESTARTTLS
LDAPINCDIR = -I${PREFIX}/include
LDAPLIBS = -L${PREFIX}/lib -lldap -llber
RPATHVAL += ${PREFIX}/lib
endif
#
# Large File Support settings
LFSDEF = -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64

include build/Makefile.FreeBSD


# Add local CFLAGS etc. settings here

include build/Makefile.rules

