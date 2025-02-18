PORTNAME=	concord
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.0
PORTREVISION=	1
CATEGORIES=	net-im devel

MAINTAINER=	mail@souji-thenria.net
COMMENT=	Discord library written in C
WWW=		https://github.com/Cogmasters/concord

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	Cogmasters
USE_LDCONFIG=	yes

MAKE_ARGS=	DESTINCLUDE_DIR=${STAGEDIR}${PREFIX}/include/concord \
		DESTLIBDIR=${STAGEDIR}${PREFIX}/lib \
		ABIVERSION=1 # This is for the soname value
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=		DEBUG DEBUG_HTTP DEBUG_WEBSOCKETS EXAMPLES SIGINTCATCH
OPTIONS_DEFAULT=	EXAMPLES
OPTIONS_SUB=		yes

DEBUG_HTTP_DESC=	Verbose debugging for HTTP communication
DEBUG_WEBSOCKETS_DESC=	Verbose debugging for WebSockets communication
SIGINTCATCH_DESC=	Shutdown gracefully when a SIGINT is received

DEBUG_VARS=			ALL_TARGET=debug
DEBUG_HTTP_CFLAGS=		-DCCORD_DEBUG_HTTP
DEBUG_WEBSOCKETS_CFLAGS=	-DCCORD_DEBUG_WEBSOCKETS
EXAMPLES_USES=			localbase:ldflags
EXAMPLES_VARS=			ALL_TARGET=examples
SIGINTCATCH_CFLAGS=		-DCCORD_SIGINTCATCH

post-patch-EXAMPLES-on:
	${REINPLACE_CMD} -e 's|\.\./config\.json|config.json|' ${WRKSRC}/examples/*.c

post-install-DEBUG-off:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libdiscord.so

post-install-EXAMPLES-on:
	${REINPLACE_CMD} -e 's|#include "\([^"]*\)\.h"|#include <concord/\1.h>|' \
		${WRKSRC}/examples/*.c
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} "*.c" ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_BIN}   "*"   ${STAGEDIR}${EXAMPLESDIR} \
		'! -name Makefile ! -name *\.bak ! -name *\.c ! -name *\.orig'
	${INSTALL_DATA} ${FILESDIR}/Makefile.examples    ${STAGEDIR}${EXAMPLESDIR}/Makefile
	${INSTALL_DATA} ${FILESDIR}/config.json.examples ${STAGEDIR}${EXAMPLESDIR}/config.json

.include <bsd.port.mk>
