# New ports collection makefile for:	mod_bandwidth
# Date created:				2 July 2003
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	mod_bandwidth
PORTVERSION=	2.0.4
CATEGORIES=	www
MASTER_SITES=	http://sheepkiller.nerim.net/ports/${PORTNAME}/ \
		http://www.cultdeadsheep.org/FreeBSD/ports/download/distfiles/
EXTRACT_SUFX=   .c

MAINTAINER=	sheepkiller@cultdeadsheep.org
COMMENT=	Bandwidth management module for the Apache webserver

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${BUILD_DEPENDS}

NO_WRKSUBDIR=	YES

APXS?=		${LOCALBASE}/sbin/apxs

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}/${PORTNAME}.c

do-build:
	@(cd ${WRKSRC} && ${APXS} -c ${PORTNAME}.c)

do-install:
	@(cd ${WRKSRC} && ${APXS} -A -i ${PORTNAME}.so)
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
