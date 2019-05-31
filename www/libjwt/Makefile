# Created by: Kevin Lo <kevlo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libjwt
PORTVERSION=	1.10.2
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSON Web Token implementation in C

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/MPL-2.0

BUILD_DEPENDS=	jansson>=2.0:devel/jansson
LIB_DEPENDS=	libjansson.so:devel/jansson

USES=		autoreconf gmake libtool pathfix pkgconfig ssl

USE_GITHUB=	yes
GH_ACCOUNT=	benmcollins

CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto -lssl"
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.include <bsd.port.mk>
