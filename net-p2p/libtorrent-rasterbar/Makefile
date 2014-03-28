# Created by: Doug Barton <dougb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libtorrent-rasterbar
PORTVERSION=	0.16.16
CATEGORIES?=	net-p2p ipv6
MASTER_SITES=	SF/${PORTNAME:S/-rasterbar//}/${PORTNAME:S/-rasterbar//}/

MAINTAINER=	nemysis@FreeBSD.org
COMMENT?=	C++ library implementing a BitTorrent client

LICENSE=	BSD3CLAUSE

LIB_DEPENDS?=	libboost_date_time.so:${PORTSDIR}/devel/boost-libs \
		libGeoIP.so:${PORTSDIR}/net/GeoIP

USES=		compiler:c++11-lang pathfix pkgconfig iconv
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

SHLIB_VER=	7
PLIST_SUB+=	SHLIB_VER="${SHLIB_VER}"

SUB_FILES=	pkg-message

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS ChangeLog README

DOCSRCDIR2=	${WRKSRC}/docs
DOCSDIR2=	${DOCSDIR}/docs
DOC_FILES2=	*

PORTEXAMPLES=	*.cpp

OPTIONS_DEFINE=	DEBUG DOCS EXAMPLES STRIP
OPTIONS_DEFAULT=	STRIP

DEBUG_CONFIGURE_ENABLE=	debug

.include <bsd.port.options.mk>

.if defined(SLAVE_PORT) && ${SLAVE_PORT:L} == "yes" && defined(USE_PYTHON)
CONFIGURE_ARGS+=	--enable-python-binding \
			--with-boost-python=boost_python
.else
CONFIGURE_ARGS+=	--disable-python-binding
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/include|${PREFIX}/include|' \
		${WRKSRC}/Jamfile

post-install:
.if ${PORT_OPTIONS:MSTRIP}
	${STRIP_CMD} \
	${STAGEDIR}${PREFIX}/lib/libtorrent-rasterbar.so.${SHLIB_VER}
.else
	${STRIP_CMD} \
	${STAGEDIR}${PREFIX}/lib/${PYTHON_VERSION}/site-packages/libtorrent.so
.endif

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/examples/|} \
		${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
