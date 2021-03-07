# $FreeBSD$

PORTNAME=	lagrange
DISTVERSION=	1.2.2
CATEGORIES=	www
MASTER_SITES=	https://git.skyjake.fi/skyjake/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Beautiful Gemini Client

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BROKEN_SSL=	libressl
BROKEN_SSL_REASON_libressl=	needs features only available in OpenSSL

LIB_DEPENDS=	libmpg123.so:audio/mpg123 \
		libpcre.so:devel/pcre \
		libunistring.so:devel/libunistring

USES=		cmake compiler:c11 desktop-file-utils pkgconfig sdl ssl
USE_SDL=	sdl2

OPENSSL_LDFLAGS=	-lssl -lcrypto

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1200085 && ${SSL_DEFAULT} == base
BROKEN=		requires at least OpenSSL version 1.1.1 to build
.endif

.include <bsd.port.post.mk>
