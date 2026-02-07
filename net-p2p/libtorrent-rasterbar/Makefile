PORTNAME=	libtorrent-rasterbar
DISTVERSION=	1.2.20 # 2.x is unusable until memory problems are resolved, see https://github.com/arvidn/libtorrent/issues/6781
PORTREVISION=	2
PORTEPOCH=	2
CATEGORIES=	net-p2p
MASTER_SITES=	https://github.com/arvidn/libtorrent/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library implementing a BitTorrent client
WWW=		https://libtorrent.org \
		https://github.com/arvidn/libtorrent

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		fails to build with Boost>=1.87, see https://github.com/arvidn/libtorrent/issues/7875

LIB_DEPENDS=	libboost_chrono.so:devel/boost-libs \
		libboost_random.so:devel/boost-libs \
		libboost_thread.so:devel/boost-libs

USES=		cmake compiler:c++17-lang iconv:wchar_t localbase:ldflags pathfix pkgconfig python:test shebangfix ssl
SHEBANG_FILES=	test/socks.py test/web_server.py
USE_LDCONFIG=	yes

USE_CXXSTD=	c++17 # prevent boost-related SEGV, see bug#264278

LDFLAGS+=	${ICONV_LIB}

SHLIB_VER=	10
PLIST_SUB+=	SHLIB_VER="${SHLIB_VER}" SO_VER="${DISTVERSION}"

DOCFILES=	AUTHORS ChangeLog
PORTDOCS=	${DOCFILES} docs/*
PORTEXAMPLES=	*.cpp

OPTIONS_DEFINE=		DOCS EXAMPLES LOGGING
OPTIONS_DEFAULT=	LOGGING
OPTIONS_SUB=		yes
LOGGING_DESC=		Enable logging to disk

EXAMPLES_CMAKE_BOOL=	build_examples
LOGGING_CMAKE_BOOL=	logging

PORTSCOUT=	limit:^1.* # 2.x is WIP and we don't accept it before qBittorrent does

CONFLICTS_INSTALL=	libtorrent-rasterbar2

post-patch:
	@${REINPLACE_CMD} -e 's|return "python3";|return "${PYTHON_CMD}";|' \
		${WRKSRC}/test/setup_transfer.cpp

post-install:
	# py-bindings seems to link this exact name after v1.2.14
	# TODO: figure out how to make symlinks in Jamfile
	/bin/ln -s libtorrent-rasterbar.so.${DISTVERSION} ${STAGEDIR}${PREFIX}/lib/libtorrent-rasterbar.so.10.0.0
	@${RM} ${STAGEDIR}${PREFIX}/include/libtorrent/Makefile*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCFILES:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${STAGEDIR}${DOCSDIR}
	${RM} ${STAGEDIR}${DOCSDIR}/docs/._*

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/${PORTEXAMPLES} \
		${STAGEDIR}${EXAMPLESDIR}

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -Dbuild_tests:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
