# Created by: Doug Barton <dougb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libtorrent-rasterbar
PORTVERSION=	1.0.9
CATEGORIES?=	net-p2p ipv6
MASTER_SITES=	https://github.com/arvidn/libtorrent/releases/download/libtorrent-${PORTVERSION:S/./_/g}/

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	C++ library implementing a BitTorrent client

LICENSE=	BSD3CLAUSE

LIB_DEPENDS?=	libboost_date_time.so:devel/boost-libs \
		libGeoIP.so:net/GeoIP

USES+=		compiler:c++11-lang iconv:wchar_t libtool pathfix pkgconfig
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--disable-static \
		--enable-dht \
		--enable-encryption \
		--enable-pool-allocators \
		--enable-deprecated-functions \
		--with-boost=${LOCALBASE} \
		--with-boost-system=boost_system \
		--enable-geoip \
		--with-libgeoip \
		--with-libiconv \
		--with-openssl=${OPENSSLBASE}

SHLIB_VER=	8
PLIST_SUB+=	SHLIB_VER="${SHLIB_VER}"

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS ChangeLog

DOCSRCDIR2=	${WRKSRC}/docs
DOCSDIR2=	${DOCSDIR}/docs
DOC_FILES2=	*.*

DOCSRCDIR3=	${WRKSRC}/docs/img
DOCSDIR3=	${DOCSDIR}/docs/img
DOC_FILES3=	*

PORTEXAMPLES=	*.cpp

OPTIONS_DEFINE=	DEBUG DOCS EXAMPLES

DEBUG_CONFIGURE_ENABLE=	debug

.include <bsd.port.options.mk>

# Restrict to stable (even) versions, indicated by the second component.
# With Versions 1.x not build yet net-p2p/qbittorrent
PORTSCOUT=	limit:^0.16\..*

.if defined(SLAVE_PORT) && ${SLAVE_PORT:tl} == "yes" && defined(USE_PYTHON)
CONFIGURE_ARGS+=	--enable-python-binding \
			--with-boost-python=boost_python
.else
CONFIGURE_ARGS+=	--disable-python-binding
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/include|${PREFIX}/include|' \
		${WRKSRC}/Jamfile

post-install:
.if defined(SLAVE_PORT) && ${SLAVE_PORT:tl} == "yes" && defined(USE_PYTHON)
	${STRIP_CMD} \
	${STAGEDIR}${PYTHON_SITELIBDIR}/libtorrent.so
.else
	${STRIP_CMD} \
	${STAGEDIR}${PREFIX}/lib/libtorrent-rasterbar.so.${SHLIB_VER}
.endif

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${DOCSDIR2}
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${DOCSDIR3}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES3:S|^|${DOCSRCDIR3}/|} ${STAGEDIR}${DOCSDIR3}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/examples/|} \
		${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
