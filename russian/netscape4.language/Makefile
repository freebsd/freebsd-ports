# New ports collection makefile for: netscape.language
# Date created:         8 Apr 1996
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	netscape
PORTVERSION=	4.7
CATEGORIES=	russian www
MASTER_SITES=	http://koi8.pp.ru/
DISTNAME=	v4.7.subject.patch.txt
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	ache@FreeBSD.org

RUN_DEPENDS+=	${X11BASE}/lib/X11/nls/ru_SU.KOI8-R:${PORTSDIR}/russian/X.language
RUN_DEPENDS+=	netscape:${PORTSDIR}/www/netscape47-communicator

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes

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
		${PATCH} < ${DISTDIR}/${DISTFILES}

.include <bsd.port.mk>
