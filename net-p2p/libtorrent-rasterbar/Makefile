# Created by: Doug Barton <dougb@FreeBSD.org>

PORTNAME=	libtorrent-rasterbar
DISTVERSION=	1.2.13
PORTEPOCH=	1
CATEGORIES=	net-p2p
MASTER_SITES=	https://github.com/arvidn/libtorrent/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library implementing a BitTorrent client

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_chrono.so:devel/boost-libs \
		libboost_random.so:devel/boost-libs \
		libboost_system.so:devel/boost-libs

USES=		cmake compiler:c++11-lib iconv:wchar_t libtool localbase:ldflags pathfix pkgconfig python:test shebangfix ssl
SHEBANG_FILES=	test/socks.py test/web_server.py
USE_LDCONFIG=	yes

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

post-patch:
	@${REINPLACE_CMD} -e 's|return "python3";|return "${PYTHON_CMD}";|' \
		${WRKSRC}/test/setup_transfer.cpp

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/include/libtorrent/Makefile*
	# Workaround for -DTHREADS_HAVE_PTHREAD_ARG:BOOL=YES being set in
	# Mk/Uses/cmake.mk
	# References:   https://mariadb.atlassian.net/browse/MDEV-9388
	#               https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=206169
	@${REINPLACE_CMD} 's/-l-pthread/-lpthread/' \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/libtorrent-rasterbar.pc

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
