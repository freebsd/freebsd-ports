# New ports collection makefile for:	mod_authenticache
# Date created:				Fri Oct  10
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$

PORTNAME=	mod_authenticache
PORTVERSION=	2.0.6
CATEGORIES=	www
MASTER_SITES=	http://killa.net/infosec/mod_authenticache/
DIST_SUBDIR=	apache

MAINTAINER=	sheeepkiller@cultdeadsheep.org
COMMENT=	A generic credential caching module for Apache 2.0.x

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache2
RUN_DEPENDS=	${BUILD_DEPENDS}

APXS?=		${LOCALBASE}/sbin/apxs

do-build:
	@(cd ${WRKSRC}/ && ${APXS} -I. -c ${PORTNAME}.c)

do-install:
	@(cd ${WRKSRC}/ && ${APXS} -A -i ${PORTNAME}.la)

.include <bsd.port.mk>
