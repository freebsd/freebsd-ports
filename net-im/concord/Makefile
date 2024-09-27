PORTNAME=	concord
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.0
CATEGORIES=	net-im devel

MAINTAINER=	mail@souji-thenria.net
COMMENT=	Discord library written in C
WWW=		https://github.com/Cogmasters/concord

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	curl>=7.56.1:ftp/curl
RUN_DEPENDS=	curl>=7.56.1:ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	Cogmasters

MAKE_ARGS=	DESTINCLUDE_DIR=${STAGEDIR}${PREFIX}/include/concord \
		DESTLIBDIR=${STAGEDIR}${PREFIX}/lib

OPTIONS_DEFINE=		DEBUG_HTTP DEBUG_WEBSOCKETS EXAMPLES SIGINTCATCH
OPTIONS_DEFAULT=	EXAMPLES SHARED
OPTIONS_SINGLE=		TARGETS
OPTIONS_SINGLE_TARGETS=	DEBUG SHARED STATIC
OPTIONS_SUB=		yes

DEBUG_HTTP_DESC=	Verbose debugging for HTTP communication
DEBUG_WEBSOCKETS_DESC=	Verbose debugging for WebSockets communication
SHARED_DESC=		Build dynamically linked version
SIGINTCATCH_DESC=	Shutdown gracefully when a SIGINT is received
STATIC_DESC=		Build statically linked version

DEBUG_VARS=			ALL_TARGET=debug
DEBUG_HTTP_CFLAGS=		-DCCORD_DEBUG_HTTP
DEBUG_WEBSOCKETS_CFLAGS=	-DCCORD_DEBUG_WEBSOCKETS
SHARED_LIB_DEPENDS=		libcurl.so:ftp/curl
SHARED_VARS=			ALL_TARGET=shared
SIGINTCATCH_CFLAGS=		-DCCORD_SIGINTCATCH
STATIC_VARS=			ALL_TARGET=static

post-install-EXAMPLES-on:
	${REINPLACE_CMD} -e 's|#include "\([^"]*\)\.h"|#include <concord/\1.h>|; \
		s|\.\./config\.json|config.json|' ${WRKSRC}/examples/*.c
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} "*.c" ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/Makefile.examples ${STAGEDIR}${EXAMPLESDIR}/Makefile
	${INSTALL_DATA} ${FILESDIR}/config.json.examples ${STAGEDIR}${EXAMPLESDIR}/config.json

post-install-SHARED-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libdiscord.so

.include <bsd.port.mk>
