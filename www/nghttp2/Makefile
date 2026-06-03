PORTNAME=	nghttp2
PORTVERSION=	1.69.0
CATEGORIES=	www net
MASTER_SITES=	https://github.com/nghttp2/nghttp2/releases/download/v${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP/2 tools
WWW=		https://nghttp2.org/ \
		https://github.com/nghttp2/nghttp2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	libnghttp2>=${PORTVERSION}:www/libnghttp2
LIB_DEPENDS=	libnghttp2.so:www/libnghttp2

USES=		cmake compiler:c++20-lang cpe localbase:ldflags pkgconfig python:env ssl tar:xz

CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR=share/man
CMAKE_OFF=	BUILD_SHARED_LIBS \
		BUILD_STATIC_LIBS \
		BUILD_TESTING \
		ENABLE_DEBUG \
		ENABLE_FAILMALLOC \
		ENABLE_HTTP3 \
		ENABLE_LIB_ONLY \
		ENABLE_STATIC_CRT \
		ENABLE_WERROR \
		WITH_JEMALLOC \
		WITH_LIBBPF \
		WITH_MRUBY \
		WITH_NEVERBLEED \
		WITH_WOLFSSL
CMAKE_ON=	ENABLE_THREADS
USE_CXXSTD=	c++20
USE_RC_SUBR=	nghttpx

OPTIONS_DEFINE=	APP DOCS EXAMPLES HPACK
OPTIONS_DEFAULT=APP HPACK
OPTIONS_SUB=	yes
APP_DESC=	Build h2load, nghttp, nghttpd and nghttpx

APP_CMAKE_BOOL=		ENABLE_APP WITH_LIBXML2
APP_LIB_DEPENDS=	libbrotlidec.so:archivers/brotli \
			libcares.so:dns/c-ares \
			libev.so:devel/libev
APP_USE=		GNOME=libxml2
APP_USES=		gnome
DOCS_CMAKE_BOOL=	ENABLE_DOC
EXAMPLES_CMAKE_BOOL=	ENABLE_EXAMPLES
EXAMPLES_LIB_DEPENDS=	libevent_openssl.so:devel/libevent
HPACK_CMAKE_BOOL=	ENABLE_HPACK_TOOLS
HPACK_LIB_DEPENDS=	libjansson.so:devel/jansson

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/nghttpx/
	${INSTALL_DATA} ${FILESDIR}/nghttpx.conf.sample ${STAGEDIR}${PREFIX}/etc/nghttpx/nghttpx.conf.sample

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/examples/*.c ${STAGEDIR}${EXAMPLESDIR}/
	cd ${BUILD_WRKSRC}/examples/ && ${INSTALL_PROGRAM} client deflate libevent-client libevent-server ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
