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

USE_APACHE=	yes
USE_MYSQL=	yes
NO_WRKSUBDIR=	yes

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

do-build:
	@cd ${WRKSRC} && ${APXS} -c -l mysqlclient -I ${PREFIX}/include -L ${PREFIX}/lib/mysql ${PORTNAME}.c

do-install:
	${APXS} -i -A -n ${PORTNAME:S/^mod_//g} ${WRKSRC}/${PORTNAME}.so

.include <bsd.port.mk>
