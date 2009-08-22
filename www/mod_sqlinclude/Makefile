# New ports collection makefile for:    mod_sqlinclude
# Date created:				October 25 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$

PORTNAME=	mod_sqlinclude
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/mod-sqlinclude/mod-sqlinclude/${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	apache@FreeBSD.org
COMMENT=	An Apache module implementing config inclusion from MySQL databases

MAKE_JOBS_SAFE=  yes

USE_APACHE=	1.3
USE_MYSQL=	yes

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

AP_INC=	${LOCALBASE}/include
AP_LIB=	${LOCALBASE}/lib/mysql -lmysqlclient

PORTDOCS=		CHANGES.txt README.txt test.sql

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
