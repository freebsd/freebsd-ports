# Created by: Doug Barton <dougb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libtorrent-rasterbar
PORTVERSION=	0.16.11
CATEGORIES?=	net-p2p ipv6
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	libtorrent

MAINTAINER=	nemysis@FreeBSD.org
COMMENT?=	C++ library implementing a BitTorrent client

LICENSE=	BSD

LIB_DEPENDS+=	boost_date_time:${PORTSDIR}/devel/boost-libs \
		GeoIP:${PORTSDIR}/net/GeoIP

USES=		pathfix pkgconfig iconv
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFLICTS+=	libtorrent-rasterbar-0.1[45789].*
NO_LATEST_LINK=	yes

CONFIGURE_ARGS+=	--disable-debug \
		--disable-static \
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

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS README

DOCSRCDIR2=	${WRKSRC}/docs
DOCSDIR2=	${DOCSDIR}/docs
DOC_FILES2=	*.png *.jpg *.gif *.html *.rst *.css

PORTEXAMPLES=	*.cpp

OPTIONS_DEFINE=	DOCS EXAMPLES

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
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/examples/|} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
