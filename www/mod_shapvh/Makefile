# New ports collection makefile for: 	mod_shapvh
# Date created: 			17 Nov 2004
# Whom:					Steven Looman <steven@krx.nl>
#
# $FreeBSD$
#

PORTNAME=	mod_shapvh
PORTVERSION=	1.0
CATEGORIES=	www
MASTER_SITES=	http://www.crazygreek.co.uk/data/pages/mod_shapvh/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.c

MAINTAINER=	steven@krx.nl
COMMENT=	Apache module that provides virtual hosts from a database

MAKE_JOBS_SAFE=  yes

USE_APACHE=	1.3
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
