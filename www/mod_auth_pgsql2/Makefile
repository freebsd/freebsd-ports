# New ports collection makefile for:	mod_auth_pgsql2
# Date created:				Mon Oct  6
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$

PORTNAME=	mod_auth_pgsql
PORTVERSION=	2.0.2b1
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.giuseppetanzilli.it/mod_auth_pgsql2/dist/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows users to use PostgreSQL databases for user authentication

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache2
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PGSQL=	yes

LATEST_LINK=	mod_auth_pgsql2

APXS?=		${LOCALBASE}/sbin/apxs
PG_INC?=	${LOCALBASE}/include
PG_LIBS?=	${LOCALBASE}/lib -lpq

do-build:
	@(cd ${WRKSRC} && ${APXS} -I ${PG_INC} -L ${PG_LIBS} -c ${PORTNAME}.c)

do-install:
	@(cd ${WRKSRC} && ${APXS} -A -i ${PORTNAME}.la)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/mod_auth_pgsql.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
