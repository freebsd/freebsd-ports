# New ports collection makefile for:	mod_auth_pgsql2
# Date created:				Mon Oct  6
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$

PORTNAME=	mod_auth_pgsql
PORTVERSION=	2.0.3
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.giuseppetanzilli.it/mod_auth_pgsql2/dist/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows users to use PostgreSQL databases for user authentication

MAKE_JOBS_SAFE=  yes

USE_PGSQL=	yes
USE_APACHE=	20+

LATEST_LINK=	mod_auth_pgsql2

AP_INC?=	${LOCALBASE}/include
AP_LIB?=	${LOCALBASE}/lib -lpq
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
PORTDOCS=	mod_auth_pgsql.html

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/mod_auth_pgsql.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
