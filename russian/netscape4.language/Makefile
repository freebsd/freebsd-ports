# New ports collection makefile for: netscape.language
# Version required:     3.01
# Date created:         8 Apr 1996
# Whom:                 ache
#
# $Id: Makefile,v 1.12 1996/12/08 01:15:22 max Exp $
#

PKGNAME=        ru-netscape-3.01
CATEGORIES=     russian www

MAINTAINER=	ache@FreeBSD.ORG

RUN_DEPENDS += ${X11BASE}/lib/X11/nls/ru_SU.KOI8-R:${PORTSDIR}/russian/X.language
RUN_DEPENDS += netscape:${PORTSDIR}/www/netscape3

RESTRICTED=     "Includes a copyrighted file from Netscape"
NO_EXTRACT=     YES
NO_BUILD=       YES
NO_WRKDIR=      YES
USE_X11=        YES

APPDEF = ${X11BASE}/lib/X11/app-defaults

# no distfile to fetch
do-fetch:

do-install:
	if [ -f ${APPDEF}/Netscape ] ; then \
		grep -q '\.version:.*3\.01$$' ${APPDEF}/Netscape || \
			${RM} ${APPDEF}/Netscape; \
	fi
	if [ ! -f ${APPDEF}/Netscape ] ; then \
		${CP} /usr/local/lib/netscape/Netscape.ad ${APPDEF}/Netscape; \
	fi
	cd ${APPDEF}; grep -q koi8-r=BOLD Netscape || \
		patch < ${FILESDIR}/koi8-r_patch;

.include <bsd.port.mk>
