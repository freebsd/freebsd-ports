# New ports collection makefile for: netscape.language
# Date created:         8 Apr 1996
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	netscape
PORTVERSION= 	3.01
CATEGORIES=     russian www

MAINTAINER=	ache@FreeBSD.org

RUN_DEPENDS += ${X11BASE}/lib/X11/nls/ru_SU.KOI8-R:${PORTSDIR}/russian/X.language
RUN_DEPENDS += netscape:${PORTSDIR}/www/netscape3

RESTRICTED=     "Includes a copyrighted file from Netscape"
EXTRACT_ONLY=   # empty
NO_BUILD=       YES
NO_WRKSUBDIR=   YES
USE_X_PREFIX=   YES

APPDEF = ${X11BASE}/lib/X11/app-defaults

# no distfile to fetch
do-fetch:

do-install:
	if [ -f ${APPDEF}/Netscape ] ; then \
		${GREP} -q '\.version:.*3\.01$$' ${APPDEF}/Netscape || \
			${RM} ${APPDEF}/Netscape; \
	fi
	if [ ! -f ${APPDEF}/Netscape ] ; then \
		${CP} /usr/local/lib/netscape/Netscape.ad ${APPDEF}/Netscape; \
	fi
	cd ${APPDEF}; ${GREP} -q koi8-r=BOLD Netscape || \
		patch < ${FILESDIR}/koi8-r_patch;

.include <bsd.port.mk>
