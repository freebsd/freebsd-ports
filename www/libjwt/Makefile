# Created by: Kevin Lo <kevlo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libjwt
PORTVERSION=	1.11.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSON Web Token implementation in C

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/MPL-2.0

BUILD_DEPENDS=	jansson>=2.0:devel/jansson
LIB_DEPENDS=	libjansson.so:devel/jansson
TEST_DEPENDS=	check>=0.9.4:devel/check

USES=		autoreconf gmake libtool pathfix pkgconfig ssl

USE_GITHUB=	yes
GH_ACCOUNT=	benmcollins

CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto -lssl"
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_ARGS=	CFLAGS+=-I${LOCALBASE}/include LIBS+="-L${LOCALBASE}/lib -lcheck"
TEST_TARGET=	check
USE_LDCONFIG=	yes

.include <bsd.port.mk>
