# New ports collection makefile for:    apache mod_auth_pgsql
# Date created:		2000/11/10
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$

PORTNAME=	mod_auth_pgsql
PORTVERSION=	0.9.12
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://www.giuseppetanzilli.it/${PORTNAME}/dist/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows users to use PostgreSQL databases for user authentication

MAKE_JOBS_SAFE=  yes

USE_DOS2UNIX=	${PORTNAME}.html

USE_PGSQL=	yes
USE_APACHE=	1.3

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
AP_INC=	${LOCALBASE}/include
AP_LIB=	${LOCALBASE}/lib -lpq

PORTDOCS=	README index.html

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.html ${DOCSDIR}/index.html
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
