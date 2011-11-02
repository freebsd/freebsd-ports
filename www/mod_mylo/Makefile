# New ports collection makefile for:	mod_mylo
# Date created:				12 November 2001
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	mod_mylo
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://sheepkiller.nerim.net/ports/${PORTNAME}/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	An Apache module to make Apache log to MySQL

DEPRECATED=	apache13 is deprecated, migrate to 2.2.x+ now
EXPIRATION_DATE=	2012-01-01

MAKE_JOBS_SAFE=  yes

USE_APACHE=	13
USE_MYSQL=	YES

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

AP_INC=	${LOCALBASE}/include
AP_LIB=	${LOCALBASE}/lib/mysql -lmysqlclient

PORTDOCS=	mod_mylo.sql README

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
