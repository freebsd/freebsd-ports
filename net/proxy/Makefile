# New ports collection Makefile for:	proxy
# Date created:		22 August 2000
# Whom:			jasone
#
# $FreeBSD$
#

PORTNAME=	proxy
PORTVERSION=	1.2.0
CATEGORIES=	net
DISTNAME=	canonware-1.2.0
MASTER_SITES=	http://www.canonware.com/download/canonware/

MAINTAINER=	jasone@FreeBSD.org

BUILD_DEPENDS=	cook:${PORTSDIR}/devel/cook

GNU_CONFIGURE=	yes

MAN1=		proxy.1
MANCOMPRESSED=	no

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} cook bin/proxy/src/proxy)

do-install:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} cook proxy_install_a)

post-install:
	@strip ${PREFIX}/bin/proxy

.include <bsd.port.mk>
