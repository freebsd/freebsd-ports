# Created by: Kevin Lo <kevlo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libjwt
PORTVERSION=	1.3.1
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

USES=		libtool pkgconfig pathfix ssl
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openssl=${OPENSSLBASE}
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
