# New ports collection makefile for: netscape.language
# Version required:     3.0b3
# Date created:         8 Apr 1996
# Whom:                 ache
#
# $Id: Makefile,v 1.1.1.1 1996/04/08 01:09:42 ache Exp $
#

PKGNAME=        ru-netscape-3.0b3
CATEGORIES+=    russian www x11

MAINTAINER=	ache@FreeBSD.ORG

RUN_DEPENDS += ${X11BASE}/lib/X11/nls/ru_SU.KOI8-R:${PORTSDIR}/russian/X.language
RUN_DEPENDS += netscape:${PORTSDIR}/www/netscape3

NO_PATCH=       YES
NO_EXTRACT=     YES
NO_CONFIGURE=   YES
NO_BUILD=       YES
NO_WRKDIR=      YES
NO_PACKAGE=     YES
USE_X11=        YES

APPDEF = ${X11BASE}/lib/X11/app-defaults

# no distfile to fetch
do-fetch:

do-install:
	if [ -f ${APPDEF}/Netscape ] ; then \
		grep -q '\.version:.*3\.0b3$$' ${APPDEF}/Netscape || \
			rm ${APPDEF}/Netscape; \
	fi
	if [ ! -f ${APPDEF}/Netscape ] ; then \
		cp /usr/local/lib/netscape/Netscape.ad ${APPDEF}/Netscape; \
	fi
	cd ${APPDEF}; grep -q koi8 Netscape || \
		patch < ${FILESDIR}/koi8-r_patch;

.include <bsd.port.mk>
