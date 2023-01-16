PORTNAME=	nghttp2
DISTVERSION=	1.51.0
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
USE_RC_SUBR=	nghttpx
SHEBANG_FILES=	script/fetch-ocsp-response

CMAKE_OFF=	ENABLE_PYTHON_BINDINGS ENABLE_HTTP3
CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR:PATH=man

OPTIONS_DEFINE=	APP DOCS EXAMPLES HPACK
OPTIONS_DEFAULT=APP HPACK
OPTIONS_SUB=	yes

APP_DESC=	Build h2load, nghttp, nghttpd and nghttpx

APP_LIB_DEPENDS=	libcares.so:dns/c-ares \
			libev.so:devel/libev
APP_USES=		gnome
APP_USE=		GNOME=libxml2
APP_CMAKE_BOOL=		ENABLE_APP WITH_LIBXML2
HPACK_LIB_DEPENDS=	libjansson.so:devel/jansson
HPACK_CMAKE_BOOL=	ENABLE_HPACK_TOOLS
EXAMPLES_LIB_DEPENDS=	libevent_openssl.so:devel/libevent
EXAMPLES_CMAKE_BOOL=	ENABLE_EXAMPLES

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/nghttpx/
	${INSTALL_DATA} ${FILESDIR}/nghttpx.conf.sample ${STAGEDIR}${PREFIX}/etc/nghttpx/nghttpx.conf.sample

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/examples/ && ${INSTALL_DATA} client.c deflate.c libevent-client.c libevent-server.c ${STAGEDIR}${EXAMPLESDIR}/
	cd ${INSTALL_WRKSRC}/examples/ && ${INSTALL_PROGRAM} client deflate libevent-client libevent-server ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
