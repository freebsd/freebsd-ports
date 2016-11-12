# Created by: Kevin Lo <kevlo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libjwt
PORTVERSION=	1.7.1
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	JSON Web Token implementation in C

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libcheck.so:devel/libcheck \
		libjansson.so:devel/jansson

USE_GITHUB=	yes
GH_ACCOUNT=	benmcollins

USES=		autoreconf gmake libtool pkgconfig ssl
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OPENSSL_CFLAGS="-I/usr/include" \
		OPENSSL_LIBS="-lcrypto -lssl"

INSTALL_TARGET=	install-strip

post-patch:
	${REINPLACE_CMD} -e 's|^pkgconfiglibdir.*|pkgconfiglibdir = ${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/libjwt/Makefile.am

.include <bsd.port.mk>
