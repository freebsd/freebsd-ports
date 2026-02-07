PORTNAME=	tdlib
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.48
PORTREVISION=	4
CATEGORIES=	net-im devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for building Telegram clients
WWW=		https://github.com/tdlib/td

LICENSE=	BSL

USES=		cmake:testing compiler:c++14-lang gperf readline ssl

CONFLICTS_INSTALL=	tde2e

USE_GITHUB=	yes
GH_PROJECT=	td
GH_TAGNAME=	b8b08b0 # hash corresponding to 1.8.48

CMAKE_ON=	TD_INSTALL_SHARED_LIBRARIES TD_INSTALL_STATIC_LIBRARIES \
		BUILD_SHARED_LIBS
CMAKE_OFF+=	TD_E2E_ONLY # supposed to install tde2e but it fails to install headers
CMAKE_OFF+=	BUILD_TESTING FREEBSD_BUILD_BENCHMARKS

PLIST_SUB+=	LIBVERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|%%COMMIT%%|${GH_TAGNAME}|g' \
		${WRKSRC}/CMake/GetGitRevisionDescription.cmake

post-install: # see https://github.com/tdlib/td/issues/3328
	@cd ${WRKSRC}/td && \
		${COPYTREE_SHARE} telegram ${STAGEDIR}${PREFIX}/include/td "-name *\.h -o -name *\.hpp"
	@cd ${WRKSRC}/tdutils/td && \
		${COPYTREE_SHARE} utils ${STAGEDIR}${PREFIX}/include/td "-name *\.h -o -name *\.hpp"
	@cd ${WRKSRC}/tde2e/td && \
		${COPYTREE_SHARE} e2e ${STAGEDIR}${PREFIX}/include/td "-name *\.h -o -name *\.hpp"

.include <bsd.port.mk>
