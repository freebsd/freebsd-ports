# Created by: Doug Barton <dougb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libtorrent-rasterbar
PORTVERSION=	1.1.3
PORTREVISION=	1
CATEGORIES?=	net-p2p ipv6
MASTER_SITES=	https://github.com/arvidn/libtorrent/releases/download/libtorrent-${PORTVERSION:S/./_/g}/

PATCH_SITES=	https://github.com/arvidn/libtorrent/commit/
PATCHFILES=	7eb3cf6bc6db.patch:-p1

MAINTAINER=	rezny@FreeBSD.org
COMMENT?=	C++ library implementing a BitTorrent client

LICENSE=	BSD3CLAUSE

LIB_DEPENDS+=	libboost_chrono.so:devel/boost-libs \
		libboost_random.so:devel/boost-libs \
		libboost_system.so:devel/boost-libs

BROKEN_powerpc64=	fails to build: client_test.cpp: undefined reference to std::__cxx11::basic_string

USES+=		compiler:c++11-lib iconv:wchar_t libtool pathfix pkgconfig ssl
USE_CXXSTD=	c++11
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
TEST_TARGET=	check

CONFIGURE_ARGS=	--disable-static \
		--enable-dht \
		--enable-encryption \
		--enable-pool-allocators \
		--enable-deprecated-functions \
		--with-boost=${LOCALBASE} \
		--with-libiconv \
		--with-openssl=${OPENSSLBASE}

SHLIB_VER=	9
PLIST_SUB+=	SHLIB_VER="${SHLIB_VER}"

DOCFILES=	AUTHORS ChangeLog
PORTDOCS=	${DOCFILES} docs/*
PORTEXAMPLES=	*.cpp

OPTIONS_DEFINE=	DEBUG DOCS EXAMPLES LOGGING TEST
OPTIONS_SUB=	yes
LOGGING_DESC=	Enable disk stat logging and logging to disk

DEBUG_CONFIGURE_ENABLE=		debug
EXAMPLES_CONFIGURE_ENABLE=	examples
LOGGING_CONFIGURE_ENABLE=	logging disk-stats
TEST_CONFIGURE_ENABLE=		tests

.include <bsd.port.options.mk>

.if defined(SLAVE_PORT) && ${SLAVE_PORT:tl} == "yes" && defined(USE_PYTHON)
CONFIGURE_ARGS+=	--enable-python-binding
.else
CONFIGURE_ARGS+=	--disable-python-binding
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/include|${PREFIX}/include|' \
		${WRKSRC}/Jamfile

post-configure:
	${FIND} ${WRKSRC} -name Makefile -o -name link_flags | \
		${XARGS} ${REINPLACE_CMD} 's| *-R${LOCALBASE}/lib||'

post-install:
.if defined(SLAVE_PORT) && ${SLAVE_PORT:tl} == "yes" && defined(USE_PYTHON)
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/libtorrent.so
.else
	${STRIP_CMD} \
	${STAGEDIR}${PREFIX}/lib/libtorrent-rasterbar.so.${SHLIB_VER}
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${DOCFILES:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${STAGEDIR}${DOCSDIR})
	${RM} ${STAGEDIR}${DOCSDIR}/docs/._*

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/${PORTEXAMPLES} \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
