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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Apache module that implements the client side of the SCGI protocol

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/${APACHE_PORT}

do-build:
	cd ${WRKSRC} && ${APXS} -c -o mod_scgi.so mod_scgi.c

do-install:
	cd ${WRKSRC} && ${APXS} -i -a mod_scgi.so

.include <bsd.port.mk>
