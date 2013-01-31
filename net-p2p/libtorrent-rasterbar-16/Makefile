# $FreeBSD$

PORTNAME=	libtorrent-rasterbar
PORTVERSION=	0.16.7
PORTREVISION?=	1
CATEGORIES?=	net-p2p ipv6
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	libtorrent

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	C++ library implementing a BitTorrent client

MAKE_JOBS_SAFE=	yes

CONFLICTS+=	libtorrent-rasterbar-0.1[45789].*

NO_LATEST_LINK=	yes

LIB_DEPENDS+=	boost_date_time:${PORTSDIR}/devel/boost-libs \
		GeoIP:${PORTSDIR}/net/GeoIP

USE_PKGCONFIG=	build
USE_GNOME=	gnomehack
USE_OPENSSL=	yes
USE_ICONV=	yes

GNU_CONFIGURE=	yes
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
		--with-openssl=${OPENSSLBASE}

USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if defined(SLAVE_PORT) && ${SLAVE_PORT:L}=="yes" && defined(USE_PYTHON)
CONFIGURE_ARGS+=	--enable-python-binding \
			--with-boost-python=boost_python
.else
CONFIGURE_ARGS+=	--disable-python-binding
.endif

.if defined(SLAVE_PORT) && ${SLAVE_PORT:L}=="yes"
post-patch: slave-post-patch
.else
post-patch:
	@${REINPLACE_CMD} -e 's|<include>/usr/local/include|<include>${PREFIX}/include|' \
		${WRKSRC}/Jamfile
.endif

.if defined(SLAVE_PORT) && ${SLAVE_PORT:L}=="yes"
post-install: slave-post-install
.else
post-install:
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.css ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.gif ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.jpg ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.png ${DOCSDIR}
PORTDOCS=	*
.endif

.include <bsd.port.post.mk>
