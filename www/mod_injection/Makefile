# New ports collection makefile for:	mod_injection
# Date created:				Sun Oct  5
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	mod_injection
PORTVERSION=	0.3.1
CATEGORIES=	www
MASTER_SITES=	http://pmade.org/software/mod_injection/download/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Injects text in the HTTP response after a HTML tag

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache2
RUN_DEPENDS=	${BUILD_DEPENDS}

APXS?=		${LOCALBASE}/sbin/apxs

do-build:
	@(cd ${WRKSRC}/src && ${APXS} -c ${PORTNAME}.c)

do-install:
	@(cd ${WRKSRC}/src && ${APXS} -A -i ${PORTNAME}.la)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CP} -Rf ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
