# New ports collection makefile for:    freeradius-mysql
# Date created:         05 February 2007
# Whom:                 David Wood <david@wood2.org.uk>
#
# $FreeBSD$

MAINTAINER=     david@wood2.org.uk
COMMENT=        A free RADIUS server implementation with MySQL support

# Set the necessary (private) knob before handing off to the master port
# (all the necessary support is in the master port)
FREERADIUS_SLAVE_MYSQL=	yes

MASTERDIR=      ${.CURDIR}/../freeradius

.include "${MASTERDIR}/Makefile"
