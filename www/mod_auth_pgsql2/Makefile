# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	mod_auth_pgsql
PORTVERSION=	2.0.3
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.giuseppetanzilli.it/mod_auth_pgsql2/dist/
PKGNAMESUFFIX=	2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows users to use PostgreSQL databases for user authentication

USES=		apache:2.2+ pgsql

AP_INC?=	${LOCALBASE}/include
AP_LIB?=	${LOCALBASE}/lib -lpq
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
PORTDOCS=	mod_auth_pgsql.html

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
