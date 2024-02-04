PORTNAME=	nghttp2
DISTVERSION=	1.59.0
CATEGORIES=	www net
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP/2.0 C Library
WWW=		https://nghttp2.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	libnghttp2>=${DISTVERSION}:www/libnghttp2
LIB_DEPENDS=	libnghttp2.so:www/libnghttp2

USES=		cmake compiler:c++14-lang cpe localbase:ldflags pathfix \
		pkgconfig python:env shebangfix ssl tar:xz
SHEBANG_FILES=	script/fetch-ocsp-response

USE_RC_SUBR=	nghttpx

CMAKE_OFF=	ENABLE_DEBUG \
		ENABLE_HTTP3 \
		ENABLE_LIB_ONLY \
		ENABLE_STATIC_CRT \
		ENABLE_WERROR \
		WITH_LIBBPF \
		WITH_MRUBY \
		WITH_NEVERBLEED
CMAKE_ON=	ENABLE_DOC \
		ENABLE_FAILMALLOC \
		ENABLE_THREADS \
		CMAKE_DISABLE_FIND_PACKAGE_Jemalloc \
		CMAKE_DISABLE_FIND_PACKAGE_Libnghttp3 \
		CMAKE_DISABLE_FIND_PACKAGE_Libngtcp2 \
		CMAKE_DISABLE_FIND_PACKAGE_Libngtcp2_crypto_openssl

OPTIONS_DEFINE=	APP EXAMPLES HPACK
OPTIONS_DEFAULT=APP HPACK
OPTIONS_SUB=	yes

APP_DESC=	Build h2load, nghttp, nghttpd and nghttpx

APP_BUILD_DEPENDS=	c-ares>=1.7.5:dns/c-ares \
			libev>=4.11:devel/libev
APP_LIB_DEPENDS=	libcares.so:dns/c-ares \
			libev.so:devel/libev
APP_USE=		GNOME=libxml2
APP_USES=		gnome
APP_CMAKE_BOOL=		ENABLE_APP
APP_CMAKE_OFF=		-DCMAKE_DISABLE_FIND_PACKAGE_Libev:BOOL=True \
			-DCMAKE_DISABLE_FIND_PACKAGE_LibXml2:BOOL=True

EXAMPLES_BUILD_DEPENDS=	libevent>=2.0.8:devel/libevent
EXAMPLES_LIB_DEPENDS=	libevent_openssl.so:devel/libevent
EXAMPLES_CMAKE_BOOL=	ENABLE_EXAMPLES
EXAMPLES_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_Libevent:BOOL=True

HPACK_BUILD_DEPENDS=	jansson>=2.5:devel/jansson
HPACK_LIB_DEPENDS=	libjansson.so:devel/jansson
HPACK_CMAKE_BOOL=	ENABLE_HPACK_TOOLS
HPACK_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_Jansson:BOOL=True

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/nghttpx/
	${INSTALL_DATA} ${FILESDIR}/nghttpx.conf.sample ${STAGEDIR}${PREFIX}/etc/nghttpx/nghttpx.conf.sample

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/examples/*.c ${STAGEDIR}${EXAMPLESDIR}/
	cd ${BUILD_WRKSRC}/examples/ && ${INSTALL_PROGRAM} client deflate libevent-client libevent-server ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
