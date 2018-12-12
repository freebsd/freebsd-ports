# Created by: Doug Barton <dougb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libtorrent-rasterbar
DISTVERSION=	1.1.10
PORTREVISION=	2
CATEGORIES=	net-p2p ipv6
MASTER_SITES=	https://github.com/arvidn/libtorrent/releases/download/libtorrent-${PORTVERSION:S/./_/g}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library implementing a BitTorrent client

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_chrono.so:devel/boost-libs \
		libboost_random.so:devel/boost-libs \
		libboost_system.so:devel/boost-libs

USES=		cmake:outsource compiler:c++14-lang iconv:wchar_t libtool pathfix pkgconfig ssl
USE_LDCONFIG=	yes

SHLIB_VER=	9
PLIST_SUB+=	SHLIB_VER="${SHLIB_VER}"

DOCFILES=	AUTHORS ChangeLog
PORTDOCS=	${DOCFILES} docs/*
PORTEXAMPLES=	*.cpp

OPTIONS_DEFINE=	DEBUG DOCS EXAMPLES LOGGING
OPTIONS_DEFAULT=LOGGING
OPTIONS_SUB=	yes
LOGGING_DESC=	Enable disk stat logging and logging to disk

DEBUG_CONFIGURE_ENABLE=		debug
EXAMPLES_CONFIGURE_ENABLE=	examples
LOGGING_CONFIGURE_ENABLE=	logging disk-stats

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/include|${PREFIX}/include|' \
		${WRKSRC}/Jamfile

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/include/libtorrent/tommath.h.orig ${STAGEDIR}${PREFIX}/include/libtorrent/Makefile*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCFILES:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${STAGEDIR}${DOCSDIR}
	${RM} ${STAGEDIR}${DOCSDIR}/docs/._*

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/${PORTEXAMPLES} \
		${STAGEDIR}${EXAMPLESDIR}

do-test: # broken: https://github.com/arvidn/libtorrent/issues/3327
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -Dbuild_tests=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
