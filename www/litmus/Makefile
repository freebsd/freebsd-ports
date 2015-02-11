# $FreeBSD$

PORTNAME=	litmus
PORTVERSION=	0.13
CATEGORIES=	www
MASTER_SITES=	http://www.webdav.org/neon/litmus/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	WebDAV server protocol compliance test suite

LIB_DEPENDS=	libneon.so:${PORTSDIR}/www/neon

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-ssl

.include <bsd.port.mk>
