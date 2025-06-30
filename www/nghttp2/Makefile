PORTNAME=	nghttp2
PORTVERSION=	1.66.0
PORTREVISION=	1
CATEGORIES=	www net
MASTER_SITES=	https://github.com/nghttp2/nghttp2/releases/download/v${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP/2 tools
WWW=		https://nghttp2.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	libnghttp2>=${PORTVERSION}:www/libnghttp2
LIB_DEPENDS=	libnghttp2.so:www/libnghttp2

USES=		cmake compiler:c++20-lang cpe localbase:ldflags pathfix pkgconfig python:env ssl tar:xz

CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR=share/man
CMAKE_OFF=	BUILD_SHARED_LIBS \
		BUILD_STATIC_LIBS \
		BUILD_TESTING \
		ENABLE_DEBUG \
		ENABLE_HTTP3 \
		ENABLE_LIB_ONLY \
		ENABLE_STATIC_CRT \
		ENABLE_WERROR \
		WITH_LIBBPF \
		WITH_MRUBY \
		WITH_NEVERBLEED
CMAKE_ON=	ENABLE_FAILMALLOC \
		ENABLE_THREADS \
		WITH_JEMALLOC
USE_CXXSTD=	c++20
USE_RC_SUBR=	nghttpx

OPTIONS_DEFINE=	APP DOCS EXAMPLES HPACK
OPTIONS_DEFAULT=APP HPACK
OPTIONS_SUB=	yes
APP_DESC=	Build h2load, nghttp, nghttpd and nghttpx

APP_BUILD_DEPENDS=	c-ares>=1.7.5:dns/c-ares \
			libev>=4.11:devel/libev
APP_CMAKE_BOOL=		ENABLE_APP WITH_LIBXML2
APP_LIB_DEPENDS=	libcares.so:dns/c-ares \
			libev.so:devel/libev
APP_USE=		GNOME=libxml2
APP_USES=		gnome
DOCS_CMAKE_BOOL=	ENABLE_DOC
EXAMPLES_BUILD_DEPENDS=	libevent>=2.0.8:devel/libevent
EXAMPLES_CMAKE_BOOL=	ENABLE_EXAMPLES
EXAMPLES_LIB_DEPENDS=	libevent_openssl.so:devel/libevent
HPACK_BUILD_DEPENDS=	jansson>=2.5:devel/jansson
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
