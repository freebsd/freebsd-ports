PORTNAME=	lagrange
DISTVERSION=	1.17.6
CATEGORIES=	www
MASTER_SITES=	https://git.skyjake.fi/gemini/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Beautiful Gemini Client
WWW=		https://gmi.skyjake.fi/lagrange/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	zip>0:archivers/zip
LIB_DEPENDS=	libfribidi.so:converters/fribidi \
		libharfbuzz.so:print/harfbuzz \
		libmpg123.so:audio/mpg123 \
		libpcre2-8.so:devel/pcre2 \
		libunistring.so:devel/libunistring \
		libwebp.so:graphics/webp

USES=		cmake compiler:c11 desktop-file-utils pkgconfig sdl ssl xorg
BROKEN_SSL=	libressl
BROKEN_SSL_REASON_libressl=	needs features only available in OpenSSL
USE_SDL=	sdl2
USE_XORG=	ice sm x11 xext

CMAKE_ARGS+=	-DTFDN_ENABLE_WARN_ERROR=OFF

OPTIONS_DEFINE=	SSE41

SSE41_DESC=	Enable SSE4.1 support
SSE41_CMAKE_ON=	-DTFDN_ENABLE_SSE41:BOOL=ON

.include <bsd.port.mk>
