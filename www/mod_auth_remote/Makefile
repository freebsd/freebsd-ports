# New ports collection makefile for:	mod_auth_remote
# Date created:				Sun Oct  5
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	mod_auth_remote
PORTVERSION=	0.1
CATEGORIES=	www
MASTER_SITES=	http://sheepkiller.nerim.net/ports/${PORTNAME}/
# Original location is here: http://puggy.symonds.net/~srp/stuff/

MAINTAINER=	sheepkiller@cultdeadsheep.org
COMMENT=	Allows users to authenticate on a remote web server

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache2
RUN_DEPENDS=	${BUILD_DEPENDS}

APXS?=		${LOCALBASE}/sbin/apxs

do-build:
	@(cd ${WRKSRC} && ${APXS} -c ${PORTNAME}.c)

do-install:
	@(cd ${WRKSRC} && ${APXS} -A -i ${PORTNAME}.la)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
