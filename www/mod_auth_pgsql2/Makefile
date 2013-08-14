# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	mod_auth_pgsql
PORTVERSION=	2.0.3
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.giuseppetanzilli.it/mod_auth_pgsql2/dist/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows users to use PostgreSQL databases for user authentication


USE_PGSQL=	yes
USE_APACHE=	22

LATEST_LINK=	mod_auth_pgsql2

AP_INC?=	${LOCALBASE}/include
AP_LIB?=	${LOCALBASE}/lib -lpq
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
PORTDOCS=	mod_auth_pgsql.html

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/mod_auth_pgsql.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
