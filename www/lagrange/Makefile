PORTNAME=	lagrange
DISTVERSION=	1.7.3
CATEGORIES=	www
MASTER_SITES=	https://git.skyjake.fi/gemini/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Beautiful Gemini Client

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BROKEN_SSL=	libressl
BROKEN_SSL_REASON_libressl=	needs features only available in OpenSSL

LIB_DEPENDS=	libfribidi.so:converters/fribidi \
		libharfbuzz.so:print/harfbuzz \
		libmpg123.so:audio/mpg123 \
		libpcre.so:devel/pcre \
		libunistring.so:devel/libunistring

USES=		cmake compiler:c11 desktop-file-utils pkgconfig sdl ssl
USE_SDL=	sdl2

OPTIONS_DEFINE=	SSE41

SSE41_DESC=	Enable SSE4.1 support
SSE41_CMAKE_ON=	-DTFDN_ENABLE_SSE41:BOOL=ON

OPENSSL_LDFLAGS=	-lssl -lcrypto

.include <bsd.port.mk>
