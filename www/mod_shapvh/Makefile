# New ports collection makefile for: 	mod_shapvh
# Date created: 			17 Nov 2004
# Whom:					Steven Looman <steven@krx.nl>
#
# $FreeBSD$
#

PORTNAME=	mod_shapvh
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.crazygreek.co.uk/data/pages/mod_shapvh/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.c

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Apache module that provides virtual hosts from a database

DEPRECATED=	apache13 is deprecated, migrate to 2.2.x+ now
EXPIRATION_DATE=	2011-11-01

MAKE_JOBS_SAFE=  yes

USE_APACHE=	13
USE_MYSQL=	yes

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

AP_INC=	${LOCALBASE}/include
AP_LIB=	${LOCALBASE}/lib/mysql -lmysqlclient

NO_WRKSUBDIR=	yes

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

.include <bsd.port.mk>
