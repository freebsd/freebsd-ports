# New ports collection makefile for:	mod_traf_thief
# Date created:				Sun Oct  5
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	mod_traf_thief
PORTVERSION=	0.01
CATEGORIES=	www
MASTER_SITES=	http://sheepkiller.nerim.net/ports/${PORTNAME}/
EXTRACT_SUFX=	.c
# Original location: http://web.god.net.ru/projects/mod_traf_thief/dist/
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows you to redirect part of the traffic to your url

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache2
RUN_DEPENDS=	${BUILD_DEPENDS}

RESTRICTED=	No licence

NO_WRKSUBDIR=	YES
APXS?=		${LOCALBASE}/sbin/apxs

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} ${WRKDIR}/${PORTNAME}.c

do-build:
	@(cd ${WRKSRC} && ${APXS} -c ${PORTNAME}.c)

do-install:
	@(cd ${WRKSRC} && ${APXS} -A -i ${PORTNAME}.la)

.include <bsd.port.mk>
