# New ports collection makefile for: netscape.language
# Date created:         8 Apr 1996
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	netscape
PORTVERSION=    4.7
MASTER_SITES=   http://koi8.pp.ru/
DISTFILES=      v4.7.subject.patch.txt
CATEGORIES=	russian www
EXTRACT_ONLY=	# empty

MAINTAINER=	ache@FreeBSD.org

RUN_DEPENDS+=	${X11BASE}/lib/X11/nls/ru_SU.KOI8-R:${PORTSDIR}/russian/X.language
RUN_DEPENDS+=   netscape:${PORTSDIR}/www/netscape47-communicator

NO_BUILD=	YES
NO_WRKSUBDIR=	YES
USE_X_PREFIX=	YES

APPDEF=		${X11BASE}/lib/X11/app-defaults

do-install:
	if [ -f ${APPDEF}/Netscape ] ; then \
		${GREP} -q '\.version:.*4\.7' ${APPDEF}/Netscape || \
			${RM} ${APPDEF}/Netscape; \
	fi
	if [ ! -f ${APPDEF}/Netscape ] ; then \
		${CP} ${LOCALBASE}/lib/netscape/Netscape.ad ${APPDEF}/Netscape; \
	fi
	cd ${APPDEF}; ${GREP} -q koi8-r=BOLD Netscape || \
		patch < ${DISTDIR}/${DISTFILES}

.include <bsd.port.mk>
