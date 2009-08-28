# New ports collection makefile for:	mod_fileiri
# Date created:				2008/05/27
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	mod_fileiri
PORTVERSION=	1.15
CATEGORIES=	www
MASTER_SITES=	LOCAL/chinsan
DIST_SUBDIR=	apache2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A http IRIs module for Apache 2

MAKE_JOBS_SAFE=  yes

USE_APACHE=	20+
PLIST_SUB=	APACHE_DIR=${APACHEMODDIR}

do-build:
	cd ${WRKSRC} && ${APXS} -c ${PORTNAME}.c

do-install:
	${APXS} -i -c -n fileiri ${WRKSRC}/${PORTNAME}.so

.include <bsd.port.mk>
