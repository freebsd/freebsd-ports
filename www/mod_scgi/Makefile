# New ports collection makefile for: scgi
# Date created:		19 Aug 2002
# Whom:			Neil Blakey-Milner <nbm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scgi
PORTVERSION=	0.2
CATEGORIES=	www
MASTER_SITES=	http://www.mems-exchange.org/software/files/scgi/
PKGNAMEPREFIX=	mod_

MAINTAINER=	nbm@FreeBSD.org

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13

APXS?=		${PREFIX}/sbin/apxs

do-build:
	cd ${WRKSRC} && ${APXS} -c -o mod_scgi.so mod_scgi.c

do-install:
	cd ${WRKSRC} && ${APXS} -i -a mod_scgi.so

.include <bsd.port.mk>
