# $FreeBSD$

PORTNAME=	litmus
PORTVERSION=	0.13
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.webdav.org/neon/litmus/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	WebDAV server protocol compliance test suite

LIB_DEPENDS=	libneon.so:www/neon \
		libk5crypto.so:security/krb5

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-ssl --with-neon=/usr/local

.include <bsd.port.mk>
